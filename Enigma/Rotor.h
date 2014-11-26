/* Rotors are responsible for...
		-Constructing an array to facilitate the ciphering process based on a supplied model type 
		-Knowing the size of its mapping scheme, expandable to acommodate more cipherable characters at a later date 
		-Keep track of, and increment, its current position setting, as an offset from the 0/'A' position, to give the ciphering process
		 more complexity and security */

#ifndef ENIGMA_ENIGMA_ROTOR_H_
#define ENIGMA_ENIGMA_ROTOR_H_

#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using std::array;
using std::cout;
using std::endl;
using std::ifstream;
using std::iterator;
using std::string;

/* Consists of an array to facilitate ciphering, a model type to determine the specific mappings, the map size, and the current position setting 
   See top-of-file comment for full description */
class Rotor {
private:
	/* The identifier used to determine what mapping scheme the rotor will use for ciphering */
	const string rotor_model_;
	/* Determines the size of the node map of the rotor
			-NOTE: Should be equal to 26 unless maps are extended to include capitals/lowercase, numeric characters, punctuation, etc */
	const int map_size_;
	/* Array used to establish the rotor's mapping scheme
			-The indices and contained values are represented by integers 0-25, where 0 = A and 25 = Z
			-Indices and their contained values serve as the ciphering mechanism 
			-EX...
				If a rotor maps the letter 'A' to the letter 'X', then the 0th index will contain the value 23
			-Implemented as a circular array to correct for out-of-range values due to the impact of varying rotor offsets */
	int* node_map_;
	/* Represents the rotor's current setting as an offset from 0 or 'A'
			-Should only ever be incremented
			-Mod is used to ensure that the offset is always within the rotor's 26 possible settings */
	int offset_;

public:
	/* Intializes and builds the rotor's substitution array as well as determining the rotor's initial offset */
	Rotor(string rotor_model, int offset, int map_size) : rotor_model_(rotor_model), map_size_(map_size), offset_(offset), node_map_(new int[map_size]) {
		BuildNodemapOrDie(rotor_model_);
		SetOffset(offset);
	}

	/* Sets the rotor's initial position setting relative to 'A', or 0 */
	void SetOffset(const int setting) {
		offset_ = setting;
	}

	/* Gives access to the rotor's current position setting */
	int Offset() {
		return offset_;
	}

	/* Provides access to the rotor's model type */
	string RotorModel() {
		return rotor_model_;
	}

	/* Increments the rotor's positional offset
			-Mod is used to ensure the setting is always within the range of the rotor's mapping scheme */
	void StepPosition() {
		offset_ = (++offset_) % map_size_;
	}

	/* Allows access to the rotor's substitution array */
	int* Nodemap() {
		return node_map_;
	}

	/* Returns the size of the rotor's substitution array */
	int Mapsize() {
		return map_size_;
	}

	/* Constructs the rotor's substitution array based on the rotor's model */
	void BuildNodemapOrDie(string rotor_model);
};
#endif

