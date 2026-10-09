class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        int n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        int temp = m.size();
        unordered_set<char> set;
        for (int i = 0; i < n; i++) {
            if (m[s[i]] == 1)
                m.erase(s[i]);
            else
                m[s[i]]--;

            if(set.count(s[i])){
                continue;
            }
            while (!ans.empty() && ans.back() > s[i] && m.count(ans.back())) {
                set.erase(ans.back());
                ans.pop_back();
            }
            ans.push_back(s[i]);
            // if (m[s[i]] == 1) {
            //     m.erase(s[i]);
            // } else {
            //     m[s[i]]--;
            // }
            set.insert(s[i]);
        }

        return ans;
    }
};