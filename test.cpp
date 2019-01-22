#include <iostream>
#include"LinearList.h"

using namespace std;

int main()
{
	Array<int>num;
	num[0] = 1;
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	cout << endl;
	num.push_back(12);
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	cout << endl;
	num.push_back(121);
	num.push_back(120);
	num.push_back(113);
	num.push_back(119);
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	cout << endl;
	return 0;
}