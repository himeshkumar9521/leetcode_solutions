class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int ans = INT_MIN;
        int st = 0;
        int cT = 0, cF = 0;
        for (int end = 0; end < n; end++) {
            if (answerKey[end] == 'T') {
                cT++;
            } else {
                cF++;
            }
            while (st < n && cT > k && cF > k) {
                if (answerKey[st] == 'T') {
                    cT--;
                } else {
                    cF--;
                }
                st++;
            }

            if (cF <= k || cT <= k) {
                ans = max(ans, (end - st + 1));
            }
        }
        return ans;
    }
};