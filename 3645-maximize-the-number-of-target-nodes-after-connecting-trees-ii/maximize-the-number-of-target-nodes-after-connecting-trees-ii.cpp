class Solution {
public:
int dfs(int i, unordered_map<int, vector<int>>& Graph, vector<bool>& visited, int k, vector<int>& color)
{
    

    visited[i] = true;
    color[i] = k % 2;

    
    int count = 0;
    for(int edge : Graph[i])
    {
        if(!visited[edge])
        {
            count += dfs(edge, Graph, visited, k+1, color);
        }
    }

    if(k % 2 == 0)
        return count + 1;
    else return count;

    
}

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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
        vector<bool> visited(totalNodesInGraph1, false);
        vector<int> color(totalNodesInGraph1, 0);
        int Graph1EvenCount = dfs(0, FirstGraph, visited, 0, color);
        int Graph1OddCount = totalNodesInGraph1 - Graph1EvenCount;

        int totalNodesInGraph2 = SecondGraph.size();
        vector<bool> visited2(totalNodesInGraph2, false);
        vector<int> color2(totalNodesInGraph2, 0);
        int Graph2EvenCount = dfs(0, SecondGraph, visited2, 0, color2);
        int Graph2OddCount = totalNodesInGraph2 - Graph2EvenCount;
        int Graph2MaxConnectedNodes = max(Graph2EvenCount, Graph2OddCount);

        vector<int> res(totalNodesInGraph1, 0);
        for (int i = 0; i < totalNodesInGraph1; i++) {
            if(color[i] % 2 == 0)
                res[i] = Graph1EvenCount + Graph2MaxConnectedNodes;
            else
                res[i] = Graph1OddCount + Graph2MaxConnectedNodes;
        }

        return res;
    }
};