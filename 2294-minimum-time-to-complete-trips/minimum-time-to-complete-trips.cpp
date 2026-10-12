class Solution {
public:
    bool helper(long long mid , vector<int>& t , int total){
        long long count = 0;
        for(int i = 0;i<t.size();i++){
            count+=(mid/t[i]);
        }
        return (count < total) ? false : true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin() , time.end());
        long long st = 1;
        long long end = 1LL*time[0]*totalTrips;
        long long ans = end;
        while(st<=end){
            long long mid = st+(end-st)/2;
            if(helper(mid,time,totalTrips)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;

        return -1;
    }
};