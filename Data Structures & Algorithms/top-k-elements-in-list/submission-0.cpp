class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ref;
        vector<int> bucket;
        vector<int> ans;
        int i=0; int j=0;
        while(j<nums.size()){
            if(nums[j]==nums[i]){
                j++;
            }else{
                bucket.push_back(nums[i]);
                bucket.push_back(j-i);
                ref.push_back(bucket);
                bucket.clear();
                i=j;
            }
        }
        bucket.push_back(nums[i]);
        bucket.push_back(j-i);
        ref.push_back(bucket);
        sort(ref.begin(), ref.end(), [](const vector<int>& a, const vector<int>&
        b){
        return a[1] > b[1];
        });
        for(int m = 0; m < k; m++) {
            ans.push_back(ref[m][0]); 
        }
        return ans;
    }
};
