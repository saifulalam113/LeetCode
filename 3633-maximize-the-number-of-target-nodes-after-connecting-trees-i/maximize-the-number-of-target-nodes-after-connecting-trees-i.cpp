class Solution {
public:
    int dfs(int i, unordered_map<int, vector<int>>& Graph,
            vector<bool>& visited, int k) {

                visited[i] = true;
        if (k < 0)
            return 0;

        if (k == 0) {
            return 1;
        }

        

        int count = 0;
        for (int edge : Graph[i]) {
            if (!visited[edge]) {
                count += dfs(edge, Graph, visited, k - 1);
            }
        }

        return count+1;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> FirstGraph;
        unordered_map<int, vector<int>> SecondGraph;

        for (vector<int>& edge : edges1) {
            FirstGraph[edge[0]].push_back(edge[1]);
            FirstGraph[edge[1]].push_back(edge[0]);
        }

        for (vector<int>& edge : edges2) {
            SecondGraph[edge[0]].push_back(edge[1]);
            SecondGraph[edge[1]].push_back(edge[0]);
        }

        int totalNodesInGraph1 = FirstGraph.size();
        vector<int> MaxTargetNodes1(totalNodesInGraph1, 0);
        for (int i = 0; i < totalNodesInGraph1; i++) {
            int count = 0;
            vector<bool> visited(totalNodesInGraph1, false);
            count += dfs(i, FirstGraph, visited, k);

            MaxTargetNodes1[i] = count;
        }

        int totalNodesInGraph2 = SecondGraph.size();
        vector<int> MaxTargetNodes2(totalNodesInGraph2, 0);
        for (int i = 0; i < totalNodesInGraph2; i++) {
            int count = 0;
            vector<bool> visited(totalNodesInGraph2, false);
            count += dfs(i, SecondGraph, visited, k - 1);

            MaxTargetNodes2[i] = count;
        }

        int iMaxTargetInGraph2 = 0;
        for (int i = 0; i < totalNodesInGraph2; i++) {

            iMaxTargetInGraph2 = max(iMaxTargetInGraph2, MaxTargetNodes2[i]);
        }

        vector<int> res(totalNodesInGraph1, 0);
        for (int i = 0; i < totalNodesInGraph1; i++) {
            res[i] = iMaxTargetInGraph2 + MaxTargetNodes1[i];
        }

        return res;
    }
};