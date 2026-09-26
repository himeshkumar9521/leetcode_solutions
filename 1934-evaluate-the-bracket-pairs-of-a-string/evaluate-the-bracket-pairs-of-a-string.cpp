class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        int n = s.size();
        for(int i = 0;i<knowledge.size();i++){
            m[knowledge[i][0]] = knowledge[i][1];
        }
        int i = 0;
        string ans = "";
        while(i<n){
            if(s[i] == '('){
                string temp = "";
                i++;
                while(i<n && s[i]!= ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                if(m.count(temp)){
                    ans+=m[temp];
                }else{
                    ans.push_back('?');
                }
            }else{
                ans.push_back(s[i]);
            }
            i++;
        }

        return ans;
    }
};