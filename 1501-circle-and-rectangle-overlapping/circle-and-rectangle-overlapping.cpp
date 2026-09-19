class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xCloset = max(x1 , min(xCenter , x2));
        int yCloset = max(y1 , min(yCenter , y2));
        int dx = xCenter-xCloset;
        int dy = yCenter-yCloset;

        return (dx*dx + dy*dy <= radius*radius);
    }
};