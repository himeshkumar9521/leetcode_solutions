class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        string temp = s + s;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int j = i;
            int count = 0;
            int temp2 =0;
            while(count<n-1){
                if(temp[j] == temp[j+1]){
                    temp2++;
                }
                j++;
                count++;
            }
            if(temp2 == k){
                ans++;
            }
        }

        return ans;
    }
};