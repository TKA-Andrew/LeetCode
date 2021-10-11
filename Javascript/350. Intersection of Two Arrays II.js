/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    if (nums1.length<nums2.length) {
        return intersect(nums2,nums1);
    }
    const map = new Map();
    for (const num of nums1) {
        map.set(num, (map.get(num) || 0) + 1)
    }
    const ans = [];
    for (const num of nums2) {
        if (map.has(num) && map.get(num) > 0 ) {
            map.set(num, map.get(num) - 1)
            ans.push(num)
        }
    }
    return ans
};