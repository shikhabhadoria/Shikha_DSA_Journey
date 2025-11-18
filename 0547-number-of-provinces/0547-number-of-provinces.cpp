class Solution {
public:
    void bfs(int node , vector<vector<int>> &adj , vector<int> &visited){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]] = 1;
                    q.push(adj[node][i]);
                }
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
                bfs(i , adj , visited);
            }
        }

        return count;
    }
};