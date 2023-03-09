#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        int m = mat.size();
        int n = mat[0].size();

        queue<int> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                q.push(mat[i][j]);
            
        if(m*n == r*c)
        {
            for(int i = 0; i < r; i++)
            {
                vector<int> tmp;
                for(int j = 0; j < c; j++)
                {
                    tmp.push_back(q.front());
                    q.pop();
                }
                ans.push_back(tmp);
            }
            return ans;
        }
        else
            return mat;
   }
};



class Solution2 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = size(mat), n = size(mat[0]), total = m * n;
        if(r * c != total) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < total; i++) 
            ans[i / c][i % c] = mat[i / n][i % n];
        return ans;
    }
};