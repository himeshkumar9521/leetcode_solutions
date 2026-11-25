class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int ans = 0;

        for (int count : freq) {
            if (count == 0) continue;

            ans += (count % 2 == 0) ? 2 : 1;
        }

        return ans;
    }
};