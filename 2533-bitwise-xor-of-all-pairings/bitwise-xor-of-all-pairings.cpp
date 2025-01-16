class Solution {
public:
    //Learning: If we XOR a number even number of times, it will become 0
    //If we XOR a element odd number of times, the result will be the same number
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // if n1 is even, each element in nums2 is XOR'd even number of times. Using the property of XOR'd (x ^ x = 0), all the elements cancel out and contribute 0 in the result;
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