LeetCode: 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        vector<int> res;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
	    for (int i = 0, j = 0; i < A.size() && j < B.size();)
	    {
		    if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1]))
		    {
			    res.emplace_back(A[i]);
			    i++; j++;
		    }
		    else
		    {
			    A[i] < B[j] ? i++ : j++; 
		    }
	    }	
	    return res;
    }
};