class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        unordered_set<int> onlyInNums2;
        for(int i : nums1)
            onlyInNums1.insert(i);

        for(int i : nums2)
            onlyInNums2.insert(i);

        for(int i: nums1)
        {
            if(onlyInNums2.find(i) != onlyInNums2.end())
            {
                onlyInNums1.erase(i);
                onlyInNums2.erase(i);
            }
        }

        return {vector<int>{onlyInNums1.begin(), onlyInNums1.end()}, vector<int>{onlyInNums2.begin(), onlyInNums2.end()}};
    }
};