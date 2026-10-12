class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int k=nums.size()-1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        int i=0; 
        while(i<nums.size()-2){
            int j=i+1;
            int k=nums.size()-1;
            int curr_sum=0;
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            while(j<k){
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                curr_sum=nums[i]+nums[j]+nums[k];
                if(curr_sum==0){
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    ans.push_back(res);
                    res.clear();
                    j++;
                    k--;
                }else if(curr_sum<0){
                    j++;
                }else{
                    k--;
                }
            }
            i++;
        }
        return ans;
    }
};
