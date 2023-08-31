// Time Complexity: O(N)
// Space Complexity: O(N)

#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> umap;
        for (char c:s) {
            umap[c] += 1;
        }
        for (char c:t) {
            if (umap.find(c) == umap.end()) {
                return false;
            }
            umap[c] -= 1;
            if (umap[c] == 0) {
                umap.erase(c);
            }
        }
        return umap.empty();
    }
};
