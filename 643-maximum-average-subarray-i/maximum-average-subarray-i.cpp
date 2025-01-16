class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int windowSum = 0;
        int count = 0;
        int maxWindowSum = -pow(10, 9);
        for(int i = 0; i < n; i++)
        {
            windowSum += nums[i];
            count++;

            if(count > k)
            {
                windowSum -= nums[i-k];
                count--;
            }

            if(count == k)
            {
                maxWindowSum = max(maxWindowSum, windowSum); 
            }
        }

        return maxWindowSum/(double)k;
    }
};