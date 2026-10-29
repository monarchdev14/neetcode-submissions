class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str="";
        for(int i=0; i<strs.size(); i++){
            int n=strs[i].size();
            encoded_str.append(to_string(n));
            encoded_str.push_back('#');
            for(int j=0; j<strs[i].size(); j++){
                encoded_str.push_back(strs[i][j]);
            }
        }
        return encoded_str;
    }

    vector<string> decode(string encoded_str) {
        string operation=encoded_str;
        vector<string> ans;
        int i=0;
        while(i<encoded_str.size()){
            int j=i;
            while(encoded_str[j]!='#'){ 
                j++;
            }
            int length=stoi(encoded_str.substr(i, j-i));
            j++;
            ans.push_back(encoded_str.substr(j, length));
            i=j+length;
        }
        return ans;
    }
};
