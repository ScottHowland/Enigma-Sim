/* Constructs the rotor's node map based on the identifier assigned to it 
		-NOTE: If an invalid model identifier is passed, the function will crash. It is not possible for an Enigmachine to function
			   should a standard rotor be used in place of the input rotor or the reflector */

#include "Rotor.h"
#include "Rotormaps.h"

/* See top-of-file comment for description */
void Rotor::BuildNodemapOrDie(const string rotor_model) {
	if (rotor_model == "Input") {
		for (int k = 0; k < map_size_; ++k)
			node_map_[k] = k;
	}

	if (rotor_model == "I") {
		for (int k = 0; k < map_size_; ++k)
			node_map_[k] = IMap(k);
	}

	if (rotor_model == "II") {
		for (int k = 0; k < map_size_; ++k)
			node_map_[k] = IIMap(k);
	}

	if (rotor_model_ == "III") {
		for (int k = 0; k < map_size_; ++k)
			node_map_[k] = IIIMap(k);
	}

	if (rotor_model == "Wide_B") {
		for (int k = 0; k < map_size_; ++k)
			node_map_[k] = WideBMap(k);
	}
}