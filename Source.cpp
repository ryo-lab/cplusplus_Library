#include<iostream>
#include "String.h"
#include "Vector.h"
using namespace std;

int main() {
	Vector myvector;

	for (unsigned int i = 0; i < 5; i++)
		myvector.push_back(i*2);

	std::cout << "myvector contains:";
	for (Vector::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	
	return 0;
}