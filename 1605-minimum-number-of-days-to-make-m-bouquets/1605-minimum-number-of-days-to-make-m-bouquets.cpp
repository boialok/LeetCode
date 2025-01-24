class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       int ans = 0;
       int n = bloomDay.size();
       long long val = m*1ll*k*1ll;
       if(n<val) return -1;
       int mini = INT_MAX;
       int maxi = INT_MIN;
       for(int i=0;i<n;i++){
         mini = min(bloomDay[i],mini);
         maxi = max(bloomDay[i],maxi);
       }
       int low = mini;
       int high = maxi;
       while(low<=high){
        int mid = (low+high)/2;
        int cnt = 0,noofB = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                noofB+=cnt/k;
                cnt = 0;
            }
        }
        noofB+= cnt/k;
        if(noofB>=m) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
       }
       return ans;
    }
};