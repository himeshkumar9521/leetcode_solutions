class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin() , nums.end());
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int st = j+1;
                int end = n-1;
                while(st<=end){
                    int mid = st + (end-st)/2;
                    int v = nums[i] + nums[j] + nums[mid];
                    if(v<t){
                        st = mid+1;
                    }else{
                        end = mid-1;
                    }
                    if(ans == INT_MAX || abs(t-v)<abs(ans-t)){
                        ans = v;
                    }
                }
            }
        }

        return ans;
    }
};