class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        long long temp = 0;
        for(int i = 0;i<n;i++){
            temp+=source[i];
        }
        for(int i = 0;i<n;i++){
            temp-=target[i];
        }
        if(temp == 0){return true;}
        else{return false;}
    }
};