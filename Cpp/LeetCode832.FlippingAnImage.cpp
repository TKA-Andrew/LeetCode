#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        int n = image.size();
        
        for (int row=0; row<n; row++)
        {
            int leftPointer = 0;
            int rightPointer = n-1;
            while (leftPointer<=rightPointer)
            {
                if (leftPointer==rightPointer)
                {
                    image[row][leftPointer] = !image[row][leftPointer];                
                } else {
                    image[row][leftPointer] = !image[row][leftPointer];
                    image[row][rightPointer] = !image[row][rightPointer];            
                    std::swap(image[row][leftPointer], image[row][rightPointer]);
                }
                leftPointer++;
                rightPointer--;
            }
        }
        
        return image;
    }
    
};