class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int,vector<int>> m;
        for(int i = 0;i<n;i++){
            m[cards[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &v:m){
            vector<int> part = v.second;
            if(part.size() == 1){
                continue;
            }
            for(int i = 0;i<part.size()-1;i++){
                ans = min(ans , (part[i+1]-part[i]+1));
            }
        }
        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};