#include <vector>
#include <queue>
#include <unordered_map>

typedef std::unordered_map<int,std::vector<std::pair<int, double>>> Graph;
typedef std::priority_queue<std::pair<double, int>> MaxHeap;

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        
        // GRAPH CONSTRUCTION
        std::unordered_map<int,std::vector<std::pair<int, double>>> graph;
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        return dijkstraSingleTarget(graph, start, end, n);
    }
    
    double dijkstraSingleTarget(Graph& graph, int source, int target, int n) {
        
        // VARIABLLE DECLARATION
        std::vector<double> maxTravelCost(n, 0);
        std::vector<bool> visited(n, false);

        // BASE CASE
        maxTravelCost[source] = 1;
        
        MaxHeap maxHeap;
        maxHeap.push({1, source});
        
        while (!maxHeap.empty()) {
            auto [curTravelCost, curVertex] = maxHeap.top();
            maxHeap.pop();
            if (curVertex == target || curTravelCost == 0) {
                break;
            }
            visited[curVertex] = true;
            for (const auto& [nextVertex, nextTravelCost]: graph[curVertex]) {
                double newTravelCost = curTravelCost * nextTravelCost;
                if (!visited[nextVertex] && newTravelCost>maxTravelCost[nextVertex]) {
                    maxTravelCost[nextVertex] = newTravelCost;
                    maxHeap.push({newTravelCost, nextVertex});
                }
            }
            
        }
        return maxTravelCost[target];
        
    }
    
};