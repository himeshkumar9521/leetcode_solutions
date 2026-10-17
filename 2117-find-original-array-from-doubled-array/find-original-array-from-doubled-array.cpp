class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        sort(ch.begin() , ch.end());
        unordered_map<int,vector<int>> m;
        int n = ch.size();
        if(n%2 == 1){
            return {};
        }
        for(int i = n-1;i>=0;i--){
            m[ch[i]].push_back(i);
        }
        unordered_set<int> s;
        vector<int> ans;
        if(m.count(0)){
            if(m[0].size()%2 == 1){return {};}
            else{
                int v = m[0].size()/2;
                while(v>0){
                    ans.push_back(0);
                    v--;
                }
                m.erase(0);
            }
        }
        for(int i = 0;i<n;i++){
            if(s.count(i) || ch[i] == 0){
                continue;
            }
            if(m.count(ch[i]*2)){
                ans.push_back(ch[i]);
                s.insert(i);
                int v = m[ch[i]*2].back();
                m[ch[i]*2].pop_back();
                if(m[ch[i]*2].size() == 0){
                    m.erase(ch[i]*2);
                }
                s.insert(v);
            }else{
                return {};
            }
        }

        return ans;
    }
};