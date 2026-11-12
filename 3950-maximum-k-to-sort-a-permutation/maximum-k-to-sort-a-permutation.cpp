class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] != i){
                ans = nums[i]&ans;
            }
        }
        if(ans == -1){
            return 0;
        }else{
            return ans;
        }
    }
};