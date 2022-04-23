// REFERENCE: https://www.youtube.com/watch?v=cIBFEhD77b4
// Kahn's Algorithm
/*
The intuition behind Kahn's algorithm is to repeatedly remove nodes without dependencies (nodes with indegree of 0).
*/

// Time Complexity: O(V+E)
// Space Complexity: O(V)

#include <vector>
#include <queue>

class Solution {
public:    
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {

        // get adjacent list
        std::vector<std::vector<int>> adj(numCourses);
        for (auto p:prerequisites)
        {
            adj[p[0]].push_back(p[1]);
        }
        
        // get incoming degree of every node
        std::vector<int> in_degree(numCourses, 0);
        for (auto p:prerequisites)
        {
            in_degree[p[1]]++;
        }
        
        std::queue<int> q;
        
        for (int i=0; i<numCourses; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int removedNode = 0;
        
        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            removedNode++;
            for (auto next: adj[current])
            {
                in_degree[next]--;
                if (in_degree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        
        // if all nodes are visited, means no cycle
        if (removedNode == numCourses)
        {
            return true;
        }

        return false;
    }
};