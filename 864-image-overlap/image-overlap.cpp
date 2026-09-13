class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>>ones1,ones2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(img1[i][j] == 1){ones1.push_back({i,j});}
                if(img2[i][j] == 1){ones2.push_back({i,j});}
            }
        }

        unordered_map<string,int> m;
        int ans = 0;

        for(auto [x1,y1] : ones1){
            for(auto [x2,y2] : ones2){
                int dx = x2-x1;
                int dy = y2-y1;

                string key = to_string(dx) + "," + to_string(dy);
                ans = max(ans , ++m[key]);
            }
        }

        return ans;
    }
};