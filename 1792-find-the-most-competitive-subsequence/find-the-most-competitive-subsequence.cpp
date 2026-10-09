class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>s;
        if(k>n){
            return nums;
        }
        for(int i = 0;i<n;i++){
            while(!s.empty() && s.back()>nums[i] && s.size()+(n-i)>k){
                    s.pop_back();
                }
                s.push_back(nums[i]);
        }


        s.resize(k);
        return s;
    }
};