#include <iostream>
#include<vector>
#include<iterator>
#include"LinearList.h"

using namespace std;

int ArrayTest()
{
	
	int inf[10] = { 1,2,3,4,5 };
	Array<int>num, xx(inf, 5);
	num[0] = 1;
	for (int *p = xx.begin(); p < xx.end(); p++)
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
	cout << xx.size() << endl;

	for (int *p = xx.begin(); p < xx.end(); p++)
		cout << *p << ' ';
	cout << xx[4] << endl;
	cout << xx.length() << endl;
	cout << xx[100] << endl;

	for (int* p = xx.begin(); p < xx.end(); p++)
		cout << *p << ' ';
	cout << endl;

	cout << xx.length() << endl;
	cout << xx.size() << endl;
	return 0;
}

int main()
{
	ArrayTest();
	return 0;
}