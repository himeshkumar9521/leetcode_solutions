class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0;
        long long even = 0;
        long long ans = 0;
        for (int x : arr) {
            if (x % 2 != 0) {
                long long newOdd = even + 1;
                long long newEven = odd;
                odd = newOdd;
                even = newEven;
            } 
            else {
                odd = odd;
                even = even + 1;
            }
            odd %= MOD;
            even %= MOD;
            ans = (ans + odd) % MOD;
        }
        return ans;
    }
};