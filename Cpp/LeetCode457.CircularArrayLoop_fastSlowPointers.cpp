#include <vector>

class Solution {
public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int N = nums.size();
        for (int i=0; i<N; i++) {
            int slow = i;
            int fast1 = getNextIdx(i, nums);
            if (!sameSign(nums[slow], nums[fast1]) || slow==fast1){
                continue;
            }
            int fast2 = getNextIdx(fast1, nums);
            if (!sameSign(nums[fast1], nums[fast2]) || fast1==fast2){
                continue;
            }
            int numElementVisited = 0;
            while (numElementVisited<=N) {
                slow = getNextIdx(slow, nums);
                fast1 = getNextIdx(fast2, nums);
                if (!sameSign(nums[slow], nums[fast1])){
                    break;
                }
                fast2 = getNextIdx(fast1, nums);
                if (!sameSign(nums[fast1], nums[fast2]) || fast1 == fast2){
                    break;
                }
                if (slow==fast2) {
                    return true;
                }
                numElementVisited++;
            }
        }
        return false;
    }
    
    int getNextIdx(int currentIdx, std::vector<int>& nums) {
        int jump = nums[currentIdx];
        int nextIdx = (currentIdx + jump) % (int)nums.size();
        return nextIdx >= 0 ? nextIdx : nextIdx + (int)nums.size();
    }
    
    bool sameSign(int num1, int num2) {
        return (num1<0&&num2<0) || (num1>=0&&num2>=0);
    }
};