// Take note that this solution will have Time Limit Exceeded problem when comes to big m and big n

#include <queue>
#include <vector>

class Solution {
public:

    int uniquePaths(int m, int n) {
        
        // special case
        if (m==1 && n==1)
        {
            return 1;
        }
        
        int moves[2][2] = {{1,0},{0,1}};
        int targetR = m-1;
        int targetC = n-1;
        int count = 0;
        std::vector<std::vector<int>> visited(m, std::vector<int> (n, false));
        std::queue<std::vector<int>> q;
        q.push({0,0});
        
        while (!q.empty())
        {
            auto qFront = q.front();
            int currentR = qFront[0];
            int currentC = qFront[1];
            q.pop();
            
            visited[currentR][currentC] = true;
            
            for (const auto move:moves)
            {
                int newR = currentR + move[0];
                int newC = currentC + move[1];

                if (newR >= m || newC >= n)
                {
                    continue;
                } else if (visited[newR][newC]) {
                    continue;
                } else {
                    if (newR == targetR && newC == targetC) {
                        count++;
                    } else {
                        q.push({newR, newC});
                    }
                }
            }
            
        }
        
        return count;
    }
};
