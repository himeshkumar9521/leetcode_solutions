class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0;i<n;i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto&v:m){
            pq.push({v.second,v.first});
        }
        string ans = "";
        while(pq.size()>0){
            auto it = pq.top();
            pq.pop();
            for(int i = 0;i<it.first;i++){
                ans.push_back(it.second);
            }
        }
        return ans;
        
    }
};