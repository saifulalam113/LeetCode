class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        //nums1 = [m1,m2]
        //nums2 = [x1, x2]

        //Result:
        // (m1 XOR x1) XOR (m1 XOR x2) XOR (m2 XOR x1) XOR (m2, x2)
        // = (m1 XOR m1) XOR (m2 XOR m2) XOR (x1 XOR x1) XOR (x2 XOR x2)
        // = 0 XOR 0 XOR 0 XOR 0
        // = 0 

        int ans = 0;
        if(n1 % 2  != 0)
        {
            for(int i = 0; i < n2; i++)
                ans = ans ^ nums2[i];
        }

        if(n2 % 2  != 0)
        {
            for(int i = 0; i < n1; i++)
                ans = ans ^ nums1[i];
        }

        return ans;
        
    }
};