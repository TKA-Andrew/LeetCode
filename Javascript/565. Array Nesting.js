// Submission Result on 2-9-2021 1:10AM:
/*
Runtime: 88 ms, faster than 94.12% of JavaScript online submissions for Array Nesting.
Memory Usage: 41.9 MB, less than 85.29% of JavaScript online submissions for Array Nesting.
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
 var arrayNesting = function(nums) {
    let maxCount = 0
    for (let i=0; i<nums.length; i++) {
        let value = nums[i]
        let count = 0
        let idx = i
        while (nums[idx] !== -1) {
            nums[idx] = -1
            count ++
            if (count > maxCount) {
                maxCount = count
            }
            idx = value
            value = nums[idx]
        }
    }
    return maxCount
};

// test
const nums = [5,4,0,3,1,6,2]
console.log(arrayNesting(nums))