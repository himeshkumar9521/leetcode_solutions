class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> m;
        for(int i = 0;i<n;i++){
            m[words[i]]++;
        }
        vector<pair<int,string>> temp;
        for(auto&v:m){
            temp.push_back({v.second,v.first});
        }
        sort(temp.begin() , temp.end() , [](auto&a , auto&b){
            if(a.first == b.first){
                return a.second < b.second;
            }else{
                return a.first > b.first;
            }
        });

        vector<string> ans;
        int count = 0;
        for(auto& a:temp){
            if(count == k){
                break;
            }
            ans.push_back(a.second);
            count++;
        }

        return ans;
    }
};