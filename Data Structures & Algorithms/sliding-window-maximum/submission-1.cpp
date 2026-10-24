class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int i = 0, j = 0;
        vector<int> ans;

        while (j < nums.size()) {

            // Remove smaller elements from the back
            while (!q.empty() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }

            q.push_back(j);

            // Remove indices outside the current window
            if (q.front() < i) {
                q.pop_front();
            }

            // When the window reaches size k
            if (j - i + 1 == k) {
                ans.push_back(nums[q.front()]);
                i++;
            }

            j++;
        }

        return ans;   
    }
};
