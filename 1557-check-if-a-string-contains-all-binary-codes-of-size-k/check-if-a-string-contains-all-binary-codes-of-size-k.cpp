class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> set;
        int st = 0;
        for(int i = 0;i<s.size();i++){
            if((i-st+1)>k){
                st++;
            }

            if(i-st+1 == k){
                string temp = s.substr(st,(i-st+1));
                set.insert(stoi(temp,nullptr,2));
            }
        }
        vector<int> temp(set.begin(),set.end());
        sort(temp.begin() , temp.end());

        int high = (1 << k)-1;
        if(temp.size() < (high+1)){
            return false;
        }

        for(int i = 0;i<=high;i++){
            if(temp[i] != i){
                return false;
            }
        }

        return true;
    }
};