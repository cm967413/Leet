#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int maxim = current;
        for(int i = 1; i < nums.size(); i++)
        {
            current = max(current+nums[i], nums[i]);
            maxim = max(maxim, current);
        }
        return maxim;

    }
};

int main()
{
    return 0;
}