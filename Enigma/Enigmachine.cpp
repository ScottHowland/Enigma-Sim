/* Implementations for the Enigmachine class methods
		-Handling Enigmachine construction
		-Managing rotor offset incrementations
		-Executing string-int conversions, and vice versa
		-Handling the ciphering process */

#include "Enigmachine.h"
#include "IntCharConversions.h"

/* Constructs the rotors to be used for ciphering, then organizes them into a list for later iteration */
Enigmachine::Enigmachine(string right_rotor_type, string mid_rotor_type, string left_rotor_type, string reflector_type,
						 int right_offset, int mid_offset, int left_offset, int rotor_map_size) {
	rotor_map_size_ = rotor_map_size;

	right_rotor_ = new Rotor(right_rotor_type, right_offset, rotor_map_size_);
	mid_rotor_ = new Rotor(mid_rotor_type, mid_offset, rotor_map_size_);
	left_rotor_ = new Rotor(left_rotor_type, left_offset, rotor_map_size_);

	/* Input rotors need not be constructed, as they have only one map configuration: X maps to X */
	rotor_sequence_.push_back(new Rotor("Input", 0, rotor_map_size_));
	rotor_sequence_.push_back(right_rotor_);
	rotor_sequence_.push_back(mid_rotor_);
	rotor_sequence_.push_back(left_rotor_);
	rotor_sequence_.push_back(new Rotor(reflector_type, 0, rotor_map_size_));
}

/* Steps the rightmost rotor, then determines if any subsequent rotations need to be made
		-Called right before each input character undergoes ciphering
		-Needed to change the rotor offsets and modify the rotor maps for stronger encryption */
void Enigmachine::StepRotors() {
	right_rotor_->StepPosition();

	string right_model = right_rotor_->RotorModel();
	int right_position = right_rotor_->Offset();

	/* Each rotor model has a specific 'tipping point' which will rotate the next rotor in sequence if passed 
			-EX...
				A rotor of model 'I' will rotrate the next rotor if it progresses from 16 ('Q') to 17 ('R')*/
	if (right_model == "I" && right_position == 17) {
		mid_rotor_->StepPosition();
		string mid_model = mid_rotor_->RotorModel();
		int mid_position = mid_rotor_->Offset();

		if (mid_model == "II" && mid_position == 5)
			left_rotor_->StepPosition();

		else if (mid_model == "III" && mid_position == 22)
			left_rotor_->StepPosition();
	}

	else if (right_model == "II" && right_position == 5) {
		mid_rotor_->StepPosition();
		string mid_model = mid_rotor_->RotorModel();
		int mid_position = mid_rotor_->Offset();

		if (mid_model == "I" && mid_position == 17)
			left_rotor_->StepPosition();

		else if (mid_model == "III" && mid_position == 22)
			left_rotor_->StepPosition();
	}

	else if (right_model == "III" && right_position == 22) {
		mid_rotor_->StepPosition();
		string mid_model = mid_rotor_->RotorModel();
		int mid_position = mid_rotor_->Offset();

		if (mid_model == "I" && mid_position == 17)
			left_rotor_->StepPosition();

		else if (mid_model == "II" && mid_position == 5)
			left_rotor_->StepPosition();
	}
}

/* Converts a string into a sequence of integer values, ciphers each, and then pushes them to a queue for later int-char conversion*/
void Enigmachine::StringToIntQ(string input_target) {
	int temp_plain;
	int temp_cipher;
	/* Convert an alpha character in the string to an int, step the machine's rotors, then cipher it before pushing to the queue */
	for (int k = 0; k < input_target.size(); ++k) {
		if (isalpha(input_target[k])) {
			temp_plain = CharToInt(input_target[k]);
			StepRotors();
			temp_cipher = Cipher(temp_plain);
			int_queue_.push(temp_cipher);
		}
		/* If not alpha, then push the character to the queue as-is*/
		else {
			temp_plain = CharToInt(input_target[k]);
			int_queue_.push(temp_plain);
		}
	}
}

/* Converts the elements of an integer queue into a string */
string Enigmachine::IntQToString(queue<int> output_target) {
	string ciphered_string;
	char temp_char;

	while (!output_target.empty()) {
		temp_char = IntToChar(output_target.front());
		ciphered_string.push_back(temp_char);
		output_target.pop();
	}
	return ciphered_string;
}

/* Manages the ciphering process from the input rotor up until the process reaches the reflector */
int Enigmachine::CipherToReflector(list<Rotor*>::iterator entry_point, int temp_cipher) {
	int current_offset;
	int next_offset;

	entry_point = rotor_sequence_.begin();

	while (true) {
		current_offset = (*entry_point)->Offset();

		if (next(entry_point, 1) != rotor_sequence_.end())
			next_offset = (*next(entry_point, 1))->Offset();
		/* If the next element in the list is one past the end, then the iterator must be pointing to the reflector, which always has an offset of 0 */
		else
			next_offset = 0;

		/* The temporary cipher value is equal to whatever the old temp value maps to in the current rotor's node map 
		   adjusted by the offsets of the current and following rotor to simulate the effects of position offsets in a physical Enigma */
		temp_cipher = (*entry_point)->Nodemap()[temp_cipher] + next_offset - current_offset;

		/* These operations will guarantee that the temporary cipher value is within the range of the rotor maps,
		   so as to prevent out-of-range indices being searched for in the next rotor map */
		if (temp_cipher >= 0)
			temp_cipher = temp_cipher % rotor_map_size_;
		else
			temp_cipher = temp_cipher + rotor_map_size_;

		if (next(entry_point, 1) != rotor_sequence_.end())
			++entry_point;
		else
			break;
	}

	return temp_cipher;
}

/* Manages the ciphering process when the process has reached the reflector, before the cipher value is fed back through the sequence in reverse */
int Enigmachine::CipherAtReflector(list<Rotor*>::iterator entry_point, int temp_cipher) {
	int next_offset;

	entry_point = prev(rotor_sequence_.end(), 1);
	next_offset = (*prev(entry_point, 1))->Offset();
	/* There is no risk of the temp cipher value being negative, and the current offset is always 0 at the reflector */
	temp_cipher = temp_cipher + next_offset;
	temp_cipher = temp_cipher % rotor_map_size_;

	return temp_cipher;
}

/* Manages the ciphering process as the temporary cipher value is fed through the rotors in reverse order */
int Enigmachine::CipherFromReflector(list<Rotor*>::iterator entry_point, int temp_cipher) {
	int current_offset;
	int next_offset;

	entry_point = prev(rotor_sequence_.end(), 1);

	while (true) {
		if (entry_point != rotor_sequence_.begin())
			--entry_point;

		current_offset = (*entry_point)->Offset();

		/* Similar to the reflector, the input rotor will always have an offset of 0 */
		if (entry_point != rotor_sequence_.begin())
			next_offset = (*prev(entry_point, 1))->Offset();
		else
			next_offset = 0;

		/* Instead of seeing what value an index maps to, the index that maps to the cipher value, modified by offsets, is what is searched for */
		for (int k = 0; k < (*entry_point)->Mapsize(); ++k) {
			int mappedvalue = (*entry_point)->Nodemap()[k];
			if (temp_cipher == mappedvalue) {
				temp_cipher = k + next_offset - current_offset;

				if (temp_cipher >= 0)
					temp_cipher = temp_cipher % rotor_map_size_;
				else
					temp_cipher = temp_cipher + rotor_map_size_;
				break;
			}
		}
		if (entry_point == rotor_sequence_.begin())
			break;
	}
		return temp_cipher;
}

/* Bundles the "CipherXReflector" functions to execute the ciphering process while keeping the individual stages distinct and modular */
int Enigmachine::Cipher(int to_cipher) {
	int temp_cipher = to_cipher;
	list<Rotor*>::iterator entry_point;
	
	temp_cipher = CipherToReflector(entry_point, temp_cipher);
	temp_cipher = CipherAtReflector(entry_point, temp_cipher);
	temp_cipher = CipherFromReflector(entry_point, temp_cipher);

	return temp_cipher;
}