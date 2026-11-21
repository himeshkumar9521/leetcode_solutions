
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> lastSeen;

    void dfs(int node, vector<int>& parent, string& s) {
        int ch = s[node] - 'a';
        int previous = lastSeen[ch];
        lastSeen[ch] = node;
        for (int child : adj[node]) {
            dfs(child, parent, s);
        }
        lastSeen[ch] = previous;
        if (node != 0) {
            if (previous != -1) {
                parent[node] = previous;
            }
            ans[parent[node]] += ans[node];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        ans.assign(n, 1);
        lastSeen.assign(26, -1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(0, parent, s);
        return ans;
    }
};
