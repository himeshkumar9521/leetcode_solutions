class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        long long a = 1;
        while(a<=bound){
            long long b = 1;
            while(a+b<=bound){
                s.insert(a+b);
                if (y == 1 || b > (bound - a) / y)
                    break;
                b*=y;
            }
            if (x == 1 || a > bound / x)
                break;
            a*=x;
        }
        return vector<int>(s.begin() , s.end());
    }
};