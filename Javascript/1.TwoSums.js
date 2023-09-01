// Time Complexity: O(N)
// Space Complexity: O(N)

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let hashmap = new Map();
    for (let idx = 0; idx < nums.length; ++idx) {
        remainder = target - nums[idx];
        if (hashmap.has(remainder)) {
            return [hashmap.get(remainder), idx]
        }
        hashmap.set(nums[idx], idx);
    }
    return [0, 1]
};
