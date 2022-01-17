#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

typedef std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> MinHeap;

typedef std::unordered_map<int,std::vector<std::pair<int, int>>> Graph;

class Solution {
public:
    
    std::pair<std::vector<int>, std::vector<int>> dijkstra(Graph& graph, int source, int n) {
        MinHeap minHeap;
        
        // VARIABLLE DECLARATION
        std::vector<int> minTravelCost(n, INT_MAX);
        std::vector<int> prev(n, -1);
        std::vector<bool> visited(n, false);

        // BASE CASE
        minTravelCost[source] = 0;
        
        minHeap.push({0, source});
        
        while (!minHeap.empty()) {
            auto [curTravelCost, curVertex] = minHeap.top();
            minHeap.pop();
            if (visited[curVertex]) {
                continue;
            }
            visited[curVertex] = true;
            for (const auto& [nextVertex, nextTravelCost]: graph[curVertex]) {
                int newTravelCost = curTravelCost + nextTravelCost;
                if (!visited[nextVertex] && newTravelCost<minTravelCost[nextVertex]) {
                    minTravelCost[nextVertex] = newTravelCost;
                    prev[nextVertex] = curVertex;
                    minHeap.push({newTravelCost, nextVertex});
                }
            }
            
        }
        return {minTravelCost, prev};
        
    }
    
    std::pair<int, std::vector<int>> dijkstraSingleTarget(Graph& graph, int source, int target, int n) {
        MinHeap minHeap;
        
        // VARIABLLE DECLARATION
        std::vector<int> minTravelCost(n, INT_MAX);
        std::vector<int> prev(n, -1);
        std::vector<bool> visited(n, false);

        // BASE CASE
        minTravelCost[source] = 0;
        
        minHeap.push({0, source});
        
        while (!minHeap.empty()) {
            auto [curTravelCost, curVertex] = minHeap.top();
            minHeap.pop();
            if (curVertex == target) {
                break;
            }
            if (visited[curVertex]) {
                continue;
            }
            visited[curVertex] = true;
            for (const auto& [nextVertex, nextTravelCost]: graph[curVertex]) {
                int newTravelCost = curTravelCost + nextTravelCost;
                if (!visited[nextVertex] && newTravelCost<minTravelCost[nextVertex]) {
                    minTravelCost[nextVertex] = newTravelCost;
                    prev[nextVertex] = curVertex;
                    minHeap.push({newTravelCost, nextVertex});
                }
            }
            
        }
        return {minTravelCost[target], prev};
        
    }
    
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        
        // GRAPH CONSTRUCTION
        Graph graph;
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        
        auto [minTravelCost, prev] = dijkstra(graph, k-1, n);
        
        int maxTime = -1;
        for (auto time:minTravelCost) {
            if (time == INT_MAX) {
                return -1;
            }
            if (time > maxTime) {
                maxTime = time;
            }
        }
        
        return maxTime;
    }
    
};