class Solution {
public:
    int count = 0;
    int helper(vector<vector<pair<int,int>>>& adj , vector<bool>& vis , int sr){
        vis[sr] = true;
        for(int i = 0;i<adj[sr].size();i++){
            int one = adj[sr][i].first;
            int sec = adj[sr][i].second;
            if(vis[one] == false){
                count+=sec;
                helper(adj,vis,one);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<connections.size();i++){
            adj[connections[i][0]].push_back({(connections[i][1]),1});
            adj[connections[i][1]].push_back({(connections[i][0]),0});
        }

        vector<bool> vis(n,false);
        helper(adj,vis,0);

        return count;
    }
};