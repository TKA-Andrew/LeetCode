#include <queue>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::priority_queue<std::pair<int, char>> pq;
        std::unordered_map<char, int> m;
        for (auto t: tasks)
        {
            m[t]++;
        }
        for (auto ele:m)
        {
            pq.push({ele.second, ele.first});
        }
        
        int time = 0;
        while(!pq.empty())
        {
            auto task = pq.top();
            pq.pop();
            time++;
            std::vector<std::pair<int, char>> temp;
            if (task.first > 1) 
            {
                temp.push_back({task.first-1, task.second});
            } 
            
            // while there are other tasks, try to fill into the n time range
            int processedTask = 0;
            while (!pq.empty() && processedTask<n)
            {
                auto othertask = pq.top();
                pq.pop();
                if (othertask.first > 1) 
                {
                    temp.push_back({othertask.first-1, othertask.second});
                }
                processedTask++;
            }
            
            // add the remaining tasks back to pq
            for (auto t:temp)
            {
                pq.push(t);
            }
            
            if (!pq.empty()) // if still got other tasks, add n
            {
                time += n;
            } else {
                time += processedTask;
            }
        }
        return time;
    }
};