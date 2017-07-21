#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;


double BuyAndSellStockOnce(const vector<double>& prices)
{
	double lowestPrice = INT_MAX;
	double maxProfit = INT_MIN;
	for (int i = 0; i < prices.size(); i++)
	{
		maxProfit = max(maxProfit, prices[i] - lowestPrice);
		lowestPrice = min (lowestPrice, prices[i]);
	}
	return maxProfit;
}

int main()
{
	vector<double> input = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	cout << BuyAndSellStockOnce(input) << endl;
}