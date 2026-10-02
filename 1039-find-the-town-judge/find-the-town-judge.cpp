class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1){return n;}
        unordered_map<int,unordered_set<int>> m;
        for(int i = 0;i<trust.size();i++){
            m[trust[i][0]].insert(trust[i][1]);
        }
        for(int i = 1;i<=n;i++){
            if(!m.count(i)){
                m[i] = {};
            }
        }
        for(auto & v : m){
            int val = v.first;
            if(m[val].size() == 0){
                int count = 0;
                for(auto& w: m){
                    int part = w.first;
                    if(m[part].count(val)){
                        count++;
                    }
                }

                if(count == n-1){
                    return val;
                }
            }
        }

        return -1;
    }
};