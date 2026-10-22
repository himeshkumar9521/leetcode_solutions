class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int a : nums){
            pq.push(a);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};