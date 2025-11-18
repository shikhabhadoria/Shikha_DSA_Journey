class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj , vector<int> &visited){
        visited[node] = 1;
        for(int i = 0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i] , adj , visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected[0].size();
        vector<vector<int>> adj(V);
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(V , 0);
        int count = 0;
        for(int i = 0; i<V; i++){
            if(visited[i] != 1){
                count++;
                dfs(i , adj , visited);
            }
        }

        return count;
    }
};