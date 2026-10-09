class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int target = nums2[n];

        long long ans = 1;
        int minExtra = INT_MAX;
        bool canAppend = false;

        for (int i = 0; i < n; i++) {
            int a = nums1[i];
            int b = nums2[i];

            ans += abs(a - b);

            int low = min(a, b);
            int high = max(a, b);

            if (target >= low && target <= high) {
                canAppend = true;
            }

            minExtra = min(minExtra,
                           min(abs(a - target),
                               abs(b - target)));
        }

        if (!canAppend) {
            ans += minExtra;
        }

        return ans;
    }
};