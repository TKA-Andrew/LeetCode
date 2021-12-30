// O(N) time
// O(1) space

#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        int N = points.size();
        std::sort(points.begin(), points.end());
        int pre_end = points[0][1];
        int arrows = 1;
        for (int i=1; i<N; i++) {
            int cur_start = points[i][0];
            int cur_end = points[i][1];
            if (cur_start>pre_end) {
                arrows++; // additional arrow needed
                pre_end = cur_end;// update new group of balloons
            } else if (cur_end<pre_end) {
                pre_end = cur_end; // update pre_end
            }
        }
        return arrows;
    }
};