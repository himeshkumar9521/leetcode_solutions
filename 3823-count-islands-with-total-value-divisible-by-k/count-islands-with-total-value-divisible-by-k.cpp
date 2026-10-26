class Solution {
public:
    long long helper(vector<vector<int>>& grid , vector<vector<bool>>& vis, int i , int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j] == 0 || vis[i][j] == true){
            return 0;
        }
        vis[i][j] = true;
        long long a = helper(grid,vis,i,j+1);
        long long b = helper(grid,vis,i,j-1);
        long long c = helper(grid,vis,i+1,j);
        long long d = helper(grid,vis,i-1,j);

        return (a+b+c+d+1LL*grid[i][j]);

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0 && vis[i][j] == false){
                    long long val = helper(grid,vis,i,j);
                    if(val%k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};