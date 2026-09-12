class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        int high = INT_MIN;
        int idx = 0;
        int sec  = 0;
        for(int i = 0;i<n;i++){
            if(high<abs(nums[i])){
                high = abs(nums[i]);
                idx = i;
            }
        }
        for(int i = 0;i<n;i++){
            if(idx == i){
                continue;
            }
            sec = max(abs(nums[i]) , sec);
        }

        long long ans = 1LL*sec*high*100000;

        return ans;
    }
};