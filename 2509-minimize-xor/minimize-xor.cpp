class Solution {
public:
    bool isSet(int num, int bit) 
    {
        return num & (1 << bit);
    }

    void setBit(int& num, int bit)
    {
        num = num | (1 << bit);
    }

    void unsetBit(int& num, int bit)
    {
        num = num & ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        // the best choice for ans is num1 because num1 XOR num1 is 0;
        int ans = num1;

        int targetSetBits = __builtin_popcount(num2);
        int currentSetBits = __builtin_popcount(ans);

        int currentPos = 0;
        if(currentSetBits < targetSetBits)
        {
            while(currentSetBits < targetSetBits)
            {
                if(!isSet(ans, currentPos))
                {
                    setBit(ans, currentPos);
                    currentSetBits++;
                }

                currentPos++;
            }
        }
        else
        {
            while(currentSetBits > targetSetBits)
            {
                if(isSet(ans, currentPos))
                {
                    unsetBit(ans, currentPos);
                    currentSetBits--;
                }

                currentPos++;
            }
        }

        return ans;
    }
};