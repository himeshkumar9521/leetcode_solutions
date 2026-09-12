class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        long long ans = 0;
        if(n<=1){return 0;}
        vector<long long> LAll(n+1,0);
        vector<long long> TAll(n+1,0);
        for(int i = 1;i<=n;i++){
            LAll[i] = LAll[i-1];
            if(s[i-1] == 'L'){
                LAll[i]++;
            }
        }
        for(int i = n-1;i>=0;i--){
            TAll[i] = TAll[i+1];
            if(s[i] == 'T'){
                TAll[i]++;
            }
        }
        long long L = 0;
        long long LC = 0;
        for(char ch : s){
            if(ch == 'L'){
                L++;
            }else if(ch == 'C'){
                LC+=L;
            }else if(ch == 'T'){
                ans+=LC;
            }
        }

        long long gainL = 0;
        long long cntC = 0;
        for(char ch : s){
            if(ch == 'C'){
                cntC++;
            }else if(ch == 'T'){
                gainL+=cntC;
            }
        }

        long long gainT = LC;
        long long gainC = 0;
        for(int i = 0;i<=n;i++){
            gainC = max(gainC , (LAll[i]*TAll[i]));
        }

        ans+=max({gainC,gainL,gainT});
        return ans;
    }
};