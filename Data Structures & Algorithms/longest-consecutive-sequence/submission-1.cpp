class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int curr_len=0;
        int longest=0;
        for(int i=0; i<nums.size(); i++){
            mp.insert(nums[i]);
        }
        int i=0;
        for(int num : mp){
            if(!mp.contains(num-1)){
                int next=num+1;
                curr_len=1;
                while(mp.contains(next)){
                    curr_len++;
                    next+=1;
                }
                longest=max(longest, curr_len);
            }
            i++;
        }
        return longest;
    }
};
