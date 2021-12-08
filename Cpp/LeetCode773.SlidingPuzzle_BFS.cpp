#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int slidingPuzzle(std::vector<std::vector<int>>& board) {
        std::vector<std::vector<int>> neighbour {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        
        int step = 0;
        std::string start="";
        const std::string target="123450";
        const int m=2;
        const int n=3;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                start.push_back(board[i][j]+'0');
            }
        }
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        
        q.push(start);
        visited.insert(start);
        
        while (!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                auto current = q.front();
                q.pop();
                if (current == target) {
                    return step;
                }
                
                int idx=0;
                for (;current[idx]!='0';idx++);
                
                for (auto const nIdx: neighbour[idx]) {
                    std::string newString = current;
                    std::swap(newString[nIdx], newString[idx]);
                    if (!visited.count(newString)) {
                        q.push(newString);                        
                        visited.insert(newString);
                    }
                }

            }
            step++;
        }
        
        return -1;
    }
};