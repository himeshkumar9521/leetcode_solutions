class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int st = 0;
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0;i<n;i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        int k;
        while(s.size()>0){
            k = *s.begin();
            int count = 0;
            while(s.count(k)){
                s.erase(k);
                count++;
                k = nums[k];
            }

            ans = max(ans , count);
        }
        return ans;
    }
};