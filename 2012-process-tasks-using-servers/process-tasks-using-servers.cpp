class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        map<int,vector<pair<int,int>>> mp;
        vector<int> ans(m,0);
        long long time = 0;
        for(int i = 0;i<n;i++){
            pq.push({servers[i],i});
        }
        for(int i = 0;i<m;i++){
            time = max(time , (long long)i);

            if(!mp.empty() && mp.begin()->first<=time){
                vector<pair<int,int>> part = mp.begin()->second;
                for(int j = 0;j<part.size();j++){
                    pq.push(part[j]);
                }
                mp.erase(mp.begin()->first);
            }

            if(pq.empty()){
                time = mp.begin()->first;
                if(!mp.empty() && mp.begin()->first<=time){
                vector<pair<int,int>> part = mp.begin()->second;
                for(int j = 0;j<part.size();j++){
                    pq.push(part[j]);
                }
                mp.erase(mp.begin()->first);
                }
            }

            auto it = pq.top();
            pq.pop();
            ans[i] = it.second;
            int t = time + tasks[i];
            mp[t].push_back(it);
        }

        return ans;

    }
};