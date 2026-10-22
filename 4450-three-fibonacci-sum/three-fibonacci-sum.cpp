class Solution {
public:
    bool threeFibonacciSum(int n) {
        int pp = 0,p = 1;
        int ans = 1;
        while(ans<=n){
            if(ans + p + pp == n){
                return true;
            }
            pp = p;
            p = ans;
            ans = p + pp;
        }

        return false;
    }
};