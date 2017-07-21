#include <iostream>
#include <string>

using namespace std;

short Parity(unsigned long x)
{
	int res = 0;
	while (x)
	{
		x &= x - 1;
		res++;
	}
	return res;
}

int main()
{
	cout << Parity(10) << endl;
	cout << Parity(19472028) << endl;
	cout << Parity(0) << endl;
}