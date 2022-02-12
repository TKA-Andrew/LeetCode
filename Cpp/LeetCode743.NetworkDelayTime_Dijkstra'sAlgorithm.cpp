#include <vector>
#include <set>
#include <unordered_map>
#include <climits>

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {

        // VARIABLLE DECLARATION
        std::vector<int> minTravelCost(n, INT_MAX);
        std::set<int> visited;

        // BASE CASE
        minTravelCost[k-1] = 0;
        
        // GRAPH CONSTRUCTION
        std::unordered_map<int,std::vector<std::pair<int, int>>> graph;
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        // LOOP UNTIL ALL VERTICES ARE VISITED
        while (visited.size() != n) {

            // FIND UNVISITED VERTEX WITH MINIMUM TRAVEL COST
            auto [currentVertex, currentMinTravelCost] = getVertexWithMinTravelCost(minTravelCost, visited);

            // ENDING CONDITION
            if (currentMinTravelCost == INT_MAX) {
                return -1;
            }

            // UPDATE VISITED VERTICES
            visited.insert(currentVertex);

            // SCAN THROUGH NEIGHBOURING VERTICES
            for (auto edgeInfo: graph[currentVertex]) {
                int vertexIdx = edgeInfo.first;
                if (visited.find(vertexIdx) != visited.end()) {
                    continue;
                }
                
                // FORMULATE newTravelCost
                int newTravelCost = currentMinTravelCost + edgeInfo.second;

                // UPDATE minTravelCost
                if (newTravelCost<minTravelCost[vertexIdx-1]) {
                    minTravelCost[vertexIdx-1] = newTravelCost;                
                }
            }
        }

        int maxTime = -1;
        for (auto time:minTravelCost) {
            maxTime=std::max(maxTime, time);
        }

        return maxTime;
    }
    
    std::tuple<int, int> getVertexWithMinTravelCost(const std::vector<int>& minTravelCost, const std::set<int>& visited)
    {
        int currentMinTravelCost = INT_MAX;
        int vertex = -1;
        for (int vertexIdx = 1; vertexIdx<minTravelCost.size()+1; vertexIdx++) {
            int time = minTravelCost[vertexIdx-1];
            if (visited.find(vertexIdx) != visited.end()) {
                continue;
            }
            if (time < currentMinTravelCost) {
                currentMinTravelCost = time;
                vertex = vertexIdx;
            }
        }
        return {vertex, currentMinTravelCost};
    }
};