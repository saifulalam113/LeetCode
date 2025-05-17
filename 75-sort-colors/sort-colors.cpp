class Solution {
public:
    void sortColors(vector<int>& nums) {
        int iCount_zero = 0;
        int iCount_one = 0;
        int iCount_two = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                iCount_zero++;
            else if(nums[i] == 1)
                iCount_one++;
            else
                iCount_two++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(iCount_zero > 0)
            {
                nums[i] = 0;
                iCount_zero--;
            }
            else if(iCount_one > 0)
            {
                nums[i] = 1;
                iCount_one--;
            }
            else
            {
                nums[i] = 2;
                iCount_two--;
            }
        }

        return;
    }
};