class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int count = 0;
        int maxCount = 0;
        int start = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else
            {
                if(k > 0)
                {
                    count++;
                    k--;
                }
                else
                {
                    maxCount = max(maxCount , count);
                    while(nums[start] != 0)
                    {
                        start++;
                        count--;
                    }
                    start++;
                }
            }
        }

        maxCount = max(maxCount , count);
        return maxCount-1;
    }
};