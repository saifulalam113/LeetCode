class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //Description:
        //Suppose, derived = [a1, a2, a3] and original = [b1, b2, b3]
        //a1 = b1 XOR b2
        //a2 = b2 XOR b3
        //a3 = b3 XOR b1

        //Approach:
        //if we XOR all the elements in derived:
        //a1 XOR a2 XOR a3 = (b1 XOR b2) XOR (b2 XOR b3) XOR (b3 XOR b1) = (b1 XOR b1) XOR (b2 XOR b2) XOR (b3 XOR b3) = (0) XOR (0) XOR (0) = 0

        //Findings:
        // If we XOR all the elements in derived array, the result should be 0. If not, then there is no such possible original array that will produce this derived array.

        int result = 0;
        for(int i = 0; i < derived.size(); i++)
            result = result ^ derived[i];

        if(result == 0)
            return true;

        return false;
    }
};