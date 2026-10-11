class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int st = 0,n = arr.size(),end = 0;
        vector<int> nums = arr;
        nums.insert(nums.end() , arr.begin() , arr.end());
        int total = accumulate(arr.begin() , arr.end() , 0);
        int ans = INT_MAX,zeros = 0;
        while(end<2*n){
            if(nums[end] == 0){
                zeros++;
            }
            if((end-st+1)>total){
                if(nums[st] == 0){
                    zeros--;
                }
                st++;
            }
            if((end-st+1) == total){
                ans = min(ans , zeros);
            }
            end++;
        }

        return ans;

    }
};