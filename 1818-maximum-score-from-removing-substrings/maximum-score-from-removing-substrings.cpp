class Solution {
public:
    int removePair(string &s, char a, char b, int points) {
        string st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.back() == a && c == b) {
                st.pop_back();
                score += points;
            } else {
                st.push_back(c);
            }
        }

        s = st;
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;

        if (x >= y) {
            score += removePair(s, 'a', 'b', x);
            score += removePair(s, 'b', 'a', y);
        } else {
            score += removePair(s, 'b', 'a', y);
            score += removePair(s, 'a', 'b', x);
        }

        return score;
    }
};