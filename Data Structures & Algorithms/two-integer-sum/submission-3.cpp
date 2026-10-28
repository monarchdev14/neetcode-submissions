class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        for(int i=0; i<nums.size(); i++){
            if(mp.contains(target-nums[i]) && mp[target-nums[i]] != i){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
