#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>

typedef std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> MinHeap;
typedef std::unordered_map<int, std::vector<std::pair<int, int>>> Graph;

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        Graph graph;
        for (int i=0; i<flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        return dijkstraSingleTarget(graph, src, dst, n, k);
    }
    
    int dijkstraSingleTarget(Graph graph, int source, int target, int n, int k) {
        
        std::vector<int> minTravelCost(n, INT_MAX);
        std::vector<int> stops(n, INT_MAX);
        minTravelCost[source] = 0;
        stops[source] = 0;
        
        MinHeap minHeap;
        minHeap.push({0, source, 0});
        
        while(!minHeap.empty()) {
            auto[curTravelCost, curVertex, curStop] = minHeap.top();
            minHeap.pop();
            if (curVertex == target) break;
            if (curStop == k+1) continue;
            for (const auto& [nextVertex, nextTravelCost]: graph[curVertex]) {
                int newTravelCost = curTravelCost+nextTravelCost;
                int newStop = curStop + 1;
                if (newTravelCost<minTravelCost[nextVertex]) {
                    minTravelCost[nextVertex] = newTravelCost;
                    stops[nextVertex] = newStop;    
                    minHeap.push({newTravelCost, nextVertex, newStop});  
                } else if (newStop < stops[nextVertex]) {
                    stops[nextVertex] = newStop;    
                    minHeap.push({newTravelCost, nextVertex, newStop});  
                }
            }
            
        }
        return minTravelCost[target] == INT_MAX ? -1 : minTravelCost[target];
    }
};