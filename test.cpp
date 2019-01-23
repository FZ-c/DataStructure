#include <iostream>
#include<vector>
#include"LinearList.h"

using namespace std;

int main()
{
	Array<int>num, xx;
	num[0] = 1;
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	cout << endl;
	num.push_back(12);
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	cout << endl;
	num.push_back(121);
	cout << num.length() << endl;
	num.push_back(120);
	cout << num.length() << endl;
	num.push_back(113);
	cout << num.length() << endl;
	num.push_back(119);
	cout << num.length() << endl;
	for (int *p = num.begin(); p < num.end(); p++)
		cout << *p << ' ';
	xx = num;

	cout << xx.length() << endl;
	for (int *p = xx.begin(); p < xx.end(); p++)
		cout << *p << ' ';
	num.clear();
	xx = num;
	cout << xx.length() << endl;
	cout << endl;
	return 0;
}