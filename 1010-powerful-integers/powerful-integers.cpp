class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;

        for (long long a = 1; a <= bound; ) {
            for (long long b = 1; a + b <= bound; ) {
                s.insert(a + b);

                // Prevent overflow and handle y = 1
                if (y == 1 || b > (bound - a) / y)
                    break;

                b *= y;
            }

            // Prevent overflow and handle x = 1
            if (x == 1 || a > bound / x)
                break;

            a *= x;
        }

        return vector<int>(s.begin(), s.end());
    }
};