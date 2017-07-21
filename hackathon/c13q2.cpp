#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool IsLetterConstructibleFromMagazine(const string& letter, const string& magazine)
{
	unordered_map<char, int> ht;
	for (char c : letter)
	{
		ht[c]++;
	}

	for (char c : magazine)
	{
		if (ht.find(c) == ht.end()) continue;
		else if (ht[c] == 1) ht.erase(c);
		else ht[c]--;
		if (ht.empty()) return true;
	}
	return ht.empty();
}

int main()
{
	cout << IsLetterConstructibleFromMagazine("abcdefghijkl", "abcdef ab abcdefghijkl abcdefghijkl cdefghijkl ghijkl") << endl;
	cout << IsLetterConstructibleFromMagazine("abcdefghijk", "abcdghijkl") << endl;
}