class Solution {
public:
    void helper(vector<vector<int>>& adj , vector<int>& vis , int sr){
        if(vis[sr] == true){
            return;
        }
        vis[sr] = true;
        for(int i = 0;i<adj[sr].size();i++){
            helper(adj,vis,adj[sr][i]);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n,false);
        int br = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] == false){
                br++;
                helper(adj,vis,i);
            }
        }

        if(connections.size()<n-1){
            return -1;
        }else{
            return (br-1);
        }
    }
};