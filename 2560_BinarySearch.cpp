class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end());
        int left = nums[0];
        //int right = nums[nums.size()-1];
        int right = 1e9;
        int ans;
        while(left < right)
        {
            int mid = (left + right) /2;
            if(isValid(nums, k, mid) == true)
            {
                
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }

    bool isValid(vector<int>& nums, int k, int expected_min_cap)
    {
        int steal = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= expected_min_cap)
            {
                steal++;
                i++;
            }
            if(steal >= k) return true;
        }
        return false;
    }
};