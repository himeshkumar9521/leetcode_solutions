class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int n = temp.size();
        if(n == 1){
            return num;
        }
        int flag = 0;
        for(int i = 0;i<n-1;i++){
            int high = *max_element(temp.begin()+i+1 , temp.end());
            if(high<=temp[i]){
                continue;
            }
            for(int j = n-1;j>i;j--){
                if(temp[j] == high){
                    swap(temp[i] , temp[j]);
                    flag = 1;
                    break;
                }
            }
            if(flag){break;}
        }
        return stoi(temp);

    }
};