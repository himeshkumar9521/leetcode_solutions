class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 1){
                continue;
            }
            for(int j = 0;j<m;j++){
                (grid[i][j] == 0)?grid[i][j] = 1 : grid[i][j] = 0;
            }
        }
        for(int i = 0;i<m;i++){
            int total = 0;
            for(int j = 0;j<n;j++){
                total+=grid[j][i];
            }
            if(total*2>=n){continue;}
            for(int j = 0;j<n;j++){
                (grid[j][i] == 0)?grid[j][i] = 1 : grid[j][i] = 0;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int t = 0;
            int val = 0;
            for(int j = m-1;j>=0;j--){
                val+=(pow(2,t)*grid[i][j]);
                t++;
            }
            ans+=val;
        }
        return ans;
    }
};