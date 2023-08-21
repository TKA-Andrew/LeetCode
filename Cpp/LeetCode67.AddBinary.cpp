#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        std::string ret = "";
        while (i >=0 || j >= 0 || carry != 0) {
            if (i >= 0) {
                carry += a[i] == '0' ? 0 : 1;
                i--;
            }
            if (j >= 0) {
                carry += b[j] == '0' ? 0 : 1;
                j--;
            }
            ret = ((carry%2) == 0 ? "0":"1") + ret;
            carry /= 2;
        }
        return ret;
    }
};