class Solution {
public:
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        int m = temp.size();
        int flag = 0;
        for(int i = m-2;i>=0;i--){
            if(temp[i]<temp[i+1]){
                for(int j = m-1;j>i;j--){
                    if(temp[i]<temp[j]){
                        swap(temp[i] , temp[j]);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    sort(temp.begin() + i+1,temp.end());
                    break;
                }
            }
        }
        long long ans = stoll(temp);
        if(flag == 0 || ans>INT_MAX){
            return -1;
        }
        return stoi(temp);
    }
};