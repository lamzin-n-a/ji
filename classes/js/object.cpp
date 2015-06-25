#include <iostream>
#include <string>
using namespace std;
#include "object.h"

const short int Object::CHAR      = 0;
const short int Object::UCHAR     = 1;
const short int Object::SHORT     = 2;
const short int Object::USHORT    = 3;
const short int Object::LONG      = 4;
const short int Object::ULONG     = 5;
const short int Object::FLOAT     = 6;
const short int Object::DOUBLE    = 7;
const short int Object::STRING    = 8;
const short int Object::ARRAY     = 9;
const short int Object::NUMBER   = 10;
const short int Object::OBJECT   = 11;
const short int Object::J_STRING = 12;

Object::Object() {
}

Object::~Object() {
}
//CHAR
void Object::set(string key, char v) {
	//cout << "set " << key << " = " << v << " AS CHAR\n";
	bool f = true;
	unsigned short it = _removeExists(key, f);//set empty value or call ~ for content, return index in keys
	unsigned short target_it;
	if (!f) { //not replace value
		//cout << "!F\n";
		keys.push_back(key);
		keys_types.push_back(Object::CHAR);
		keys_indexes.push_back(0);
		it = keys.size() - 1;
		char_values.push_back(v);
		target_it = char_values.size() - 1;
	} else {
		//cout << "FQ!\n";
		if (keys_types[it] == Object::CHAR) {
			//cout << "FQ! -> if\n";
			target_it = keys_indexes[it];
			char_values[target_it] = v;
		} else {
			//cout << "FQ! -> else\n";
			char_values.push_back(v);
			target_it = char_values.size() - 1;
			keys_types[it] = Object::CHAR;
		}
	}
	keys_indexes[it] = target_it;
	//cout << "EXIT FROM set " << key << " = " << v << " AS CHAR\n\n";
}
char Object::get(string key) {
	unsigned short target, i, v_type, index;
	if (_get(key, v_type, target, index)) {
		if (v_type == Object::CHAR && char_values.size() > target) {
			return char_values[target];
		}
	}
	return '\0';
}
//UCHAR
void Object::set(string key, unsigned char v) {
	bool f = true;
	unsigned short it = _removeExists(key, f);
	unsigned short target_it;
	if (!f) { //not replace value
		keys.push_back(key);
		keys_types.push_back(Object::UCHAR);
		keys_indexes.push_back(0);
		it = keys.size() - 1;
		uchar_values.push_back(v);
		target_it = uchar_values.size() - 1;
	} else {
		if (keys_types[it] == Object::UCHAR) {
			target_it = keys_indexes[it];
			uchar_values[target_it] = v;
		} else {
			uchar_values.push_back(v);
			target_it = uchar_values.size() - 1;
			keys_types[it] = Object::UCHAR;
		}
	}
	keys_indexes[it] = target_it;
}
unsigned char Object::get(string key, unsigned char ch) {
	unsigned short target, i, v_type, index;
	if (_get(key, v_type, target, index)) {
		if (v_type == Object::UCHAR && uchar_values.size() > target) {
			return uchar_values[target];
		}
	}
	return '\0';
}
//SHORT
void Object::set(string key, short v) {
	bool f = true;
	unsigned short it = _removeExists(key, f);
	unsigned short target_it;
	if (!f) { //not replace value
		keys.push_back(key);
		keys_types.push_back(Object::SHORT);
		keys_indexes.push_back(0);
		it = keys.size() - 1;
		short_values.push_back(v);
		target_it = short_values.size() - 1;
	} else {
		if (keys_types[it] == Object::SHORT) {
			target_it = keys_indexes[it];
			short_values[target_it] = v;
		} else {
			short_values.push_back(v);
			target_it = uchar_values.size() - 1;
			keys_types[it] = Object::SHORT;
		}
	}
	keys_indexes[it] = target_it;
}
short Object::get(string key, short n) {
	unsigned short target, i, v_type, index;
	if (_get(key, v_type, target, index)) {
		if (v_type == Object::SHORT && short_values.size() > target) {
			return short_values[target];
		}
	}
	return '\0';
}


bool Object::_get(string key, unsigned short &v_type, unsigned short &target, unsigned short &key_index) {
	unsigned short i;
	for (i = 0; i < keys.size(); i++) {
		if (keys[i] == key) {
			key_index = i;
			if (keys_types.size() > i) {
				v_type = keys_types[i];
			}
			if (keys_indexes.size() > i) {
				target = keys_indexes[i];
			}
			return true;
		}
	}
	return false;
}
//set empty value or call ~ for content, return index in keys
//TODO add js types
unsigned short int Object::_removeExists(string key, bool &f) {
	unsigned short v_type, target, index;
	f = _get(key, v_type, target, index);
	if (!f) {
		return 0;
	}
	
	switch (v_type) {
		case CHAR:
			if (char_values.size() > target) {
				char_values[target] = '\0';
				return index;
			}
			break;
		case UCHAR:
			if (uchar_values.size() > target) {
				uchar_values[target] = '\0';
				return index;
			}
			break;
		case SHORT:
			if (short_values.size() > target) {
				short_values[target] = 0;
				return index;
			}
			break;
		case USHORT:
			if (ushort_values.size() > target) {
				ushort_values[target] = 0;
				return index;
			}
			break;
		case LONG:
			if (long_values.size() > target) {
				long_values[target] = 0;
				return index;
			}
			break;
		case ULONG:
			if (ulong_values.size() > target) {
				ulong_values[target] = 0;
				return index;
			}
			break;
		case FLOAT:
			if (float_values.size() > target) {
				float_values[target] = .0;
				return index;
			}
			break;
		case DOUBLE:
			if (double_values.size() > target) {
				double_values[target] = .0;
				return index;
			}
			break;
		case STRING:
			if (string_values.size() > target) {
				string_values[target] = string("");
				return index;
			}
			break;
		/*case ARRAY:
			if (array_values.size() > target) {
				~array_values[target];
				return index;
			}
			break;*/
		/*case NUMBER:
			if (number_values.size() > target) {
				~number_values[target];
				return index;
			}
			break;*/
		case OBJECT:
			if (object_values.size() > target) {
				object_values[target].~Object();
				return index;
			}
			break;
		/*case J_STRING:
			if (j_string_values.size() > target) {
				j_string_values[target] = String("");
				return index;
			}
			break;*/
	}
	f = false;
	return 0;
}

void Object::trace() {
	/*for (int i = 0; i < sl.size(); i++) {
		cout << sl.at(i) << "\n";
	}*/
}
