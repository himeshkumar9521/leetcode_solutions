class Solution {
public:
    bool canAliceWin(int n) {
        int flag = 0;
        int count = 10;
        while(n>0){
            if(count>n){
                return (flag == 1);
            }else{
                n-=count;
                flag = !flag;
            }
            count--;
        }
        return (flag == 1);
    }
};