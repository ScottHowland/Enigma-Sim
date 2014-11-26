/* Each function determines the value each array index (case), maps to 
		-Can be expanded to include mappings to and from non-alpha characters
		-EX...
			In the situation
				case 3:
					return 9;
			The array's 3rd position ('D') will contain, or map to, a value of 9 ('J') */

#ifndef ENIGMA_ENIGMA_ROTORMAPS_H_
#define ENIGMA_ENIGMA_ROTORMAPS_H_

#include <array>

using std::array;

/* Determines mapping scheme for a Wide B reflector type 
		-Unlike regular rotors, a reflector creates two-way mappings between characters
		-EX...
			If 5 'F' maps to 23 'X', then 23 will map to 5 */
int WideBMap(int alpha_int) {
	switch (alpha_int) {

	case 0:
		return 24;
	case 1:
		return 17;		
	case 2:
		return 20;
	case 3:
		return 7;
	case 4:
		return 16;
	case 5:
		return 18;
	case 6:
		return 11;
	case 7:
		return 3;
	case 8:
		return 15;
	case 9:
		return 23;
	case 10:
		return 13;
	case 11:
		return 6;
	case 12:
		return 14;
	case 13:
		return 10;
	case 14:
		return 12;
	case 15:
		return 8;
	case 16:
		return 4;
	case 17:
		return 1;
	case 18:
		return 5;
	case 19:
		return 25;
	case 20:
		return 2;
	case 21:
		return 22;
	case 22:
		return 21;
	case 23:
		return 9;
	case 24:
		return 0;
	case 25:
		return 19;
	default:
		return 0;
	}
}
/* Determines mapping scheme for I-type rotors
		-Standard rotors do not create two-way mappings between characters 
		-EX...
			If 5 maps to 23, then 23 will not map to 5 
		-There are, however, circumstances where a value will map to itself */
int IMap(int alpha_int) {
	switch (alpha_int) {

	case 0:
		return 4;
	case 1:
		return 10;
	case 2:
		return 12;
	case 3:
		return 5;
	case 4:
		return 11;
	case 5:
		return 6;
	case 6:
		return 3;
	case 7:
		return 16;
	case 8:
		return 21;
	case 9:
		return 25;
	case 10:
		return 13;
	case 11:
		return 19;
	case 12:
		return 14;
	case 13:
		return 22;
	case 14:
		return 24;
	case 15:
		return 7;
	case 16:
		return 23;
	case 17:
		return 20;
	case 18:
		return 18;
	case 19:
		return 15;
	case 20:
		return 0;
	case 21:
		return 8;
	case 22:
		return 1;
	case 23:
		return 17;
	case 24:
		return 2;
	case 25:
		return 9;
	default:
		return 0;
	}
}
/* Determines mapping scheme for II-type rotors */
int IIMap(int alpha_int) {
	switch (alpha_int) {

	case 0:
		return 0;
	case 1:
		return 9;
	case 2:
		return 3;
	case 3:
		return 10;
	case 4:
		return 18;
	case 5:
		return 8;
	case 6:
		return 17;
	case 7:
		return 20;
	case 8:
		return 23;
	case 9:
		return 1;
	case 10:
		return 11;
	case 11:
		return 7;
	case 12:
		return 22;
	case 13:
		return 19;
	case 14:
		return 12;
	case 15:
		return 2;
	case 16:
		return 16;
	case 17:
		return 6;
	case 18:
		return 25;
	case 19:
		return 13;
	case 20:
		return 15;
	case 21:
		return 24;
	case 22:
		return 5;
	case 23:
		return 21;
	case 24:
		return 14;
	case 25:
		return 4;
	default:
		return 0;
	}
}
/* Determines mapping scheme for III-type rotors */
int IIIMap(int alpha_int) {
	switch (alpha_int) {

	case 0:
		return 1;
	case 1:
		return 3;
	case 2:
		return 5;
	case 3:
		return 7;
	case 4:
		return 9;
	case 5:
		return 11;
	case 6:
		return 2;
	case 7:
		return 15;
	case 8:
		return 17;
	case 9:
		return 19;
	case 10:
		return 23;
	case 11:
		return 21;
	case 12:
		return 25;
	case 13:
		return 13;
	case 14:
		return 24;
	case 15:
		return 4;
	case 16:
		return 8;
	case 17:
		return 22;
	case 18:
		return 6;
	case 19:
		return 0;
	case 20:
		return 10;
	case 21:
		return 12;
	case 22:
		return 20;
	case 23:
		return 18;
	case 24:
		return 16;
	case 25:
		return 14;
	default:
		return 0;
	}
}
#endif