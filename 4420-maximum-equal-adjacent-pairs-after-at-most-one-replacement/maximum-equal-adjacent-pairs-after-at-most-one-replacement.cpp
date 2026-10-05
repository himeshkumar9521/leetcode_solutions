class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int> , int> m;
        int total = 0;
        int temp = 0;
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                total++;
            }else{
                int u = min(nums[i] , nums[i+1]);
                int v=  max(nums[i] , nums[i+1]);

                m[{u,v}]++;
                if(m[{u,v}]>temp){
                    temp = m[{u,v}];
                }
            }
        }

        return (total+temp);
    }
};