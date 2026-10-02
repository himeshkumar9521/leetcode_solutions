class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0;i<n;i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto&v:m){
            pq.push({v.second , v.first});
        }
        string ans;
        while(!pq.empty()){
            char cb = pq.top().second;
            int vb = pq.top().first;
            pq.pop();
            if(vb == 0){continue;}
            if(!ans.empty() && ans.back() == cb){
                if(pq.empty()){
                return "";
                }

                auto [freq,cs] = pq.top();
                pq.pop();

                ans.push_back(cs);
                freq--;
                if(freq>0){
                    pq.push({freq,cs});
                }

                pq.push({vb,cb});
            }else{
                ans.push_back(cb);
                vb--;
            if(vb>0){
                pq.push({vb,cb});
            }
            }

        }
        return ans;
    }
};