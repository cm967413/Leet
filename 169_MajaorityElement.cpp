#include<bits/stdc++.h>
//Bit Manipulation
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        for(int i = 1, mask = 1; i < 32; i++, mask<<=1)
        {
            int current_bit = 0;
            for(auto num : nums)
            {
                if(num & mask)
                    current_bit++;
            }
            if(current_bit > floor(nums.size()/2))
                ans |= mask;
        }
        return ans;
    }
};
//Moore Voting Algorithm
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count==0)
            {
                ans = nums[i];
                count++;
            }
            else if(count)
            {
                if(ans == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return ans;
    }
};