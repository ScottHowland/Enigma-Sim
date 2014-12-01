/* Execute is responsible for...
		-Defining the constant rotor map size of 26
		-Printing the application title to the console
		-Progressing through a series of menus and prompts, acquiring user input
		-Constructing an Enigmachine from the values collected 
		-Converting a user-supplied string into a capitalized string for ciphering
		-Directing the Enigmachine to cipher the capitalized string
		-Updating the string to match the ciphered values
		-Displaying the ciphered message on the console for the user 
		-Determining whether to cipher another message or exit the application */

#ifndef ENIGMA_ENIGMA_EXECUTE_H_
#define ENIGMA_ENIGMA_EXECUTE_H_

#include "Utilities.h"

/* Progresses through the application's functionality and sets rotor map size
   See top-of-file comment for full description */
void Execute() {
	const int MAPSIZE = 26;
	bool bloop = true;
	string message;
	Title();
	Enigmachine mEnigmachine = Menu(MAPSIZE);
	while (bloop) {
		message = InitializeInput();
		message = CipherString(mEnigmachine, message);
		cout << "Ciphered message\n" << message << "\n\nCipher another message?\n\n";
		DashLine();
		bloop = CipherAnother();
	}
}
#endif