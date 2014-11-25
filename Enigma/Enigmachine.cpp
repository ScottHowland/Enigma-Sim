#include "EnigmaMachine.h"
#include "IntCharConversions.h"

Enigmachine::Enigmachine(string rightrotortype, string midrotortype, string leftrotortype, string reflectortype, int rightoffset, int midoffset, int leftoffset, int rotormapsize) {
	this->rotormapsize = rotormapsize;
	rightrotor = new Rotor(rightrotortype, rightoffset, rotormapsize);
	midrotor = new Rotor(midrotortype, midoffset, rotormapsize);
	leftrotor = new Rotor(leftrotortype, leftoffset, rotormapsize);
	rotorsequence.push_back(new Rotor("Input", 0, rotormapsize));
	rotorsequence.push_back(rightrotor);
	rotorsequence.push_back(midrotor);
	rotorsequence.push_back(leftrotor);
	rotorsequence.push_back(new Rotor(reflectortype, 0, rotormapsize));
}

void Enigmachine::step_rotors() {
	rightrotor->step();
	string rightmodel = rightrotor->get_model();
	int rightposition = rightrotor->get_offset();

	if (rightmodel == "I" && rightposition == 17) {
		midrotor->step();
		string midmodel = midrotor->get_model();
		int midposition = midrotor->get_offset();

		if (midmodel == "II" && midposition == 5)
			leftrotor->step();

		else if (midmodel == "III" && midposition == 22)
			leftrotor->step();
	}

	else if (rightmodel == "II" && rightposition == 5) {
		midrotor->step();
		string midmodel = midrotor->get_model();
		int midposition = midrotor->get_offset();

		if (midmodel == "I" && midposition == 17)
			leftrotor->step();

		else if (midmodel == "III" && midposition == 22)
			leftrotor->step();
	}

	else if (rightmodel == "III" && rightposition == 22) {
		midrotor->step();
		string midmodel = midrotor->get_model();
		int midposition = midrotor->get_offset();

		if (midmodel == "I" && midposition == 17)
			leftrotor->step();

		else if (midmodel == "II" && midposition == 5)
			leftrotor->step();
	}
}

void Enigmachine::convert_charint(string inputtarget) {
	int inpttemp;
	int ciphertemp;
	for (int k = 0; k < inputtarget.size(); ++k) {
		if (isalpha(inputtarget[k])) {
			inpttemp = chartoint(inputtarget[k]);
			step_rotors();
			ciphertemp = cipher(inpttemp);
			intqueue.push(ciphertemp);
		}
		else {
			inpttemp = chartoint(inputtarget[k]);
			intqueue.push(inpttemp);
		}
	}
}

string Enigmachine::convert_intchar(queue<int> outputtarget) {
	string cipheredstring;
	char temp;
	while (!outputtarget.empty()) {
		temp = inttochar(outputtarget.front());
		cipheredstring.push_back(temp);
		outputtarget.pop();
	}
	return cipheredstring;
}

bool Enigmachine::queue_empty() {
	return (intqueue.empty());
}

int Enigmachine::queue_front() {
	return intqueue.front();
}

queue<int> Enigmachine::get_queue() {
	return intqueue;
}

int Enigmachine::cipher(int ciphertarget) {
	int tempcipher = ciphertarget;
	int targetindex;
	int nextoffset;
	int prevoffset;
	int currentoffset;
	list<Rotor*>::iterator entrypoint = rotorsequence.begin();
	
	while (true) {
		currentoffset = (*entrypoint)->get_offset();

		if (next(entrypoint,1) != rotorsequence.end())
			nextoffset = (*next(entrypoint, 1))->get_offset();
		else
			nextoffset = 0;

		tempcipher = (*entrypoint)->get_nodemap()[tempcipher] + nextoffset - currentoffset;

		if (tempcipher >= 0)
			tempcipher = tempcipher % rotormapsize;
		else
			tempcipher = tempcipher + rotormapsize;

		if (next(entrypoint,1) != rotorsequence.end())
			++entrypoint;
		else
			break;
	}

	nextoffset = (*prev(entrypoint, 1))->get_offset();
	tempcipher = tempcipher + nextoffset;
	tempcipher = tempcipher % rotormapsize;

	while (true) {
			if (entrypoint != rotorsequence.begin())
				--entrypoint;
	
		currentoffset = (*entrypoint)->get_offset();

		if (entrypoint != rotorsequence.begin())
			nextoffset = (*prev(entrypoint,1))->get_offset();
		else
			nextoffset = 0;

			for (int k = 0; k < (*entrypoint)->get_mapsize(); ++k) {
				int mappedvalue = (*entrypoint)->get_nodemap()[k];
				if (tempcipher == mappedvalue) {
					tempcipher = k + nextoffset - currentoffset;
					if (tempcipher >= 0)
						tempcipher = tempcipher % rotormapsize;
					else
						tempcipher = tempcipher + rotormapsize;
					break;
			}
		}
			if (entrypoint == rotorsequence.begin())
			break;
	}
	return tempcipher;
}