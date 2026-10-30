class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=high;
        while(l<=high){
            int mid=l+(high-l)/2;
            long long curr_time=0;
            for(int i=0; i<piles.size(); i++){
                curr_time+=(piles[i]+mid-1)/mid;
            }
            if(curr_time<=h){
                ans=mid;
                high=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
