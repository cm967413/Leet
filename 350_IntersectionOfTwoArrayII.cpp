#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        map<int,int> mp2;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++)
        {
            if(mp1.count(nums1[i]) == 0)
            {
                mp1[nums1[i]] = 1;
            }
            else
            {
                mp1[nums1[i]]++;
            }
        }

        for(int i = 0; i < nums2.size(); i++)
        {
            if(mp2.count(nums2[i]) == 0)
            {
                mp2[nums2[i]] = 1;
            }
            else
            {
                mp2[nums2[i]]++;
            }
        }
        
        for(auto it : mp1)
        {
            if(mp2.count(it.first))
            {
                int num = (mp1[it.first] < mp2[it.first]) ? mp1[it.first] : mp2[it.first];
                for(int i = 0; i < num; i++)
                {
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            if(mp[nums2[i]] > 0)
            {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while(i != nums1.size() && j != nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
        }
        return ans;
    }
};


