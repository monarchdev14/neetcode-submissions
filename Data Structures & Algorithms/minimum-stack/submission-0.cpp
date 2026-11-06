class MinStack {
public:
    vector<int> vec;
    vector<int> min_element;
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        if(min_element.empty() || val<=min_element.back()){
            min_element.push_back(val);
        }
    }
    
    void pop() {
        if(min_element.back()==vec.back()){
            min_element.pop_back();
        }
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return min_element.back();
    }
};
