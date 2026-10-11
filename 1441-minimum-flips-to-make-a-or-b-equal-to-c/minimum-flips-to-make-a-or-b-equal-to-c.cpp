class Solution {
public:
    int minFlips(int a, int b, int c) {
        string fir = bitset<30>(a).to_string();
        string sec = bitset<30>(b).to_string();
        string thir = bitset<30>(c).to_string();
        int count = 0;
        for(int i = 0;i<fir.size();i++){
            if(thir[i] == '0'){
                if(fir[i] == '1' && sec[i] == '1'){
                    count+=2;
                }else if(fir[i] == '1' || sec[i] == '1'){count++;}
            }else{
                if(fir[i] == '0' && sec[i] == '0'){
                    count++;
                }
            }
        }

        return count;
    }
};