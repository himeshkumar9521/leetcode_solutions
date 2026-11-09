class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){
            m[answers[i]]++;
        }
        int ans = 0;
        for(auto& v:m){
            if(v.first>v.second){
                ans+=(v.first+1);
            }else{
                int temp = ((v.second+v.first)/(v.first+1));
                ans+=(temp*(v.first+1));
            }
        }
        return ans;
    }
};