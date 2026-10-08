class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        vector<int> rem(k, 0);

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                int x = ((2LL * nums[j]) % k + k) % k;
                rem[x] = 1;

                int r = (sum % k + k) % k;

                if (r == 0 || rem[r]) {
                    ans = max(ans, j - i + 1);
                }
            }

            fill(rem.begin(), rem.end(), 0);
        }

        return ans;
    }
};