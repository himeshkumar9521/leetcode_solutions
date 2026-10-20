class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int end = n-1;
        while(st+1<n && arr[st]<=arr[st+1]){
            st++;
        }
        if(st == n-1){return 0;}
        while(end>0 && arr[end-1]<=arr[end]){
            end--;
        }

        int ans = min(end , n-st-1);
        int i = 0,j = end;
        while(i<=st && j<n){
            if(arr[i]<=arr[j]){
                ans = min(ans , j-i-1);
                i++;
            }else{
                j++;
            }
        }

        return ans;
    }
};