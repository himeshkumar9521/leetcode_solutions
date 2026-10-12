class Solution {
public:
    bool helper(vector<int>& b, int m, int k, int mid) {
        int count = 0, ans = 0;
        for (int i = 0; i < b.size(); i++) {
            if (mid >= b[i]) {
                count++;
                if (count == k) {
                    ans++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return (ans >= m) ? true : false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int st = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        if (1LL * m * k > n) {
            return -1;
        }
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (helper(bloomDay, m, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};