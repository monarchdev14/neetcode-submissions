class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        mp[target-nums[0]]=0;
        for(int i=1; i<nums.size(); i++){
            if(mp.count(nums[i])){
                ans.push_back(mp[nums[i]]);
                ans.push_back(i);
                break;
            }
            mp[target-nums[i]]=i;
        }
        return ans;
    }
};
