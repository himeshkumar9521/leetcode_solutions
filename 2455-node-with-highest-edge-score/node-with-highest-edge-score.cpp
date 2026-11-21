class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> ans(n,0);
        for(int i = 0;i<n;i++){
            ans[edges[i]]+=1LL*i;
        }
        long long high = *max_element(ans.begin() , ans.end());
        for(int i = 0;i<n;i++){
            if(ans[i] == high){
                return i;
            }
        }
        return 0;

    }
};