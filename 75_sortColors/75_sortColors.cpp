// 75_sortColors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors1(vector<int>& nums) {
		vector<int> v(3, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			v[nums[i]]++;
		}
		int j = 0;
		for (int i = 0; i < 3; i++)
		{
			while (v[i]--)
				nums[j++] = i;
		}

	}
	void sortColors(vector<int>& nums) {
		int p0 = 0;
		int p2 = nums.size() - 1;
		while (p0 < nums.size() && nums[p0] == 0)p0++;
		while (p2 >= 0 && nums[p2] == 2)p2--;
		int cur = p0;
		while (cur <= p2)
		{
			if (nums[cur] == 2)
			{
				swap(nums[cur], nums[p2]);
				p2--;
				while (p2 >= 0 && nums[p2] == 2)p2--;
			}
			if (nums[cur] == 0)
			{
				swap(nums[cur], nums[p0]);
				p0++;
				while (p0 < nums.size() && nums[p0] == 0)p0++;
			}
			if (cur < p0)cur = p0;
			else
				cur++;
		}
	}
};

int main()
{
    return 0;
}

