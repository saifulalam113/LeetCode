// Prefix Sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        int currSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(currSum == sum - currSum - nums[i])
                return i;

            currSum += nums[i];
        }

        return -1;
    }
};