#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::vector<std::string> getNextCombinations (std::string curCombination) {
        std::vector<std::string> nextCombinations;
        for (int i=0; i<4; i++) {
            std::string upOne = curCombination;
            std::string downOne = curCombination;
            if ((upOne[i] - '0') == 9){
                upOne[i] = '0';
            } else {
                upOne[i]++;
            }
            if ((downOne[i] - '0') == 0){
                downOne[i] = '9';
            } else {
                downOne[i]--;
            }
            nextCombinations.push_back(upOne);
            nextCombinations.push_back(downOne);
        }
        return nextCombinations;
    }
    
    bool hasVisited(std::unordered_set<std::string>& visited, std::string combination) {
        return visited.find(combination) != visited.end(); 
    }
    
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> deads;
        std::unordered_set<std::string> visited;
        for (const auto& s:deadends) {
            deads.insert(s);
        }
        int step = 0;
        std::queue<std::string> q;
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()) {
            int qSize = q.size();
            for (int i=0; i<qSize; i++) {
                std::string curCombination = q.front();
                q.pop();
                if (curCombination == target) {
                    return step;
                }
                if (deads.find(curCombination) != deads.end()) {
                    continue;
                }
                std::vector<std::string> nextCombinations = getNextCombinations(curCombination);
                for (const auto& combination:nextCombinations) {
                    if (!hasVisited(visited, combination)) {
                        q.push(combination);
                        visited.insert(combination);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};