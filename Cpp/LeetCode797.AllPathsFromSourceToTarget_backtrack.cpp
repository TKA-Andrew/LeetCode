#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> tracks;
    
    void backtrack(std::vector<std::vector<int>>& graph, int currentNode, std::vector<int> track)
    {
        // termination condition
        if (currentNode == graph.size() - 1)
        {
            tracks.push_back(track);
            return;
        }
        
        // for each choices
        int numOfChoices = graph[currentNode].size();
        for (int i=0; i<numOfChoices; i++)
        {
            int nextNode = graph[currentNode][i];
            // add choice into track
            track.push_back(nextNode);
            // backtrack
            backtrack(graph, nextNode, track);
            // remove choice from the track
            track.pop_back();
        }
    }
    
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<int> track;
        track.push_back(0);
        backtrack(graph, 0, track);
        return tracks;
    }
    
};