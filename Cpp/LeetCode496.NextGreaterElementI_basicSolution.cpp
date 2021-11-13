#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        int N = nums1.size();
        std::vector<int> ans(N,-1);
        for (int i=0;i<N;i++) {
            int num1 = nums1[i];
            bool found=false;
            for (const auto num2: nums2) {
                if (num2==num1) {
                    found = true;
                }
                if (found && num2>num1) {
                    ans[i]=num2;
                    break;
                }
            }
        }
        return ans;
    }
};