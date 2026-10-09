class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int count = 1;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i] != s[i+1]){
                if(count%2 == 1){
                    s[i+1] = s[i];
                    ans++;
                    i++;
                }
                count = 1;
            }else{
                count++;
            }
        }

        return ans;
    }
};