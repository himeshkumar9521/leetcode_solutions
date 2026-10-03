class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int st = 0;
        int end = n-1;
        while(st<end){
            int mid = st+(end-st)/2;
            if(nums[mid]<nums[mid+1]){
                st = mid+1;
            }else{
                end = mid;
            }
        }

        ans = st;
        return ans;
    }

};