#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> sums;
	void generate(int sumEach, int i, vector<int> &nums)
	{
		if (i == nums.size())
		{
			sums.push_back(sumEach);
			return;
		}
		// sumEach += nums[i];
		generate(sumEach + nums[i], i + 1, nums);
		generate(sumEach, i + 1, nums);
	}
	int Kadane(vector<int> nums)
	{
		generate(0, 0, nums);
		int maxSum = *max_element(sums.begin(), sums.end());
		return maxSum;
	}
};

int main()
{
	Solution ans;
	vector<int> nums = {-2, -3, 4, 5, -6, 8, 9, -1, -2, -7, 2};
	cout << "Maximum Sum is :" << ans.Kadane(nums) << endl;
	return 0;
}