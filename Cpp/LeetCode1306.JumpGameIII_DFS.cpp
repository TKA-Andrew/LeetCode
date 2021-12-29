#include <vector>

class Solution {
public:
    bool canReach(std::vector<int>& arr, int start) {
        if (start<0 || start>=arr.size() || arr[start]<0) {
            return false;
        }
        arr[start] *= -1; // to mark as visited
        return arr[start]==0 || canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
    }
};