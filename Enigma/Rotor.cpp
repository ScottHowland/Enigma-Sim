#include "Rotor.h"
#include "Rotormaps.h"

void Rotor::set_offset(int setting) {
	if (setting < 0 || setting > mapsize)
		throw std::invalid_argument("Invalid rotor setting.\n");
	else
		positionoffset = setting;
}

void Rotor::step() {
	positionoffset = (++positionoffset) % mapsize;
}

string Rotor::get_model() {
	return rotormodel;
}

int Rotor::get_offset() {
	return positionoffset;
}

int* Rotor::get_nodemap() {
	return nodemap;
}

int Rotor::get_mapsize() {
	return mapsize;
}

void Rotor::build_nodemap(string rotormodel) {
	if (rotormodel == "Input") {
		for (int k = 0; k < mapsize; ++k)
			nodemap[k] = k;
	}

	if (rotormodel == "I") {
		for (int k = 0; k < mapsize; ++k)
			nodemap[k] = I_map(k);
	}

	if (rotormodel == "II") {
		for (int k = 0; k < mapsize; ++k)
			nodemap[k] = II_map(k);
	}

	if (rotormodel == "III") {
		for (int k = 0; k < mapsize; ++k)
			nodemap[k] = III_map(k);
	}

	if (rotormodel == "Wide_B") {
		for (int k = 0; k < mapsize; ++k)
			nodemap[k] = WideB_map(k);
	}
}