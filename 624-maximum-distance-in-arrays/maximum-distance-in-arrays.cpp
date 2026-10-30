class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        vector<int> high(n);
        high[n-1] = arrays[n-1].back();
        for(int i = n-2;i>=0;i--){
            high[i] = max(high[i+1] , arrays[i].back());
        }
        int temp = arrays[0].back();
        int ans = abs(high[1]-arrays[0][0]);
        int i = 1;
        for(i;i<n-1;i++){
            int val1 = abs(arrays[i][0]-high[i+1]);
            int val2 = abs(arrays[i][0]-temp);
            ans = max({ans,val1,val2});
            temp = max(temp , arrays[i].back());
        }
        ans = max(ans , abs(temp-arrays[i][0]));
        return ans;
    }
};