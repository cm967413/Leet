#include<bits/stdc++.h>
using namespace std;


class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            buy = min(prices[i], buy);
            sell = max(sell, prices[i] - buy);
            //buy = min(prices[i], buy);
        }
        return sell;
    }
};



class Solution2 {
public:
     int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur + prices[i] - prices[i-1]);
            //cout << maxCur << " " << prices[i] - prices[i-1]<<endl;
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};