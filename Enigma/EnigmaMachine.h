#ifndef _ENIGMAMACHINE_H
#define _ENIGMAMACHINE_H
#include <queue>
#include <list>
#include <iterator>
#include "Rotor.h"

using std::iterator;
using std::string;
using std::queue;
using std::list;
using std::next;

class Enigmachine {
private:
	Rotor *inputrotor;
	Rotor *rightrotor;
	Rotor *midrotor;
	Rotor *leftrotor;
	Rotor *reflector;
	list<Rotor*> rotorsequence;
	queue<int> intqueue;
	int rotormapsize;

public:
	/* Creates the right, middle, and left rotors as well as the reflector */
	Enigmachine(string rightrotortype, string midrotortype, string leftrotortype, string reflectortype, int rightoffest, int midoffset, int leftoffset, int rotormapsize);

	/* Establishes the sequence of rotors for IO */
	void build_cipher_sequence();

	/* Increments the rotor position offsets for every entered character */
	void step_rotors();

	/* Converts a string of characters into a queue of ciphered ints */
	void convert_charint(string inputtarget);

	/* Converts a queue of integers into a string of characters for output */
	string convert_intchar(queue<int> outputtarget);

	/* Returns whether or not the intqueue is empty */
	bool queue_empty();

	/* Returns the value at the front of the queue */
	int queue_front();

	/* Accesses the intqueue */
	queue<int> get_queue();

	/* Ciphers an integer */
	int cipher(int ciphertarget);

};
#endif 