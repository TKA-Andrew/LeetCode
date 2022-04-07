// REFERENCE: https://www.thedshandbook.com/sorting-in-arrays/
// REFERENCE: https://leetcode.com/problems/sort-an-array/discuss/1884518/SIMPLE-C%2B%2B-SOLUTION-or-USING-MERGE-SORT-or-RECURSION

#include <vector>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        mergeSort(nums, low, high);
        return nums;
    }
    
    // NOT RECOMMENDED IN PRODUCTION ENVIRONMENTS
    // TIME COMPLEXITY: O(N^2)
    std::vector<int> bubbleSort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-i-1; j++) {
                if (nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        return nums;
    }
    
    // PERFORMS BETTER WHEN THE ARRAY IS NEARLY SORTED
    // TIME COMPLEXITY: O(N^2)
    std::vector<int> insertionSort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i=1; i<n; i++) {
            int temp = nums[i];
            int j = i-1;
            while (j>=0 && temp<nums[j]) {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
        return nums;
    }
    
    void merge(std::vector<int>& nums, int l, int h){
        int mid=l+(h-l)/2;
        
        int n1=mid-l+1;
        int n2=h-mid;
        
        int a[n1];
        int b[n2];

        int i = 0, j = 0, k = l;

        for(int i = 0; i < n1; i++) {
            a[i] = nums[i + l];
        }

        for(int j = 0; j < n2; j++) {
            b[j] = nums[mid + 1 + j];
        }

        while(i < n1 && j < n2) {
            if(a[i] <= b[j]) nums[k++] = a[i++];
            else nums[k++] = b[j++];
        }
        while(i < n1) 
            nums[k++] = a[i++];

        while(j < n2) 
            nums[k++] = b[j++];
        
    }
    
    // TIME COMPLEXITY: O(NlogN)
    void mergeSort(std::vector<int>& nums, int low, int high) {
        if(low>=high)
            return;
        
        int mid=low+(high-low)/2;
        
        //sorting the left part of the array
        mergeSort(nums, low, mid);
        
        //sorting the right part of the array
        mergeSort(nums, mid+1, high);
        
        //lastly merge the sorted arrays
        merge(nums, low, high);
    }
};