class Solution {
public:
    long long ans = 0;
    void helper(vector<vector<int>>& adj,vector<int>& vis , vector<int>& p , int sr){
        if(vis[sr] == true){
            return;
        }

        vis[sr] = true;
        ans+=1LL*(adj[sr].size()*p[sr]);
        for(int i = 0;i<adj[sr].size();i++){
            ans+=1LL*p[adj[sr][i]];
            helper(adj,vis,p,adj[sr][i]);
        }
        return;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> vis(n , false);
        vector<vector<int>>adj(n);
        for(int i = 0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int>points(n);
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            pq.push({adj[i].size() , i});
        }
        int count = n;
        while(pq.size()>0){
            auto it = pq.top();
            pq.pop();
            points[it.second] = count;
            count--;
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == false){
                helper(adj,vis,points,i);
            }
        }

        return (ans/2);
    }
};