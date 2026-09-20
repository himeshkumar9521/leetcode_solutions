class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int count = 1;
        for(char ch : s){
            sum+=(count*int(123-ch));
            count++;
        }

        return sum;
    }
};