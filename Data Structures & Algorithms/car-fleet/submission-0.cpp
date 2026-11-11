class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> combined;
        stack<double> s;
        for(int i=0; i<position.size(); i++){
            combined.push_back({position[i], speed[i]});
        }
        sort(combined.begin(), combined.end());
        for(int i=combined.size()-1; i>=0; i--){
            double time=static_cast<double>(target-combined[i].first)/combined[i].second;
            if(s.empty()){
                s.push(time);
            }
            if(time>s.top()){
                s.push(time);
            }
        }
        return s.size();
    }
};
