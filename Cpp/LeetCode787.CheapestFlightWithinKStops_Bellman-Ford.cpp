#include <vector>
#include <climits>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        
        std::vector<int> minTravelCost(n, INT_MAX);
        minTravelCost[src] = 0;
        
        int maxNumOfTrials = k+1;
        
        for (int i=0; i<maxNumOfTrials; i++) {
            std::vector<int> temp(minTravelCost);
            for (auto flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int travelCost = flight[2];
                if (minTravelCost[u] == INT_MAX) {
                    continue;
                }
                if ((minTravelCost[u]+travelCost < temp[v])) {
                    temp[v] = minTravelCost[u] + travelCost;
                }
            }
            minTravelCost = temp;
        }
        return (minTravelCost[dst] == INT_MAX) ? -1 : minTravelCost[dst];
    }
    
};