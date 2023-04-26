class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxim = 0;
        int peak = 0;
        while(i<j)
        {
            peak = min(height[i], height[j]);
            maxim = max(maxim, (j-i)*peak);
            //cout << "peak:" << peak<<endl;
            //cout << "i and j:" << i << " " << j << endl;
            //cout << "maxim:" << maxim << endl;
            while(height[i] <= peak && i < j) 
            {
                i++;
            }
            while(height[j] <= peak && i < j)
            {
                j--;
                //cout << j << endl;
            }
        }
        return maxim;
    }
};