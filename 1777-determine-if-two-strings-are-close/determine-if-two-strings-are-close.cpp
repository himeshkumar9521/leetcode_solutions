class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n!=m){
            return false;
        }
        unordered_map<char,int> m1,m2;
        for(int i = 0;i<n;i++){
            m1[word1[i]]++;
        }
        for(int i = 0;i<m;i++){
            m2[word2[i]]++;
        }
        if(m1.size() != m2.size()){return false;}
        map<int,int> m3,m4;
        for(auto&v:m1){
            m3[v.second]++;
        }
        for(auto&v:m2){
            m4[v.second]++;
        }
        for (auto& v : m1) {
            if (m2.find(v.first) == m2.end()) {
                return false;
            }
        }
        if(m3!=m4){return false;}
        return true;
    }
};