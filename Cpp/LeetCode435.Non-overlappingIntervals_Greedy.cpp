// O(N) time
// O(1) space

#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int N = intervals.size();
        std::sort(intervals.begin(), intervals.end());
        int pre_end = intervals[0][1];
        int deletes = 0;
        for (int i=1; i<N; i++) {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            if (cur_start >= pre_end) {
                pre_end = intervals[i][1];
            } else if (cur_end > pre_end) {
                deletes++;
            } else {
                // pre_start < cur_start < cur_end < pre_end
                deletes++; // drop previous interval
                pre_end = cur_end; // change to current interval
            }
        }
        return deletes;
    }
};