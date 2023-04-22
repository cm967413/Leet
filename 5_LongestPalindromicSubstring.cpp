#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();
        vector<vector<bool> > table(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            table[i][i] = true;
            if(i == n-1) break;
                table[i][i+1] = (s[i] == s[i+1]);
        }

        //dp part
        for(int i = n - 3; i >=0; i--)
        {
            for(int j = i + 2; j < n; j++)
            {
                if(s[i] == s[j] && table[i+1][j-1] == true)
                    table[i][j] = true;
            }
        }
        int max_len = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(table[i][j] == true)
                {
                    if(j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    } 
                }
            }
        }
        return ans;
        
    }
};