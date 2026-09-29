class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());

        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            int temp = 0;
            int time = 1;
            for(int j = i;j<n;j++){
                temp+=(time*satisfaction[j]);
                time++;
            }
            ans = max(temp , ans);
        }

        if(ans<0){return 0;}
        else{
            return ans;
        }
    }
};