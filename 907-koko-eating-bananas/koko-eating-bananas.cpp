class Solution {
public:
    bool helper(vector<int>& piles, int mid, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= (piles[i] / mid + (piles[i] % mid != 0));
            if (h < 0) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};