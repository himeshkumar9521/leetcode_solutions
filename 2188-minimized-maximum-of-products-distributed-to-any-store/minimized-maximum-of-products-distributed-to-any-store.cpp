class Solution {
public:
    bool helper(int mid , int n , long long sum , vector<int>& q){
        if(1LL*mid*n < sum){
            return false;
        }
        int curr = 0;
        for(int i = 0;i<q.size();i++){
            curr+=(q[i]/mid + !(q[i]%mid == 0));
        }

        return curr <= n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int i = 1;
        int j = *max_element(q.begin() , q.end());
        long long sum = accumulate(q.begin() , q.end() ,0LL);
        int ans = 0;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(helper(mid,n,sum,q)){
                ans = mid;
                j =mid-1;
            }else{
                i = mid+1;
            }
        }

        return ans;
    }
};