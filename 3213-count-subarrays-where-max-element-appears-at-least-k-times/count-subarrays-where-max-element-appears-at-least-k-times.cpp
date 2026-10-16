class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0;
        long long ans = 0;
        int count = 0;
        int high = *max_element(nums.begin() , nums.end());
        for(int end = 0;end<n;end++){
            if(nums[end] == high){
                count++;
            }

            while(st<n && count>=k){
                ans+=1LL*(n-end);
                if(nums[st] == high){
                    count--;
                }
                st++;
            }
        }

        return ans;
    }
};