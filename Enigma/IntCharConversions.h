/* Based on the value of a given character, CharToInt converts it to an equivalent integer value 
   Similarly, IntToChar will convert a given integer value into its character counterpart */

#ifndef ENIGMA_ENIGMA_INTCHARCONVERSIONS_H_
#define ENIGMA_ENIGMA_INTCHARCONVERSIONS_H_

#include <string>

using std::string;

/* Return integer value based on character to be converted 
		-NOTE: Can only handle capital, alpha-type characters
		-If an unexpected value is entered, a 0 will be returned */
#pragma region CharToInt
int CharToInt(const char conversion_target) {
	switch (conversion_target) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	case 'K':
		return 10;
	case 'L':
		return 11;
	case 'M':
		return 12;
	case 'N':
		return 13;
	case 'O':
		return 14;
	case 'P':
		return 15;
	case 'Q':
		return 16;
	case 'R':
		return 17;
	case 'S':
		return 18;
	case 'T':
		return 19;
	case 'U':
		return 20;
	case 'V':
		return 21;
	case 'W':
		return 22;
	case 'X':
		return 23;
	case 'Y':
		return 24;
	case 'Z':
		return 25;
	case ' ':
		return 26;
	default:
		return 0;
	}
}
#pragma endregion Converts a character to an integer equivalent

/* Return character value based on integer to be converted
		-NOTE: Only returns capital, alpha-type characters 
		-If an unexpected value is entered, an 'A' will be returned */
#pragma region IntToChar
char IntToChar(int conversion_target) {
	switch (conversion_target) {
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'C';
	case 3:
		return 'D';
	case 4:
		return 'E';
	case 5:
		return 'F';
	case 6:
		return 'G';
	case 7:
		return 'H';
	case 8:
		return 'I';
	case 9:
		return 'J';
	case 10:
		return 'K';
	case 11:
		return 'L';
	case 12:
		return 'M';
	case 13:
		return 'N';
	case 14:
		return 'O';
	case 15:
		return 'P';
	case 16:
		return 'Q';
	case 17:
		return 'R';
	case 18:
		return 'S';
	case 19:
		return 'T';
	case 20:
		return 'U';
	case 21:
		return 'V';
	case 22:
		return 'W';
	case 23:
		return 'X';
	case 24:
		return 'Y';
	case 25:
		return 'Z';
	case 26:
		return ' ';
	default:
		return 'A';
	}
}
#pragma endregion Converts an integer to a character equivalent

#endif