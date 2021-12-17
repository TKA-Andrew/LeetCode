#include <vector>

class Solution {
public:
    std::vector<int> pancakeSort(std::vector<int>& arr) {
        std::vector<int> sortSeq;
        int n = arr.size();
        sort(sortSeq, arr, n);
        return sortSeq;
    }
    
    void sort (std::vector<int>& sortSeq, std::vector<int>& arr, int n) {
        if (n==1) return;
        int maxIdx = 0;
        int maxCake = 0;
        for (int i=0;i<n;i++) {
            if (arr[i]>maxCake) {
                maxCake = arr[i];
                maxIdx = i;
            }
        }
        
        reverse(arr, 0, maxIdx);
        sortSeq.push_back(maxIdx+1);
        reverse(arr, 0, n-1);
        sortSeq.push_back(n);
        sort(sortSeq, arr, n-1);
    }
    
    void reverse (std::vector<int>& arr, int i, int j) {
        while (i<=j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};