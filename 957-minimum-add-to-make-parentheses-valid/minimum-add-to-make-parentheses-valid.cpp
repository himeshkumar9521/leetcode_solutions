class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;){
            if(s[i] == '('){
                st.push(s[i]);
                i++;
            }else{
                while(st.size()>0 && i<n && s[i] == ')'){
                    st.pop();
                    i++;
                }
                while(i<n && s[i] == ')'){
                    ans++;
                    i++;
                }
            }
        }

        return st.size() +ans;
    }
};