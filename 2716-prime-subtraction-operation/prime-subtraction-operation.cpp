class Solution {
public:
    vector<int> allPrime;
    void SPF(int n){
        allPrime.resize(n+1);

        for(int i = 0;i<=n;i++){
            allPrime[i] = i;
        }

        for(int i = 2;i*i<=n;i++){
            if(i == allPrime[i]){
                for(int j = i*i;j<=n;j+=i){
                    if(allPrime[j] == j){
                        allPrime[j] = i;
                    }
                }
            }
        }


        return;
    }
    // int prime(int a , int limit){
    //     int ans = -1;
    //     while(a>0){
    //         int p = allPrime[a];
    //         if(p>limit){
    //             ans = p;
    //             break;
    //         }

    //         while(a%p == 0){
    //             a/=p;
    //         }
    //     }

    //     return ans;
    // }
    bool primeSubOperation(vector<int>& nums) {
        int high = *max_element(nums.begin() , nums.end());
        SPF(high);
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                int temp = abs(nums[i] - nums[i+1]);
                int val = -1;

                for (int p = max(2,temp + 1); p < nums[i]; p++) {
                    if (allPrime[p] == p) {
                        val = p;
                        break;
                    }
                }

                if (val == -1) {
                    return false;
                }

                nums[i] -= val;
            }
        }

        return true;
    }
};