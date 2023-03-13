#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26,0);
        vector<int> vt(26,0);
        for(char c : s)
            vs[c - 'a']++;
        for(char c : t)
        {   
            vt[c - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(vs[i] != vt[i])
                return false;
        }
        return true;
    }
};


class Solution2 {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(v[i] != 0) return false;
        }
        return true;
    }
};