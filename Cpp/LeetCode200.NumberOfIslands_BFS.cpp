#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int> (n, false));
        int totalIsland = 0;
        for (int i=0;i<m;i++) {
            for (int j=0; j<n; j++) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '0') {
                    visited[i][j] = true;
                    continue;
                }
                traverseNode(i, j, grid, visited, totalIsland);
            }
        }
        return totalIsland;
    }
    
    void traverseNode(int i, int j, std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& visited, int& totalIsland) {
        std::vector<std::vector<int>> nodesToExplore{{i,j}};
        while (nodesToExplore.size() != 0) {
            auto currentNode = nodesToExplore.back();
            nodesToExplore.pop_back();
            i = currentNode[0];
            j = currentNode[1];
            if (visited[i][j]) {
                continue;
            }
            visited[i][j] = true;
            if (grid[i][j] == '0') {
                continue;
            }
            std::vector<std::vector<int>> unvisitedNodes = getUnvisitedNodes(i, j, grid, visited);
            for (auto node: unvisitedNodes) {
                nodesToExplore.push_back(node);
            }
        }
        totalIsland++;
    }
    
    
    std::vector<std::vector<int>> getUnvisitedNodes(int i, int j, std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& visited) {
        std::vector<std::vector<int>> unvisitedNodes;
        if (i>0 && !visited[i-1][j]) {
            unvisitedNodes.push_back({i-1, j});
        }
        if (i<grid.size()-1 && !visited[i+1][j]) {
            unvisitedNodes.push_back({i+1, j});
        }
        if (j>0 && !visited[i][j-1]) {
            unvisitedNodes.push_back({i, j-1});
        }
        if (j<grid[0].size()-1 && !visited[i][j+1]) {
            unvisitedNodes.push_back({i, j+1});
        }
        return unvisitedNodes;
    }
};