#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int NumCombForScore(const vector<int>& scores, int final)
{
	vector<vector<int>> res(scores.size(), vector<int>(final + 1, 0));
	for (int i = 0; i < scores.size(); i++)
	{
		res[i][0] = 1;
		for (int j = 1; j <= final; j++)
		{
			int without = i >= 1 ? res[i - 1][j] : 0;
			int with = j >= scores[i] ? res[i][j - scores[i]] : 0;
			res[i][j] = without + with;
		}
	}
	return res.back().back();
}

int main()
{
	vector<int> input = {2, 3, 7};
	cout << NumCombForScore(input, 9) << endl;
}