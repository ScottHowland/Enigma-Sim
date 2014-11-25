#ifndef _IOFLOW_H
#define _IOFLOW_H
#include "Utilities.h"

/* Progresses through the application's functionality */
void execute() {
	queue<char> messagequeue;
	const int MAPSIZE = 26;
	string message;
	title();
	Enigmachine mEnigmachine = menu(MAPSIZE);
	message = initialize_input(messagequeue);
	message = cipher_string(mEnigmachine, message);
	cout << "Ciphered message\n" << message << endl << endl;
}

#endif