#ifndef __JS_OBJECT__
#define __JS_OBJECT__

#include <vector>
#include <string>
using namespace std;

class Object;
class Object {
	public:
		static const short int  CHAR ;
		static const short int  UCHAR;
		static const short int  SHORT;
		static const short int  USHORT;
		static const short int  LONG;
		static const short int  ULONG;
		static const short int  FLOAT;
		static const short int  DOUBLE;
		static const short int  STRING;
		static const short int  ARRAY;
		static const short int  NUMBER;
		static const short int  OBJECT;
		static const short int  J_STRING;
		
		Object();
		void set(string key, char v);
		char get(string key);
		
		void set(string key, unsigned char v);
		unsigned char get(string key, unsigned char ch);
		
		void set(string key, short n);
		short get(string key, short n);
		//void set(string key, Object v);
		~Object();
		
		void trace();
	private:
		vector<string> keys;
		vector<unsigned short> keys_indexes;
		vector<short> keys_types; //see const
		vector<char> char_values; 
		vector<unsigned char> uchar_values; 
		vector<short> short_values; 
		vector<unsigned short> ushort_values; 
		vector<long> long_values; 
		vector<unsigned long> ulong_values; 
		vector<float> float_values;
		vector<double> double_values;
		vector<string> string_values;
		//vector<JArray> array_values;TODO un me!
		//vector<JNumber> number_values;
		vector <Object> object_values;
		//vector<JString> j_string_values;
		
		bool _get(string key, unsigned short &v_type, unsigned short &target, unsigned short &key_index);
		unsigned short int _removeExists(string key, bool &f);
};

#endif //__JS_OBJECT__

