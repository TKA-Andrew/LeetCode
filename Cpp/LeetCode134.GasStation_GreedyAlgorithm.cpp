// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {        
        
        int totalGas = 0;
        int totalCost = 0;
        for (auto g:gas) {
            totalGas += g;
        }        
        for (auto c:cost) {
            totalCost += c;
        }
        if (totalCost>totalGas) {
            return -1; // impossible to reach if not enough total Gas
        }
        
        int numOfStations = cost.size();
        int gasLeft = 0;
        int minimumGasLeft = 0; // the station with minimumGasLeft should be starting
        int startingStation = 0; // initialize with station 0, then loop through the rest
        for (int stationIdx=1; stationIdx<numOfStations; stationIdx++) {
            int previousGas = gas[stationIdx-1];
            int costToThisStation = cost[stationIdx-1];
            gasLeft += (previousGas-costToThisStation);
            if (gasLeft<minimumGasLeft) {
                minimumGasLeft = gasLeft;
                startingStation = stationIdx;
            }
        }
        return startingStation;
    }
};