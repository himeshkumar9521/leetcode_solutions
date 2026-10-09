class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool temp = false;
        int count = 0;
        for(int& a:nums){
            if(a == 1){count++;}
        }
        if(count>0){
            return n-count;
        }
        int len = INT_MAX;
        for(int i = 0;i<n;i++){
            int curr = nums[i];
            for(int j = i+1;j<n;j++){
                curr = gcd(curr , nums[j]);

                if(curr == 1){
                    len = min(len , (j-i+1));
                }
            }
        }


        if(len != INT_MAX){
            return len+n-2;
        }

        return -1;
    }
};