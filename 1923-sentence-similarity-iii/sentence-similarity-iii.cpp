class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss(s1),ss2(s2);
        vector<string> w1,w2;
        string w;
        while(ss >> w)
            w1.push_back(w);
        
        w.clear();
        while(ss2 >> w)
            w2.push_back(w);

        if(w1.size()>w2.size()){
            swap(w1,w2);
        }
        int n = w1.size(),m = w2.size();
        int i = 0,j = 0;
        int unmatch = 0;
        while(i<n && w1[i] == w2[i]){
            i++;
        }

        while(j<n-i && w1[n-1-j] == w2[m-1-j]){
            j++;
        }

        return i+j == n;
    }
};