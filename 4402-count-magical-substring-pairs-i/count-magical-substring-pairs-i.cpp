class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        string temp = s;
        int ans = 0;
        for (int j = 0; j < n - 1; j++) {
            int cnt[27] = {0};
            unordered_set<char> st;

            for (int i = j; i >= 0; i--) {
                st.insert(temp[i]);
                cnt[st.size()]++;
            }
            st.clear();
            for (int k = j + 1; k < n; k++) {
                st.insert(temp[k]);
                ans += cnt[st.size()];
            }
        }
        return ans;
    }
};