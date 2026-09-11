class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp = nums;
        temp.insert(temp.end(),nums.begin() , nums.end());
        long long leftSum  = 0;
        long long rightSum = 0;
        int rightst = 0;
        int i;
        for(i = 0;i<(n/2);i++){
            leftSum+=(1LL*nums[i]);
        }
        rightst = i;
        rightSum = accumulate(nums.begin() , nums.end(),0LL) - leftSum;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(leftSum > rightSum){
                ans++;
            }
            rightSum = rightSum + 1LL*(temp[i])-1LL*(temp[rightst]);
            leftSum=leftSum - 1LL*(temp[i]) + 1LL*(temp[rightst]);
            rightst++;
        }

        return ans;
    }
};