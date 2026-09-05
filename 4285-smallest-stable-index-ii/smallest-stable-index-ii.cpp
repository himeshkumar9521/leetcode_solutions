class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> low(n,INT_MAX);
        low[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            low[i] = min(nums[i] , low[i+1]);
        }
        int high = INT_MIN;
        for(int i = 0;i<n;i++){
            high = max(high , nums[i]);
            if((high-low[i])<=k){
                return i;
            }
        }

        return -1;

    }
};