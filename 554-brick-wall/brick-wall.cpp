class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int> m;
        int n = wall.size();
        int flag = 0;
        for(int i = 0;i<n;i++){
            long long count = 0;
            if(wall[i].size()>1){
                flag = 1;
            }
            for(int j = 0;j<wall[i].size()-1;j++){
                count = count+1LL*wall[i][j];
                m[count]++;
            }
        }
        if(flag == 0){
            return n;
        }
        int ans = 0;
        for(auto&v:m){
            ans = max(ans , v.second);
        }

        return (n-ans);
    }
};