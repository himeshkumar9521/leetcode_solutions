class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int j = i;
                int k = i;
                while(j<n-1 && arr[j]>arr[j+1]){
                    j++;
                }
                while(k>=1 && arr[k]>arr[k-1]){
                    k--;
                }
                ans = max(ans , (j-k+1));
                i = j;
            }
        }

        return ans;
    }
};