class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        int i=0;
        while(i<temperatures.size()){
            while(!s.empty() && temperatures[i]>temperatures[s.top()]){
                int prev=s.top();
                s.pop();
                ans[prev]=i-prev;
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};
