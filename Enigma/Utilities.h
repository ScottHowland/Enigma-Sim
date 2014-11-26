/* The various operations that are not involved in the actual ciphering process
		-UI handling
		-Acquiring user-defined data for constructing the rotors and Enigmachine
		-Preparing input for ciphering
		-Calling and organizing the functions that make up the ciphering process */

#ifndef ENIGMA_ENIGMA_UTILITIES_H
#define ENIGMA_ENIGMA_UTILITIES_H

#include "Enigmachine.h"

#include <iostream>
#include <locale>
#include <queue>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isalpha;
using std::isspace;
using std::queue;
using std::string;
using std::stringstream;
using std::toupper;

/* Centers string in the console window */
void CenterString(string text) {
	/* Determines how many spaces are needed to center the string, given its size */
	int num_spaces = (80 - text.size()) / 2;
	for (int k = 0; k < num_spaces; ++k)
		cout << " ";
	cout << text << endl;
}


/* Prints one console line's worth of dashes */
void DashLine(){
	for (int k = 0; k < 80; ++k)
		cout << "-";
	cout << endl;
}

/* Displays the application's title */
void Title() {
	DashLine();
	CenterString("Enigma Simulator\n");
	CenterString("Created by Scott Howland, Whitworth University\n");
	CenterString("Designed and Developed from 11/17/14 to 11/25/14\n");
	DashLine();
}

/* Capitalizes all elements of a given string */
string CapitalizeString(string text) {
	string capital_text;
	for (int k = 0; k < text.size(); ++k)
		capital_text.push_back(toupper(text[k]));
	return capital_text;
}

/* Prompts user to input a string comprised of non-numeric characters and capitalizes it */
string InputString() {
	string plain_text;
	string capital_text;
	bool bvalid_message = true;

	do {
		if (!bvalid_message) {
			cout << "\nI'm sorry, but that message contained a non-alphabetic, non-space character.\n\n";
			plain_text = "";
		}

		cout << "Please enter the message to be ciphered.\n"
			<< "\t-Not case-sensitive.\n"
			<< "\t-Letters and spaces only, please.\n\n";

		getline(std::cin, plain_text);
		/* Will reject a message with a non-alpha, non-space character (',', '5', '@') */
		for (int k = 0; k < plain_text.size(); ++k) {
			bool b_isalpha = isalpha(plain_text[k]);
			bool b_isspace = isspace(plain_text[k]);
			if (!b_isalpha && !b_isspace)
				bvalid_message = false;
			else
				bvalid_message = true;
		}
	} while (!bvalid_message);

	capital_text = CapitalizeString(plain_text);

	DashLine();  /* To ensure UI clarity */

	return capital_text;
}

/* Preps user input for encryption/decryption */
string InitializeInput() {
	string prepped_string;
	prepped_string = InputString();
	return prepped_string;
}


/* Ciphers a string and returns its ciphertext */
string CipherString(Enigmachine enigmachine, string plain_text) {
	string cipher_text;
	/* Responsible for the char-int conversion and ciphering */
	enigmachine.StringToIntQ(plain_text);
	queue<int> output_queue = enigmachine.IntQueue();
	cipher_text = enigmachine.IntQToString(output_queue);
	return cipher_text;
}

/* Prompts user to provide input, collects it, and then uses that data to determine what rotor type should be returned */
string SetRotorModel(int slot_target) {
	string return_string;
	int return_model;

	/* The user cannot currently determine the reflector type */
	if (slot_target != 3) {
		cout << "Select which rotor you would like to place in ";

		if (slot_target == 0)
			cout << "the right slot (1-3)\n";
		else if (slot_target == 1)
			cout << "the middle slot (1-3)\n";
		else
			cout << "the left slot (1-3)\n";

		cout << "Available models\n";
		cout << "1. Model I\n";
		cout << "2. Model II\n";
		cout << "3. Model III\n\n";

		/* Ensures that the user selection is valid */
		while (true) {
			getline(cin, return_string);
			stringstream model_stream(return_string);
			if (model_stream >> return_model && return_model >= 1 && return_model <= 3) {
					break;
			}
			cout << "Invalid rotor selection. Please select a choice 1-3\n";
		}

		DashLine();  /* To ensure UI clarity */

		if (return_model == 1)
			return "I";
		else if (return_model == 2)
			return "II";
		else
			return  "III";
	}
	else
		return "Wide_B";
}

/* Prompts user for input, collects it, and then determines what value should be returned for initializing a rotor offset */
int SetRotorOffset(int slot_target) {
	string return_string;
	int return_offset;
		cout <<"Please enter the initial rotor offset for the ";

		/* Make sure the user knows what offset is being determined */
		if (slot_target == 0)
			cout << "right rotor (0-25)\n\n";
		else if (slot_target == 1)
			cout << "mid rotor (0-25)\n\n";
		else
			cout << "left rotor (0-25)\n\n";

		/* Ensures user input is valid */
		while (true) {
			getline(cin, return_string);
			stringstream model_stream(return_string);
			if (model_stream >> return_offset && return_offset >= 0 && return_offset <= 25) {
					break;
			}
			cout << "Invalid rotor selection. Please select a choice 0-25\n";
		}

		DashLine();  /* To ensure UI clarity */

		return return_offset;
}

/* Displays the application's construction menus */
Enigmachine Menu(const int map_size) {
	string right_model, mid_model, left_model, reflector_model;
	int right_offset, mid_offset, left_offset;

	/* Determine what model types will be used for the machine's rotors */
	for (int k = 0; k < 4; ++k) {
		if (k == 0)
			right_model = SetRotorModel(k);
		else if (k == 1)
			mid_model = SetRotorModel(k);
		else if (k == 2)
			left_model = SetRotorModel(k);
		else
			reflector_model = SetRotorModel(k);
	}

	/* Determine the offsets of those rotors */
	for (int k = 0; k < 3; ++k) {
		if (k == 0)
			right_offset = SetRotorOffset(k);
		else if (k == 1)
			mid_offset = SetRotorOffset(k);
		else
			left_offset = SetRotorOffset(k);
	}

	return Enigmachine(right_model, mid_model, left_model, reflector_model, right_offset, mid_offset, left_offset, map_size);
}
#endif