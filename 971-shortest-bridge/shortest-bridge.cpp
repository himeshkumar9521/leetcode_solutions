class Solution {
public:
    int n;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             queue<pair<int,int>>& q,
             int r, int c) {

        if (r < 0 || r >= n || c < 0 || c >= n)
            return;

        if (grid[r][c] == 0 || vis[r][c])
            return;

        vis[r][c] = true;

        q.push({r, c});
        for (int k = 0; k < 4; k++) {
            dfs(grid, vis, q,
                r + dr[k],
                c + dc[k]);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> vis(
            n, vector<bool>(n, false)
        );

        queue<pair<int,int>> q;
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    dfs(grid, vis, q, i, j);
                    found = true;
                    break;
                }
            }
        }

        int distance = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n ||
                        vis[nr][nc])
                        continue;
                    if (grid[nr][nc] == 1)
                        return distance;
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            distance++;
        }
        return -1;
    }
};