class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int ans;
        for(int i=0; i<tokens.size(); i++){
            s.push(tokens[i]);
            if(s.top()=="*" || s.top()=="/" || s.top()=="+" || s.top()=="-"){
                string op=s.top();
                s.pop();
                string num1=s.top();
                s.pop();
                string num2=s.top();
                s.pop();
                if(op=="*"){
                    int ans=stoi(num1)*stoi(num2);
                    s.push(to_string(ans));
                }else if(op=="/"){
                    int ans=stoi(num2)/stoi(num1);
                    s.push(to_string(ans));
                }else if(op=="+"){
                    int ans=stoi(num2)+stoi(num1);
                    s.push(to_string(ans));
                }else{
                    int ans=stoi(num2)-stoi(num1);
                    s.push(to_string(ans));
                }
            }
        }
        return stoi(s.top());
    }
};
