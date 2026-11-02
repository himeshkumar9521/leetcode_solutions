
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<string> st;
        int i = 0;
        while(i < n) {
            if(s[i] == ' ') {
                i++;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9') {
                string temp;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    temp.push_back(s[i]);
                    i++;
                }
                st.push(temp);
            }
            else if(s[i] == '+' || s[i] == '-') {
                st.push(string(1, s[i]));
                i++;
            }
            else {
                char op = s[i];
                i++;
                while(i < n && s[i] == ' ') {
                    i++;
                }
                string temp;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    temp.push_back(s[i]);
                    i++;
                }
                int v1 = stoi(st.top());
                st.pop();
                int v2 = stoi(temp);
                if(op == '/') {
                    st.push(to_string(v1 / v2));
                }
                else {
                    st.push(to_string(v1 * v2));
                }
            }
        }
        stack<string> rev;
        while(!st.empty()) {
            rev.push(st.top());
            st.pop();
        }
        int ans = stoi(rev.top());
        rev.pop();
        while(!rev.empty()) {
            string op = rev.top();
            rev.pop();
            int num = stoi(rev.top());
            rev.pop();
            if(op == "+") {
                ans += num;
            }
            else {
                ans -= num;
            }
        }
        return ans;
    }
};
