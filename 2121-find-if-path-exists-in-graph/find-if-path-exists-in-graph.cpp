class Solution {
public:
    bool ans = false;
    void helper(vector<vector<int>>& adj , int source, int destination , vector<bool>& vis){
        if(source == destination){
            ans = true;
            return;
        }
        if(vis[source] == true){
            return;
        }
        vis[source] = true;
        for(int i = 0;i<adj[source].size();i++){
            helper(adj , adj[source][i] , destination,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool> vis(n,false);
        int m = edges.size();
        for(int i = 0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        helper(adj,source,destination,vis);
        return ans;
    }
};