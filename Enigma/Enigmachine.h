/* An Enigmachine is responsible for...
		-Defining and keeping track of the size of rotor maps
		-The creation of a list of rotor pointers and management of the offsets of those rotors 
		-Conversion of characters in a string into integers to be stored in a queue
		-Ciphering of integer values, one-by-one, by iterating through the node maps of each rotor
		-Conversion of ciphered integer values into a string to be used for output to the user */

#ifndef ENIGMA_ENIGMA_ENIGMACHINE_H_
#define ENIGMA_ENIGMA_ENIGMACHINE_H_

#include "Rotor.h"

#include <iterator>
#include <list>
#include <queue>

using std::iterator;
using std::list;
using std::next;
using std::queue;
using std::string;

/* Manages rotor creation and organization, as well as message ciphering and char-int conversions
   See top-of-file comment for full description */
class Enigmachine {
private:
	/* Pointers to the rotors that will comprise the Enigmachine's rotor sequence
			-Input rotors should never be user-defined
			-Reflector rotors, at this time, are not user-defined */
	Rotor *input_rotor_;
	Rotor *right_rotor_;
	Rotor *mid_rotor_;
	Rotor *left_rotor_;
	Rotor *reflector_;
	/* The list of rotor pointers that will be used to guide a plaintext value through the ciphering process */
	list<Rotor*> rotor_sequence_;
	/* Stores white space characters as well as ciphered integer values of alpha-type characters from an input string */
	queue<int> int_queue_;
	/* Used to set the size of all rotor node maps
		-Should always be set to 26 at this time*/
	int rotor_map_size_;

public:
	/* Responsible for creating the machine's rotors, defining their map size, as well as building each of their individual node maps 
			-Arguments are used to initialize the machine's rotors and determine the size of their map, which should always be 26
			-Builds the sequence of rotors from right to left
			-Since the input and reflector rotors are never currently altered or user-defined, their values are hard-coded in */
	Enigmachine(string right_rotor_type, string mid_rotor_type, string left_rotor_type, string reflector_type,
				int right_offest, int mid_offset, int left_offset, const int rotor_map_size);

	/* Responsible for incrementing the right, mid, and left rotors as a string is ciphered 
			-Right rotor is incremented before every character ciphering
			-If a preceding rotor increments from a specific 'stepping value' to another, it increments the following rotor 
			-The reflector cannot be incremented */
	void StepRotors();

	/* Converts a string of characters into a queue of ciphered ints 
			-If a character is an alpha character, ciphers it and pushes it to the queue
			-If not, pushes it into the int queue as-is */
	void StringToIntQ(string input_target);

	/* Converts a queue of integers into a string of characters for output 
			-No special cases. Function only converts the queue elements to characters and adds them to output string */
	string IntQToString(queue<int> output_target);

	/* Returns whether or not the intqueue is empty */
	bool Empty() {
		return int_queue_.empty();
	}

	/* Returns the value at the front of the queue */
	int Front() {
		return int_queue_.front();
	}

	/* Accesses the intqueue */
	queue<int> IntQueue() {
		return int_queue_;
	}

	/* Ciphers an integer 
			-Uses the "CipherXReflector" methods to handle cipher at various segments of progression through the rotor sequence */
	int Cipher(int cipher_target);

	/* Handles ciphering from start of rotor sequence until the reflector is reached 
			-Determine new cipher value based on the old cipher value, adjusted to account for rotor offsets */
	int CipherToReflector(list<Rotor*>::iterator entry_point, int temp_cipher);

	/* Handles ciphering at the reflector 
			-Similar to CipherToReflector, but handles the specific ciphering case for the reflector*/
	int CipherAtReflector(list<Rotor*>::iterator entry_point, int temp_cipher);

	/* Handles ciphering from the reflector back to the front of the rotor sequence 
			-Determine new cipher based on the old cipher value, then adjust for rotor offsets*/
	int CipherFromReflector(list<Rotor*>::iterator entry_point, int temp_cipher);

};
#endif 