class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool ans=false;
        if(s2.size()>=s1.size()){
            vector<int> freq1(26, 0);
            vector<int> freq2(26, 0);
            for(int i=0; i<s1.size(); i++){
                freq1[s1[i]-'a']++;
            }
            int j=0; int i=0;
            while(j<s2.size()){
                freq2[s2[j]-'a']++;
                if(j-i+1>s1.size()){
                    freq2[s2[i]-'a']--;
                    i++;
                }
                if(j-i+1==s1.size()) {
                    if(freq2==freq1) {
                        ans=true;
                        break;
                    }
                }
                j++;
            }
            return ans;
        }else{
            return ans;
        }
    }
};
 