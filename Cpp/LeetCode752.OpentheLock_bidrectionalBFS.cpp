// using bidirectional BFS
// bidirectional BFS can be used to improve BFS if we know where is the target
// the main concept is take turn to do BFS from both end, and use hashSet to remember the paths of each end
// when the node of setA can be found in setB, means both end already met, and can return the total number of step
// However, both BFS and bidirectional BFS have the same space-time complexity although bidirectional BFS is actually faster
#include <vector>
#include <string>
#include <unordered_set>

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
        // use set insead of queue, for faster identifying existence of an element
        std::unordered_set<std::string> s1;
        std::unordered_set<std::string> s2;
        s1.insert("0000"); // start from initial point
        s2.insert(target); // start from target
        visited.insert("0000");
        while(!s1.empty() && !s2.empty()) {
            // Minor Enhancement
            // swap s1 and s2 when s1 has larger size
            // so that BFS is perform on set with smaller size first
            // as smaller size of set will result in smaller expansion
             if (s1.size() > s2.size()) {
                std::unordered_set<std::string> tempForSwap = s1;
                s1=s2;
                s2=tempForSwap;
            }

            std::unordered_set<std::string> temp;
            for (const auto& curCombination:s1) {
                if (deads.find(curCombination) != deads.end()) {
                    continue;
                }
                if (s2.find(curCombination) != s2.end()) { // means both end already met
                    return step;
                }
                visited.insert(curCombination);
                std::vector<std::string> nextCombinations = getNextCombinations(curCombination);
                for (const auto& combination:nextCombinations) {
                    if (!hasVisited(visited, combination)) {
                        temp.insert(combination);
                    }
                }
            }
            // switch s1 and s2 to take turn perform BFS from both ends
            s1=s2;
            s2=temp;
            step++;
        }
        return -1;
    }
};