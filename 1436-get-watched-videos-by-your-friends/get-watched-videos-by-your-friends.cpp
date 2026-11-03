class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& wV,
        vector<vector<int>>& fd,
        int id,
        int level
    ) {
        int n = fd.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(id);
        vis[id] = true;
        int count = 0;
        unordered_map<string, int> m;
        while (!q.empty()) {
            int sz = q.size();
            if (count == level) {
                while (!q.empty()) {
                    int val = q.front();
                    q.pop();

                    for (string& video : wV[val]) {
                        m[video]++;
                    }
                }
                break;
            }
            while (sz--) {
                int val = q.front();
                q.pop();
                for (int next : fd[val]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            count++;
        }
        vector<pair<string, int>> temp(m.begin(), m.end());
        sort(temp.begin(), temp.end(),
            [](const auto& a, const auto& b) {
                if (a.second != b.second)
                    return a.second < b.second;

                return a.first < b.first;
            }
        );
        vector<string> ans;
        for (auto& p : temp) {
            ans.push_back(p.first);
        }
        return ans;
    }
};