#include <iostream>
#include<set>
#include<vector>
#include"LinearList.h"

using namespace std;

int main()
{
	int num[10] = { 15,2,3,4,5 };
	Array<int> a(num);
	cout << a.length();
	return 0;
}