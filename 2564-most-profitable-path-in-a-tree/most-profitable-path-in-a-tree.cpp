
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, bobTime;
    int ans = INT_MIN;

    void findParent(int node, int par) {
        parent[node] = par;

        for (int nei : adj[node]) {
            if (nei != par) {
                findParent(nei, node);
            }
        }
    }

    void dfsAlice(int node, int par, int time,
                  int profit, vector<int>& amount) {

        if (time < bobTime[node]) {
            profit += amount[node];
        } 
        else if (time == bobTime[node]) {
            profit += amount[node] / 2;
        }
        if (node != 0 && adj[node].size() == 1) {
            ans = max(ans, profit);
            return;
        }

        for (int nei : adj[node]) {
            if (nei != par) {
                dfsAlice(nei, node, time + 1,
                         profit, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges,
                           int bob, vector<int>& amount) {
        int n = amount.size();

        adj.assign(n, {});
        parent.assign(n, -1);
        bobTime.assign(n, n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        findParent(0, -1);
        int node = bob;
        int time = 0;
        while (node != -1) {
            bobTime[node] = time++;
            node = parent[node];
        }
        dfsAlice(0, -1, 0, 0, amount);

        return ans;
    }
};
