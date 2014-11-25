#ifndef _UTILITIES_H
#define _UTILITIES_H
#include <iostream>
#include <string>
#include <locale>
#include <queue>
#include <sstream>

using std::string;
using std::queue;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::toupper;
using std::isalpha;
using std::isspace;
using std::stringstream;

/* Centers string in the console window */
void center_string(string text) {
	int num_spaces = (80 - text.size()) / 2;
	for (int k = 0; k < num_spaces; ++k)
		cout << " ";
	cout << text << endl;
}

/* Prints one console line's worth of dashes */
void dash_line(){
	for (int k = 0; k < 80; ++k)
		cout << "-";
	cout << endl;
}

/* Capitalizes all elements of a given string */
string capitalize_string(string text) {
	string captext;
	for (int k = 0; k < text.size(); ++k)
		captext.push_back(toupper(text[k]));
	return captext;
}

/* Prompts user to input a string comprised of non-numeric characters and capitalizes it */
string input_string() {
	string plaintext;
	string captext;
	bool b_validmessage = true;

	do {
		if (!b_validmessage) {
			cout << "I'm sorry, but that message contained a non-alphabetic, non-space character.\n\n";
			plaintext = "";
		}

		cout << "Please enter the message to be ciphered.\n"
			<< "\t-Not case-sensitive.\n"
			<< "\t-Letters and spaces only, please.\n\n";

		getline(std::cin, plaintext);

		for (int k = 0; k < plaintext.size(); ++k) {
			bool b_isalpha = isalpha(plaintext[k]);
			bool b_isspace = isspace(plaintext[k]);
			if (!b_isalpha && !b_isspace)
				b_validmessage = false;
			else
				b_validmessage = true;
		}
	} while (!b_validmessage);

	captext = capitalize_string(plaintext);

	dash_line();

	return captext;
}

/* Preps user input for encryption/decryption */
string initialize_input(queue<char> &messagequeue) {
	string preppedstring;
	preppedstring = input_string();
	return preppedstring;
}


/* Ciphers a string and returns its ciphertext */
string cipher_string(Enigmachine enigmachine, string plaintext) {
	string ciphertext;
	enigmachine.convert_charint(plaintext);
	queue<int> outputqueue = enigmachine.get_queue();
	ciphertext = enigmachine.convert_intchar(outputqueue);
	return ciphertext;
}

/* Determines one of the enigma's rotor models */
string set_rotor_model(int slottarget) {
	string returnstring;
	int returnmodel;
	if (slottarget != 3) {
		cout << "Select which rotor you would like to place in ";

		if (slottarget == 0)
			cout << "the right slot (1-3)\n";
		else if (slottarget == 1)
			cout << "the middle slot (1-3)\n";
		else
			cout << "the left slot (1-3)\n";

		cout << "Available models\n";
		cout << "1. Model I\n";
		cout << "2. Model II\n";
		cout << "3. Model III\n\n";

		while (true) {
			getline(cin, returnstring);
			stringstream modelstream(returnstring);
			if (modelstream >> returnmodel && returnmodel) {
				if (returnmodel >= 1 && returnmodel <= 3)
					break;
			}
			cout << "Invalid rotor selection. Please select a choice 1-3\n";
		}

		dash_line();

		if (returnmodel == 1)
			return "I";
		else if (returnmodel == 2)
			return "II";
		else
			return  "III";
	}
	else
		return "Wide_B";
}

int set_rotor_offset(int slottarget) {
	string returnstring;
	int returnoffset;
		cout <<"Please enter the initial rotor offset for the ";

		if (slottarget == 0)
			cout << "right rotor (0-25)\n\n";
		else if (slottarget == 1)
			cout << "mid rotor (0-25)\n\n";
		else
			cout << "left rotor (0-25)\n\n";

		while (true) {
			getline(cin, returnstring);
			stringstream modelstream(returnstring);
			if (modelstream >> returnoffset) {
				if (returnoffset >= 0 && returnoffset <= 25)
					break;
			}
			cout << "Invalid rotor selection. Please select a choice 0-25\n";
		}

		dash_line();
		return returnoffset;
}

/* Displays the application's title */
void title() {
	dash_line();
	center_string("Enigma Simulator\n");
	center_string("Developed by Scott Howland\n");
	dash_line();
}

/* Displays the application's construction menu */
Enigmachine menu(int mapsize) {
	string rightmodel, midmodel, leftmodel, reflectormodel;
	int rightoffset, midoffset, leftoffset;

	for (int k = 0; k < 4; ++k) {
		if (k == 0)
			rightmodel = set_rotor_model(k);
		else if (k == 1)
			midmodel = set_rotor_model(k);
		else if (k == 2)
			leftmodel = set_rotor_model(k);
		else
			reflectormodel = set_rotor_model(k);
	}

	for (int k = 0; k < 3; ++k) {
		if (k == 0)
			rightoffset = set_rotor_offset(k);
		else if (k == 1)
			midoffset = set_rotor_offset(k);
		else
			leftoffset = set_rotor_offset(k);
	}

	return Enigmachine(rightmodel, midmodel, leftmodel, reflectormodel, rightoffset, midoffset, leftoffset, mapsize);
}
#endif