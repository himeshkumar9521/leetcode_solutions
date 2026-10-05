class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;
        int run = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                run++;
            }else{
                run--;
                if(s[i-1] == '('){
                    ans+=1 << run;
                }
            }
        }

        return ans;
    }
};