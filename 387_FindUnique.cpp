#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

class Solution2 {
public:
	int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for (const auto& [c, p] : m) {
            if (p.first == 1) {
                idx = min(idx, p.second);
            }
        }
        return idx == s.size() ? -1 : idx;
    }
};