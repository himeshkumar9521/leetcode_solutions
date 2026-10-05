class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
        }
        while(ans.size()<n){
            for(auto&v : m){
                if(v.second != 0){
                    ans.push_back(v.first);
                    m[v.first]--;
                }
            }
        }

        return ans;
    }
};