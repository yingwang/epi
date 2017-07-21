LeetCode: 134. Gas Station

class Solution {
public:
/*
Whenever the sum is negative, reset it and let the car start from next point.
In the mean time, add up all of the left gas to total. If it's negative finally, return -1 since it's impossible to finish.
If it's non-negative, return the last point saved in res;
*/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int res = -1;
        for (int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0)
            {
                res = i;
                sum = 0;
            }
        }
        return total >= 0 ? res + 1:-1; 
    }
};