class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        int ans = -1;
        int v = INT_MAX;
        for (int i = 0; i < n; i++) {
            double v1 = preSum[i] / (i + 1);
            double v2 = 0;
            if (i != n - 1) {
                v2 = (preSum[n - 1] - preSum[i]) / (n - i - 1);
            }
            double diff = abs(v1 - v2);
            diff = round(diff);
            if (diff < v) {
                ans = i;
                v = diff;
            }
        }

        return ans;
    }
};