class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        vector<int> ans(m);
        unordered_map<int, int> server_counts;
        int left = 0;
        int right = 0;
        int num_logs = logs.size();
        for (int i = 0; i < m; i++) {
            int current_time = sorted_queries[i].first;
            int original_index = sorted_queries[i].second;            
            while (right < num_logs && logs[right][1] <= current_time) {
                server_counts[logs[right][0]]++;
                right++;
            }            
            while (left < num_logs && logs[left][1] < current_time - x) {
                server_counts[logs[left][0]]--;
                if (server_counts[logs[left][0]] == 0) {
                    server_counts.erase(logs[left][0]);
                }
                left++;
            }
            ans[original_index] = n - server_counts.size();
        }        
        return ans;
    }
};