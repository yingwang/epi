#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

string IntToString(int x)
{
	bool isNegative = false;
	if (x < 0)
	{
		isNegative = true;
		x = -x;
	}
	string s;
	do
	{
		s += '0' + x % 10;
		x /= 10;
	} while (x);
	s += isNegative? "-" : "";
	reverse(s.begin(), s.end());
	return s;
}

int StringToInt(const string& s)
{
	int pos = 0;
	bool isNegative = false;
	if (s[pos] == '-')
	{
		isNegative = true;
		pos++;
	}
	int res = 0;
	for (int i = pos; i < s.size(); i++)
	{
		res = res * 10 + s[i] - '0';
	}
	return isNegative? -res : res;
}

int main()
{
	cout << IntToString(42803) << endl;
	cout << IntToString(-1903) << endl;
	cout << IntToString(0) << endl;
	cout << IntToString(9830) << endl;
	cout << StringToInt("393") << endl;
	cout << StringToInt("-1") << endl;
	cout << StringToInt("0") << endl;
	cout << StringToInt("-9370") << endl;
}



