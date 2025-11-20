class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int , int>> q;
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
        vector<vector<int>> v = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
        int timer = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 0; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int j = 0; j<4; j++){
                    int dx = x + v[j][0];
                    int dy = y + v[j][1];

                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1){
                            q.push({dx , dy});
                            grid[dx][dy] = 2;
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