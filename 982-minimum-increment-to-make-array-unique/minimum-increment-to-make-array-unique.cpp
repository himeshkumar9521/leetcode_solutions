class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 0;
        int next = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<next){
                ans+=(next-nums[i]);
            }else{
                next = nums[i];
            }

            next++;
        }

        return ans;
    }
};