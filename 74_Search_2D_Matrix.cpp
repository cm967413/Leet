#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int len = m*n;

        int l = 0;
        int r = len - 1;
        while(l <= r)
        {
            //cout << "l and r: ";
            //cout << l << " " << r << endl;
            int mid = (l+r)/2;
            int row_idx = mid / n;
            int col_idx = mid % n;
            //cout << "position: ";
            //cout << row_idx << " " << col_idx << endl;
            if(matrix[row_idx][col_idx] == target)
            {
                return true;
            }
            else if (matrix[row_idx][col_idx] > target)
            {
                r = mid - 1;
            }
            else if (matrix[row_idx][col_idx] < target)
            {
                l = mid + 1;
            }
        }
        return false;
    }
};