class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int end = n * n;
        int count = 1;
        int up = 0, left = 0;
        int down = n - 1, right = n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while (count <= end) {
            for (int i = left;i<=right; i++) {
                ans[up][i] = count;
                count++;
            }
            up++;
            for(int i = up;i<=down;i++){
                ans[i][right] = count;
                count++;
            }
            right--;
            for(int i = right;i>=left;i--){
                ans[down][i] = count;
                count++;
            }
            down--;
            for(int i = down;i>=up;i--){
                ans[i][left] = count;
                count++;
            }
            left++;
        }

        return ans;
    }
};