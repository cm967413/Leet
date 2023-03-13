#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> ma;
        map<char,int> mb;
        for(int i = 0; i < ransomNote.size(); i++)
        {
            ma[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); i++)
        {
            mb[magazine[i]]++;
        }
        for(const auto& [c, v] : ma)
        {
            if(v > mb[c])
                return false;
        }
        return true;
    }
};


class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        for(char c : magazine)
        {
            v[c - 'a']++;
        }
        for(char c : ransomNote)
        {
            if(--v[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};