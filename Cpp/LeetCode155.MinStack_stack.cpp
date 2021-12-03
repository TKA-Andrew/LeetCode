#include <stack>

class MinStack {
public:
    std::stack<long long> s;
    std::stack<long long> minRecord;
    MinStack() {
    }
    
    void push(long long val) {
        s.push(val);
        long long minVal = val;
        if (!minRecord.empty()) {
            if (minRecord.top()< minVal) {
                minVal = minRecord.top();
            }
        }
        minRecord.push(minVal);
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();        
            minRecord.pop();
        }
    }
    
    long long top() {
        return s.top();
    }
    
    long long getMin() {
        return minRecord.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */