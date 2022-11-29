class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int len = nums.size();
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 || nums[i] >= nums.size())
            {
                nums[i] = 0;
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[nums[i] % len] += len;
            }
        }
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] / len == 0)
            {
                return i;
            }
        }
        
        return len;
    }
};