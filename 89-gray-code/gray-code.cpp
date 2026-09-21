class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1;i<pow(2,n);i++){
            int val = i^(i>>1);
            ans.push_back(val);
        }

        return ans;
    }
};