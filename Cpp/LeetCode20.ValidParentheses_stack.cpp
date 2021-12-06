// O(N) time
// O(N) space

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for( const auto c:s) {
            if (c=='(' || c=='[' || c=='{') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                if (c==')' && stack.top()=='('){
                    stack.pop();
                } else if (c==']' && stack.top()=='['){
                    stack.pop();
                } else if (c=='}' && stack.top()=='{'){
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
      return stack.empty();
    }
};