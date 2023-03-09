#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp1(1,1);
        vector<int> tmp2(2,1);
        ans.push_back(tmp1);
        if(numRows == 1)
            return ans;
        ans.push_back(tmp2);
        for(int i = 2; i < numRows; i++)
        {
            vector<int>tmp;
            tmp.push_back(1);
            for(int j = 0; j < ans[i-1].size() - 1; j++)
            {
                tmp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++)
        {
            ans[i].resize(i+1, 1);
            for(int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};