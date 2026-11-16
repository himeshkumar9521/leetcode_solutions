class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        if(n<=k){
            return s;
        }
        string temp;
        while(1){
            int count  = 1;
            int val = 0;
            for(int i = 0;i<s.size();i++){
                val += (s[i]-'0');
                if(count == k){
                    temp+=to_string(val);
                    val = 0;
                    count = 1;
                }else{
                    count++;
                }
            }
            if(s.size()%k!=0){
                temp+=to_string(val);
            }
            if(temp.size()<=k){
                return temp;
            }else{
                s = temp;
                temp.clear();
            }
        }

        return "";
    }
};