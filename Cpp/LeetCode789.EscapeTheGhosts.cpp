// Space Complexity: O(1)
// Time Complexity: O(N) where N is number of ghosts

#include <vector>
#include <math.h>

class Solution {
public:
    bool escapeGhosts(std::vector<std::vector<int>>& ghosts, std::vector<int>& target) {
        int t_distance = abs(target[0]) + abs(target[1]);
        
        for (auto g: ghosts)
        {
            int g_distance = abs(g[0]-target[0]) + abs(g[1]-target[1]);
            // if ghost is nearer to target, means there is possibility of being caught by ghost
            if (g_distance <= t_distance)
            {
                return false;
            }
        }
        return true;
    }
};