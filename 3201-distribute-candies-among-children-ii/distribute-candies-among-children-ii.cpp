class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        for(int i = 0; i <= min(n, limit); i++)
        {
            if(n-i > 2*limit)
                continue;
            ways += min(n-i, limit) - max(n-i-limit, 0) +1;
        }

        return ways;
    }
};