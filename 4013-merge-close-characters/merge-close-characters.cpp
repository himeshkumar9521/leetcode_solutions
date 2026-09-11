class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        string ans;
        unordered_map<char,int> m;
        for(int i = 0;i<s.size();){
            if(!m.count(s[i])){
                // ans.push_back(s[i]);
                m[s[i]] = i;
                i++;
            }else{
                if(abs(i-m[s[i]])<=k){
                    // ans.push_back(s[i]);
                    s.erase(i,1);
                }else{
                    m[s[i]] = i;
                    i++;
                }
                    // m.erase(s[i]);
            }
        }

        return s;
    }
};