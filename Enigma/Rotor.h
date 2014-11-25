#ifndef _ROTOR_H
#define _ROTOR_H
#include <iostream>
#include <array>
#include <iterator>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::array;
using std::iterator;
using std::string;
using std::ifstream;

class Rotor {
private:
	const string rotormodel;
	const int mapsize;
	int* nodemap;
	int positionoffset;

public:
	/* Intializes and builds the rotor's substitution array as well as the rotor's position in the encrypting process */
	Rotor(string rotormodel, int offset, int mapsize) : rotormodel(rotormodel), mapsize(mapsize), positionoffset(offset), nodemap(new int[mapsize]) {
		build_nodemap(rotormodel);
		set_offset(positionoffset);
	}

	/* Sets the rotor's position setting relative to 'A', or 0 */
	void set_offset(int setting);

	/* Gives acces to the rotor's current position setting */
	int get_offset();

	/* Provides access to the rotor's model type */
	string get_model();

	/* Increments the rotor's positional offset */
	void step();

	/* Allows access to the rotor's substitution array */
	int* get_nodemap();

	/* Returns the size of the rotor's substitution array */
	int get_mapsize();

	/* Constructs the rotor's substitution array based on the rotor's model */
	void build_nodemap(string rotormodel);
};
#endif

