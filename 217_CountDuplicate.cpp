#include <bits/stdc++.h>
using namespace std;

//1.sort the array O(nlogn)
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
        // int cur = nums[0];
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(cur == nums[i]) return true;
        //     else
        //     {
        //         cur = nums[i];
        //     }
        // }
        // return false;
    }
};


//2.Using set and check size O(nlogn), but unordered set can be O(n)
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> new_set(nums.begin(), nums.end());
        return (nums.size() == new_set.size());
    }
};

//3.Using map to count frequency
class Solution3 {
    public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> new_map;
        for(int i = 0; i < nums.size(); i++)
        {
            new_map[nums[i]]++;
        }
        bool flag = false;
        for(auto &it : new_map)
        {
            if(it.second >= 2) return true;
        }
        return false;
    }
};

