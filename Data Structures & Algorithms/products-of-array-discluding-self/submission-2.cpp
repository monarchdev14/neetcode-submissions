class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> left;
        vector<int> right;
        int l=1;
        for(int i=0; i<nums.size(); i++){
            l*=nums[i];
            left.push_back(l);
        }
        int r=1;
        for(int k=nums.size()-1; k>=0; k--){
            r*=nums[k];
            right.push_back(r);
        }
        reverse(right.begin(), right.end());
        int start=1;
        ans.push_back(right[1]);
        for(int i=1; i<nums.size()-1; i++){
            ans.push_back(right[i+1]*left[i-1]);
        }
        ans.push_back(left[left.size()-2]);
        return ans;
    }
};