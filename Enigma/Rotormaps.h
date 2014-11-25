#ifndef _ROTORMAPS_H
#define _ROTORMAPS_H
#include <array>

using std::array;

#pragma region WideB_map
int WideB_map(int alphaint) {
	switch (alphaint) {

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
#pragma endregion Mapping for a Wide B Reflector

#pragma region I_map
int I_map(int alphaint) {
	switch (alphaint) {

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
#pragma endregion Mapping for a I rotor

#pragma region II_map
int II_map(int alphaint) {
	switch (alphaint) {

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
#pragma endregion Mapping for a II rotor

#pragma region III_map
int III_map(int alphaint) {
	switch (alphaint) {

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
#pragma endregion Mapping for a III rotor

#endif