#include <iostream>
#include <stack>

// credit to: https://leetcode.com/problems/basic-calculator/discuss/1457045/C%2B%2B-oror-Explained-oror-Stacks-oror-Beginner-FriendlyEasy-To-Understand

class Solution {
public:
    
    // By interpreting every '-' as unary operator,
    // there is only one operation which is sum,
    // hence we only need to handle the sign and summation
    
    // To handle () operations, 
    // we will push the sum and sign into stack before we proceed with expression in subsequent ().
    // When we finished processing the expression in bracket:
    //      - the current sum represents the result of summation in bracket
    //      - we get the previousSum and previousSign from the stack
    //      - we update the sum, where sum = previousSum + (previousSign * sum)
    
    int calculate(std::string s) {
        
        std::stack <std::pair<int, int>> st; // pair <previousSum, previousSign>
        long long sum {0};
        int sign {1};
        
        for (int i {0}; i<s.length(); ++i) {
            char ch {s[i]};
            if (std::isdigit(ch)) {
                long long int num {0};
                while (i<s.length() && std::isdigit(s[i])) {
                    // adding a character to int will get the s[i] in ASCII representation
                    // to offset the ASCII code and convert it to actual number, we need to -'0'
                    num = (num*10) + (s[i] - '0');
                    i++;
                }
                i--; // to minus the extra increment that caused while loop to break
                sum += (num*sign);
                sign = 1; // reset after summation
            } else if (ch == '(') {
                st.push(std::make_pair(sum,sign)); 
                sum = 0; // reset 
                sign = 1; // reset
            } else if (ch == ')') {
                long long previousSum {st.top().first};
                int previousSign {st.top().second};
                sum = previousSum + (previousSign * sum); 
                st.pop();
                sign = 1; // reset
            } else if (ch == '-') {
                sign = -1; // toggle sign
            }
        }
        
        return sum;
    }
};