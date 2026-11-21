class Solution {
public:
    int ans = INT_MIN;
    void helper(int node , vector<vector<int>>& adj , vector<bool>& vis , vector<int>& val,int k){
        if(vis[node] == true){
            return;
        }
        vis[node] = true;
        priority_queue<int> pq;
        for(int i = 0;i<adj[node].size();i++){
            pq.push(val[adj[node][i]]);
            helper(adj[node][i] , adj,vis,val,k);
        }
        int temp = val[node];
        while(pq.size()>0 && k>0){
            ans = max(ans , temp);
            temp+=pq.top();
            pq.pop();
            k--;
        }
        ans = max(ans , temp);
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        if(k == 0){
            return *max_element(vals.begin() , vals.end());
        }
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                helper(i,adj,vis,vals,k);
            }
        }
        return ans;
    }
};