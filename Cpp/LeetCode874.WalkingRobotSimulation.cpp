#include <vector>
#include <set>

class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles)     {
        int x = 0;
        int y = 0;
        int heading = 0; //degree
        int maxDistance = 0;
        
        std::set<std::pair<int,int>> setOfObstacles;   
        
        for (const std::vector<int> o:obstacles)
        {
            setOfObstacles.insert({o[0], o[1]});
        }
        
        for (const int c:commands)
        {
            if (c==-2)
            {
                heading -= 90;
                if (heading < 0) heading = 360+heading;
            }
            else if (c==-1)
            {
                heading += 90;
                heading = heading%360;
            } else {
                if (heading == 0)
                {
                    for (int i=0; i<c; i++)
                    {
                        if(setOfObstacles.count({x,y+1})){
                            break;
                        }
                        y += 1;
                    }
                }
                else if (heading == 90)
                {
                    for (int i=0; i<c; i++)
                    {
                        if(setOfObstacles.count({x+1,y})){
                            break;
                        }
                        x += 1;
                    }
                }
                else if (heading == 180)
                {
                    for (int i=0; i<c; i++)
                    {
                        if(setOfObstacles.count({x,y-1})){
                            break;
                        }
                        y -= 1;
                    }
                }
                else if (heading == 270)
                {
                    for (int i=0; i<c; i++)
                    {
                        if(setOfObstacles.count({x-1,y})){
                            break;
                        }
                        x -= 1;
                    }
                }
                int currentDistance = x*x + y*y;
                if (currentDistance>maxDistance) maxDistance = currentDistance;
            }
        }
        
        return maxDistance;
        
    }
};