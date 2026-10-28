class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin() , nums.end(),0);
        long long curr = 0;
        for(int i = 0;i<n;i++){
            curr+=1LL*(i*nums[i]);
        }
        long long ans = curr;
        for(int i = n-1;i>0;i--){
            curr = curr + 1LL*total-1LL*nums[i]*n;
            ans = max(curr , ans);
        }

        return int(ans);

        return ans;

    }
};