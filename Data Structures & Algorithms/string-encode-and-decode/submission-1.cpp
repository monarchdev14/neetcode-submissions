class Solution {
public:
    string encode(vector<string>& strs) {
        string s;
        for(int i=0; i<strs.size(); i++){
            int n=strs[i].size();
            string num=to_string(n);
            for(int j=0; j<num.size(); j++){
                s.push_back(num[j]);
            }
            s.push_back('#');
            for(int j=0; j<strs[i].size(); j++){
                s.push_back(strs[i][j]);
            }
        }
        return s;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int i=0; 
        while(i<s.size()){
            string num;
            num.clear();
            while(i<s.size() && s[i]!='#'){
                num.push_back(s[i]);
                i++;
            }
            int size=stoi(num);
            i++;
            string key;
            for(int k=0; k<size; k++){
                key.push_back(s[i]);
                i++;
            }
            ans.push_back(key);
        }
        return ans;
    }
};
