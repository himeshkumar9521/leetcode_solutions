class Solution {
public:
    long long minimumCost(int c1, int c2, int cB, int n1, int n2) {
        long long ans = 0;
        int temp = c1+c2;
        if(temp>=cB){
            ans+=1LL*cB*min(n1,n2);
            if(n1<n2){
                int v = n2-n1;
                ans+=1LL*min(1LL*v*c2 , 1LL*cB*v);
            }else{
                int v = n1-n2;
                ans+=1LL*min(1LL*v*c1 , 1LL*cB*v);
            }
        }else{
            ans+=1LL*c1*min(n1,n2);
            ans+=1LL*c2*min(n1,n2);
            if(n1<n2){
                int v = n2-n1;
                ans+=1LL*min(1LL*v*c2 , 1LL*cB*v);
            }else{
                int v = n1-n2;
                ans+=1LL*min(1LL*v*c1 , 1LL*cB*v);
            }
        }

        return ans;
    }
};