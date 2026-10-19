class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int high = accumulate(nums.begin() , nums.end() , 0);
        return high%k;
    }
};