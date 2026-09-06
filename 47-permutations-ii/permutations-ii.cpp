class Solution {
public:
    void helper(vector<int>& nums , vector<vector<int>>& ans , vector<int>& temp , map<vector<int>,int>& m , unordered_set<int> s){
        if(nums.size() == temp.size()){
            if(!m.count(temp)){
                ans.push_back(temp);
                m[temp]++;
            }
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(s.count(i)){
                continue;
            }
            temp.push_back(nums[i]);
            s.insert(i);
            helper(nums,ans,temp,m,s);
            temp.pop_back();
            s.erase(i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>,int> m;
        vector<int> temp;
        vector<vector<int>> ans;
        unordered_set<int> s;
        helper(nums,ans,temp,m,s);

        return ans;
    }
};