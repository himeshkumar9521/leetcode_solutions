class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        map<int,vector<int>> m;
        for(int i = 0;i<n;i++){
            int v1 = points[i][0];
            int v2 = points[i][1];
            int temp = (v1*v1+v2*v2);
            m[temp].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto&v:m){
            vector<int> temp = v.second;
            for(int& j:temp){
                ans.push_back(points[j]);
                k--;
                if(k == 0){
                    return ans;
                }
            }
        }

        return ans;
    }
};