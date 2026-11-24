class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            long long pro = 1;
            int G =nums[i],L = nums[i];
            for(int j = i;j<n;j++){
                pro*=1LL*nums[j];
                G = gcd(G,nums[j]);
                L = lcm(L,nums[j]);
                long long val = 1LL*G*L;
                if(pro>=2520*G*L){
                    break;
                }
                if(pro == val){
                    count = max(count , (j-i+1));
                }
            }
        }

        return count;
    }
};