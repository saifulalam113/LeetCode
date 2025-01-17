class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;
        for(int i = 0; i < derived.size(); i++)
            result = result ^ derived[i];

        if(result == 0)
            return true;

        return false;
    }
};