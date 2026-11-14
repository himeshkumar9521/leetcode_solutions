class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        while(!pq.empty()){
            int val = pq.top().first;
            char ins = pq.top().second;
            pq.pop();
            if(s.size()<2){
                s.push_back(ins);
                if(val >1){pq.push({val-1,ins});}
            }else{
                if(!(s[s.size()-1] == ins && s[s.size()-2] == ins)){
                    s.push_back(ins);
                    if(val >1){pq.push({val-1,ins});}
                }else{
                    if(pq.size() == 0){
                        return s;
                    }
                    auto it = pq.top();
                    pq.pop();
                    pq.push({val,ins});
                    s.push_back(it.second);
                    if(it.first > 1){pq.push({it.first-1,it.second});}
                }
            }
        }
        return s;
    }
};