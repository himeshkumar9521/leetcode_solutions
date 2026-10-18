class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int high = INT_MIN, low = INT_MAX;
            for (int j = i; j < n; j++) {
                high = max(high, nums[j]);
                low = min(low, nums[j]);
                ans += 1LL * (high - low);
            }
        }

        return ans;
    }
};