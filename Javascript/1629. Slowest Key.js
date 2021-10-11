/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */

// Time Complexity: O(N)
// Space Complexity: O(1) as we are using constant extra space
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