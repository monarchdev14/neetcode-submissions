class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        if (s.size() < t.size() || t.empty()) {
            return ans;
        }
        unordered_map<char, int> target_freq;
        unordered_map<char, int> windows_freq;
        int min_len=INT_MAX;
        int value=0;
        int start=0;
        int t_value=0;
        for(int i=0; i<t.size(); i++){
            target_freq[t[i]]++;
        }
        t_value=target_freq.size();
        int j=0; int i=0;
        while(j<s.size()){
            if(target_freq.contains(s[j])){
                windows_freq[s[j]]++;
                if(windows_freq[s[j]]==target_freq[s[j]]){
                    value++;
                }
            }
            while(value==t_value){
                int curr_len=j-i+1;
                if(curr_len<min_len){
                    min_len=curr_len;
                    start=i;
                }
                if(target_freq.contains(s[i])){
                    if(windows_freq[s[i]]==target_freq[s[i]]){
                        value--;
                    }
                    windows_freq[s[i]]--;
                }
                i++;
            }
            j++;
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(start, min_len);
    }
};
