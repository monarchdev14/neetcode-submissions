class Solution {
public:
    string hash_key(string &s){
        string hash;
        vector<int> freq(26,0);
        for(char i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<freq.size(); i++){
            hash.append(to_string(freq[i]));
            hash.append("#");
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for(int i=0; i<strs.size(); i++){
            string key=hash_key(strs[i]);
            if(mp.find(key)==mp.end()){
                mp[key]=res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(strs[i]);
        }
        return res;
    }
};
