class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            unordered_set<int> s;
            for(int j = 0;j<adj[i].size();j++){
                s.insert(adj[i][j]);
            }
            for(int j = i+1;j<n;j++){
                int val = adj[i].size() + adj[j].size();
                if(s.count(j)){
                    val--;
                }
                ans = max(ans , val);
            }
        }

        return ans;

        return ans;
    }
};