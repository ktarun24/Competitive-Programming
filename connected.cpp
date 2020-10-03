//https://leetcode.com/problems/number-of-operations-to-make-network-connected/



//Question : 1319. Number of Operations to Make Network Connected


class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int i)
    {
        if(visited[i])
        {
            return ;
        }
        visited[i] = 1;
        for(auto x : graph[i])
        {
            dfs(graph, visited, x);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        for(auto& i : connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(n);
        
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(graph, visited, i);
                answer++;
            }
        }
        if(connections.size() >= n - 1)
        {
            return answer - 1;
        }
        else
        {
            return -1;
        }
    }
};
