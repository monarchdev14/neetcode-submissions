class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<2){
            return false;
        }
        bool alter=false;
        sort(nums.begin(), nums.end());
        int i=0; int j=1;
        while(j<nums.size()){
            if(nums[j]==nums[i]){
                alter=true;
                break;
            }
            i++;
            j++;
        }
        return alter;
    }
};