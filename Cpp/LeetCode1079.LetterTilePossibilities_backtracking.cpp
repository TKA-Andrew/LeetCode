#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    
    std::vector<std::string> tracks;
    std::unordered_set<std::string> trackset;
    
    void backtrack(std::string &tiles, std::vector<bool> &visited, std::string &track)
    {
        // termination condition
        if (track.length() == tiles.length()) return;
        
        for (int i=0; i<tiles.length(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                track.push_back(tiles[i]);
                if (trackset.count(track) == 0)
                {
                    trackset.insert(track);
                    tracks.push_back(track);
                    backtrack(tiles, visited, track);
                }
                track.pop_back();
                visited[i] = false;
            }
        }
    }
    
    int numTilePossibilities(std::string tiles) {
        std::string track = "";
        if (tiles.length() == 0) return 0;
        std::vector<bool> visited(tiles.length(), false);
        backtrack(tiles, visited, track);
        return tracks.size();
    }
};