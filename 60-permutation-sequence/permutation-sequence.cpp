
class Solution {
public:
    bool helper(int n, string& temp, vector<bool>& used,
                int& k, string& ans) {

        if (temp.size() == n) {
            k--;

            if (k == 0) {
                ans = temp;
                return true;
            }

            return false;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(i + '0');

            if (helper(n, temp, used, k, ans))
                return true;

            temp.pop_back();
            used[i] = false;
        }

        return false;
    }

    string getPermutation(int n, int k) {
        string temp = "";
        string ans = "";

        vector<bool> used(n + 1, false);

        helper(n, temp, used, k, ans);

        return ans;
    }
};
