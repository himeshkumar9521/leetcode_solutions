class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        map<pair<int,int> , int> m;
        int count = 0;
        for(int i = 0;i<n;i++){
            int st = i+1;
            int end = n-1;
            int val = INT_MAX;
            while(st<=end){
                int mid = st+(end-st)/2;
                if(nums[mid] == (k+nums[i])){
                    val = nums[mid];
                    break;
                }else if(nums[mid]<(k+nums[i])){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
            st = i+1,end = n-1;
            while(val == INT_MAX && st<=end){
                int mid = st+(end-st)/2;
                if(nums[mid] == (nums[i]-k)){
                    val = nums[mid];
                    break;
                }else if(nums[mid]<(nums[i]-k)){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
            if(val == INT_MAX){continue;}
            if(!m.count({nums[i] , val})){
                count++;
                m[{nums[i] , val}] = 1;
            }
        }

        return count;
    }
};