class Solution {
public:
    double helper(string& sr , string& dest , unordered_map<string,vector<pair<string,double>>>& m,
    unordered_set<string>& vis){
        if(sr == dest){
            return 1.0;
        }

        vis.insert(sr);

        for(auto& [a,b] : m[sr]){
            if(vis.count(a)){
                continue;
            }
            double res = helper(a,dest,m,vis);
            if(res != -1.0){
                return b*res;
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) {
        int n = eq.size();
        unordered_map<string,vector<pair<string,double>>> m;
        for(int i = 0;i<n;i++){
            m[eq[i][0]].push_back({eq[i][1] , val[i]});
            m[eq[i][1]].push_back({eq[i][0] , 1.0/val[i]});
        }
        vector<double> ans;
        for(auto&q:queries){
            string sr = q[0];
            string dest = q[1];

            if(!m.count(sr) || !m.count(dest)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(helper(sr,dest,m,vis));
        }

        return ans;
    }
};