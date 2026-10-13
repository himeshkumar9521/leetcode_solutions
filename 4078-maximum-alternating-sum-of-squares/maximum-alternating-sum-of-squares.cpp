class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin() , nums.end() , [](int a , int b){
            return abs(a) < abs(b);
        });
        int n = nums.size();
        int mid = n/2;
        int i = 0;
        while(i<mid){
            ans-=1LL*(nums[i]*nums[i]);
            i++;
        }
        while(i<n){
            ans+=1LL*(nums[i]*nums[i]);
            i++;
        }

        return ans;
    }
};