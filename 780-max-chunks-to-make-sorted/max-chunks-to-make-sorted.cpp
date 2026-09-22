class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = max(arr[i] , mx);

            if(mx == i){
                count++;
            }
        }
        return count;
    }
};