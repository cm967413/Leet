class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int front = i+1;
            int back = nums.size() - 1;
            int target = -nums[i];
            if(target < 0)
                continue;
            while(front < back)
            {
                int sum = nums[front] + nums[back];
                
                if(sum < target)
                {
                    front++;
                }
                else if(sum > target)
                {
                    back--;
                }
                else
                {
                    vector<int> tmp = {nums[i],nums[front],nums[back]};
                    int tmp1 = nums[front];
                    int tmp2 = nums[back];
                    res.push_back(tmp);
                    while(front < back && nums[front] == tmp1)
                    {
                        front++;
                    }
                    while(front < back && nums[back] == tmp2)
                    {
                        back--;
                    }
                }
                while(i+1 < nums.size() && nums[i+1] == nums[i])
                {
                    i++;
                }
            }
        }
        return res;
    }
};



//Solution2
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            int front = i + 1;
            int back = nums.size() -1;
            int target = -nums[i];
            while(front < back)
            {
                if(nums[front] + nums[back] < target)
                    front++;
                else if(nums[front] + nums[back] > target)
                    back--;
                else
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]); tmp.push_back(nums[front]); tmp.push_back(nums[back]);
                    ans.push_back(tmp);
                    // while (front < back && num[front] == triplet[1]) front++;
                    while(front < nums.size()-1 && front < back)
                    {
                        if(nums[front] == tmp[1])
                            front++;
                        else
                            break;
                    }
                    while(back < nums.size())
                    {
                        if(nums[back] == tmp[2])
                            back--;
                        else 
                            break;
                    }
                }
            }
            while(i < nums.size()-1)
            {
                if(nums[i] == nums[i+1])
                    i++;
                else
                    break;
            }
            // while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            //     i++;

        }
        return ans;
    }
};
