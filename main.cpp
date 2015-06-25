#include <iostream>
#include <string>
#include "classes/js/object.h"
using namespace std;

void runtest();
void print(string s);
void print_status(int err);

int main() {
	cout << "Hello world\n";
	runtest();
	return 0;
}


void runtest() {
	int err = 0;
	string test_case = "(Test reset types char - uchar)";
	print(test_case + "\n");
	
	Object o;
	unsigned char uch = 'd';
	o.set("v1", 'a');
	o.set("v2", 'b');
	o.set("v2", 'c');
	o.set("v2", uch);
	if (o.get("v2", uch) != (unsigned char)'d') {
		err++;
		cout << "error get v2 expect 'd', got '" << o.get("v2", uch) << "\n";
	}
	o.set("v2", 'n');
	if (o.get("v1") != (char)'a') {
		err++;
		cout << "error get v1 expect 'a', got '" << o.get("v1") << "\n";
	}
	if (o.get("v2") != (char)'n') {
		err++;
		cout << "error get v2 expect 'n', got '" << o.get("v1") << "\n";
	}
	
	print_status(err);
	//=================
	err = 0;
	test_case = "(Test reset types char - short)";
	print(test_case + "\n");
	short n = 1001;
	o.set("v1", n);
	if (o.get("v1", n) != (short)1001) {
		err++;
		cout << "error get v1 expect 1001, got " << o.get("v1", n) << "\n";
	}
	o.set("v1", 'N');
	if (o.get("v1") != 'N') {
		err++;
		cout << "error get v1 expect N, got " << o.get("v1") << "\n";
	}
	print_status(err);
}

void print_status(int err) {
	if (!err) {
		print("DONE!");
	} else {
		cout << "has " << err << "errors!\n\n";
	}
}

void print(string s) {
	cout << s << "\n";
}
