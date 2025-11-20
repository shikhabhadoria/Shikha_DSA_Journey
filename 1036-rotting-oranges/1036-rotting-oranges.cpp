class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>> q;
        int fresh = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        int timer = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int p = 0; p<size; p++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i-1 >= 0 && j < n){
                    if(grid[i-1][j] == 1){
                        q.push({i-1 , j});
                        grid[i-1][j] = 2;
                        flag = true;
                    }
                }

                if(i < m && j+1 < n){
                    if(grid[i][j+1] == 1){
                        q.push({i , j+1});
                        grid[i][j+1] = 2;
                        flag = true;
                    }
                }

                if(i+1 < m && j < n){
                    if(grid[i+1][j] == 1){
                        q.push({i+1 , j});
                        grid[i+1][j] = 2;
                        flag = true;
                    }
                }

                if(i < m && j-1 >= 0){
                    if(grid[i][j-1] == 1){
                        q.push({i , j-1});
                        grid[i][j-1] = 2;
                        flag = true;
                    }
                }
            }
            if(flag == true) timer++;
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return timer;
    }
};