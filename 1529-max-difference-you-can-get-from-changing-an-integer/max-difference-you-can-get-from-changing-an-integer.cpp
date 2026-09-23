class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);
        string a = temp;
        string b = temp;
        int n = temp.size();
        char x = '!';
        for (int i = 0; i < n; i++) {
            if (temp[i] != '9') {
                x = temp[i];
                break;
            }
        }
        if (x != '!') {
            for (int i = 0; i < n; i++) {
                if (temp[i] == x) {
                    a[i] = '9';
                }
            }
        }
        char y1 = '!';
        char y2 = '!';
        if (temp[0] != '1') {
            y1 = '1';
            y2 = temp[0];
        } else {
            for (int i = 0; i < n; i++) {
                if (temp[i] != '1' && temp[i] != '0') {
                    y2 = temp[i];
                    y1 = '0';
                    break;
                }
            }
        }
        for (int i = 0; i < n && y2 != '!'; i++) {
            if (temp[i] == y2) {
                b[i] = y1;
            }
        }
        return (stoi(a) - stoi(b));
    }
};