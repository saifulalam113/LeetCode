class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();

        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int maxVowel = 0;
        int curVowel = 0;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(vowel.find(s[i]) != vowel.end())
            {
                curVowel++;
            }

            if(i >= k)
            {
                if(vowel.find(s[i-k]) != vowel.end())
                {
                    curVowel--;
                }
            }

            if(i >= k - 1)
            {
                maxVowel = max(maxVowel, curVowel);
            }
            

        }

        return maxVowel;
    }
};