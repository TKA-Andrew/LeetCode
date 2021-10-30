#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return dp(s,0,p,0);
    }
    
    bool dp(std::string& s, int i, std::string& p, int j) {
        int sSize = s.size();
        int pSize = p.size();

        if (j==pSize) {
            return i==sSize;
        }
        if (i==sSize) {
            if((pSize-j)%2==1) {
                return false;
            }
            
            for (;j+1<pSize;j+=2) {
                if(p[j+1]!='*') {
                    return false;
                }
            }
        }

        if (s[i] == p[j] || p[j] == '.') {
            if(j<pSize-1 && p[j+1]=='*') {
                return dp(s,i,p,j+2) || dp(s,i+1,p,j); // match 0 time or more than 1 time
            } else {
                return dp(s, i+1, p, j+1); // match 1
            }
        } else {
            if (j<pSize-1 && p[j+1]=='*') {
                return dp(s, i , p, j+2); // match 0 time
            } else {
                return false;          
            }
        }
        
        return true;
    }
};