class Solution {
public:
    void helper(vector<vector<int>>& adj, vector<bool>& vis, int source) {
        if (vis[source] == true) {
            return;
        }
        vis[source] = true;
        for (int i = 0; i < adj[source].size(); i++) {
            helper(adj, vis, adj[source][i]);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for (auto edge : edges) {
            vis[edge[1]] = true;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                ans.push_back(i);
                helper(adj, vis, i);
            }
        }

        return ans;
    }
};