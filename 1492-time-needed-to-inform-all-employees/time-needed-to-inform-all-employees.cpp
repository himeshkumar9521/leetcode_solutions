class Solution {
public:
    int ans = 0;

    void helper(vector<vector<int>>& children,
                vector<int>& time,
                int sr,
                int count) {

        count += time[sr];

        if (children[sr].empty()) {
            ans = max(ans, count);
            return;
        }

        for (int employee : children[sr]) {
            helper(children, time, employee, count);
        }
    }

    int numOfMinutes(int n, int headID,
                     vector<int>& manager,
                     vector<int>& informTime) {

        vector<vector<int>> children(n);

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                children[manager[i]].push_back(i);
            }
        }

        helper(children, informTime, headID, 0);

        return ans;
    }
};