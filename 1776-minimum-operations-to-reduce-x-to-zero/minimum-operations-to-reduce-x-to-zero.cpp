class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int k = sum-x;
        int ans = INT_MAX;
        int st = 0;
        int subSum  = 0;
        for(int end = 0;end<n;end++){
            subSum+=nums[end];
            while(st<=end && subSum>k){
                subSum-=nums[st];
                st++;
            }

            if(subSum == k){
                ans = min(ans , (n-(end-st+1)));
            }
        }

        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
        
    }
};