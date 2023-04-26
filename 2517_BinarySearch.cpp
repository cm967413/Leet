class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int max_tastiness = price[price.size()-1] - price[0];
        int l = 0, r = max_tastiness;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(isValid(price, k, mid) == true)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return l-1;
    }

    bool isValid(vector<int>& price, int k, int diff)
    {
        int count = 1;
        int prev = price[0];
        for(int i = 1; i < price.size(); i++)
        {
            if(price[i] - prev >= diff)
            {
                count++;
                prev = price[i];
            }
            if(count >= k) return true;
        }
        return false;
    }
};