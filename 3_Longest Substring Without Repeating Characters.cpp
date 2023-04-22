#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ans="";
        for(int k = 0; k < s.size(); k++)
        {
            string temp="";
            map<char,int> mp;
            for(int i = k; i < s.size(); i++)
            {
                if(mp.find(s[i]) == mp.end())
                {
                    mp[s[i]] = 1;
                    temp+=s[i];
                    if(temp.size() > ans.size())
                        ans = temp;
                    
                }
                else
                {
                    break;
                }
            }
        }
        
        return ans.size();
    }
};