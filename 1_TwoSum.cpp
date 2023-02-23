#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int ret = target - nums[i];
            auto iter = mp.find(ret);
            // cout << ret << " " << iter->second << endl;
            if(iter != mp.end() && iter->second != i)
            {
                ans.push_back(i); ans.push_back(iter->second);
                break;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}