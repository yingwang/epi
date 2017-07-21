#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int SearchFirstK(const vector<int>& nums, int k)
{
	int i = 0;
	int j = nums.size() - 1;
	int res = 0;
	while (i <= j)
	{
		int mid = i + (j - i) / 2;
		if (nums[mid] > k)
		{
			j = mid - 1;
		}
		else if (nums[mid] < k)
		{
			i = mid + 1;
		}
		else if (nums[mid] == k)
		{
			res = mid;
			j = mid - 1;
		}
	}
	return res;
}

int main()
{
	vector<int> input = {1, 3, 4, 5, 6, 6, 6, 8, 9, 10, 11, 16};
	cout << SearchFirstK(input, 6) << endl;
}