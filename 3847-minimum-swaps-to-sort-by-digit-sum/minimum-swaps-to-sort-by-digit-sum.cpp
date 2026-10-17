class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dSum;
        for(int i = 0;i<n;i++){
            int val = nums[i];
            int sum = 0;
            while(val>0){
                sum+=(val%10);
                val/=10;
            }
            dSum.push_back({sum,i});
        }
        sort(dSum.begin() , dSum.end() , [&nums](auto a , auto b){
            if(a.first == b.first){
                return nums[a.second]<nums[b.second];
            }else{
                return a.first < b.first;
            }
        });
        int ans = 0;
        unordered_set<int> s;
        for(int i = 0;i<n;i++){
            if(s.count(i)){continue;}
            auto it = dSum[i];
            int count = 0;
            if(it.second == i){
                continue;
            }
            int j = i;
            while(!s.count(j)){
                s.insert(j);
                j = dSum[j].second;
                count++;
            }

            ans+=(count-1);
        }

        return ans;
    }
};