#include <unordered_map>
#include <queue>
#include <vector>

typedef std::unordered_map<int,std::vector<std::pair<int, double>>> Graph;

typedef std::priority_queue <std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> MinHeap;

class Solution {
public:
    
    std::pair<double, std::vector<int>> dijkstraSingleTarget(Graph& graph, int source, int target, int n) {

        MinHeap minHeap;
        
        // VARIABLLE DECLARATION
        std::vector<double> minTravelCost(n, 0);
        std::vector<int> prev(n, -1);
        std::vector<bool> visited(n, false);

        // BASE CASE
        minTravelCost[source] = -1; // to negate the costs
        
        minHeap.push({-1, source});
        
        while (!minHeap.empty()) {
            auto [curTravelCost, curVertex] = minHeap.top();
            minHeap.pop();

            // ENDING CONDITION
            if (curVertex == target) {
                break;
            }

            if (visited[curVertex]) {
                continue;
            }

            visited[curVertex] = true;
            for (const auto& [nextVertex, nextTravelCost]: graph[curVertex]) {
                double newTravelCost = curTravelCost * nextTravelCost;
                if (!visited[nextVertex] && newTravelCost<minTravelCost[nextVertex]) {
                    minTravelCost[nextVertex] = newTravelCost;
                    prev[nextVertex] = curVertex;
                    minHeap.push({newTravelCost, nextVertex});
                }
            }
            
        }
        
        // to invert the travelCost back to positive
        return {-minTravelCost[target], prev};
        
    }
    
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        
        // GRAPH CONSTRUCTION
        Graph graph;
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]}); // if the graph is undirected
        }
        
        auto dijkstraResult = dijkstraSingleTarget(graph, start, end, n);
        return dijkstraResult.first;
        
    }
};