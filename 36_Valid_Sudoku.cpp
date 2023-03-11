#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int blocks[3][3][9] = {0};
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] != '.')
                {
                    int num = board[r][c] - '0' - 1;
                    row[r][num]++;
                    col[c][num]++;
                    blocks[r/3][c/3][num]++;
                    if(row[r][num] > 1 || col[c][num] > 1 || blocks[r/3][c/3][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};