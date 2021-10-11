/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */

// Time Complexity: O(N), but sorting is another extra traversal
// Space Complexity = O(K) where K is number of keys with same longest duration
// var slowestKey = function(releaseTimes, keysPressed) {
//     let longestDuration = releaseTimes[0]
//     let longestKeyList = [keysPressed[0]]
//     for (let i = 1; i < releaseTimes.length; i++) {
//         const duration = releaseTimes[i] - releaseTimes[i-1]
//         if (duration > longestDuration) {
//             longestDuration = duration
//             longestKeyList = []
//             longestKeyList.push(keysPressed[i])
//         } else if (duration === longestDuration) {
//             longestKeyList.push(keysPressed[i])
//         }
//     }
//     if (longestKeyList.length === 1) return longestKeyList[0]
//     longestKeyList.sort()
//     return longestKeyList[longestKeyList.length-1]
// };

// Time Complexity: O(N)
// Space Complexity: O(1) as we only store a character no matter how many keys with same longest duration
var slowestKey = function(releaseTimes, keysPressed) {
    let longestDuration = releaseTimes[0]
    let longestKey = keysPressed[0]
    
    for (let i = 1; i < releaseTimes.length; i++) {
        const duration = releaseTimes[i] - releaseTimes[i-1]
        if (duration > longestDuration || (duration === longestDuration && keysPressed[i] > longestKey)) {
            longestDuration = duration
            longestKey = keysPressed[i]
        }
    }
    
    return longestKey
};