class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto& v : m) {
            if (v.second < 2) {
                continue;
            }
            int val = v.second;
            count += (4 * val * (val - 1));
        }

        return count;
    }
};