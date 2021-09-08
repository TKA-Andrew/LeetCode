/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */

// Time Complexity: O(N)
// Space Complexity: O(N)
 var shiftingLetters = function(s, shifts) {

    const hashTableEncode = {
        a: 0,
        b: 1,
        c: 2,
        d: 3,
        e: 4,
        f: 5,
        g: 6,
        h: 7,
        i: 8,
        j: 9,
        k: 10,
        l: 11,
        m: 12,
        n: 13,
        o: 14,
        p: 15,
        q: 16,
        r: 17,
        s: 18,
        t: 19,
        u: 20,
        v: 21,
        w: 22,
        x: 23,
        y: 24,
        z: 25
    }
    const decodeString = "abcdefghijklmnopqrstuvwxyz"
    const encodedList = Array(s.length).fill(0)

    let addition = 0

    for (let i = s.length -1; i>=0 ; i--) {
        addition = addition + shifts[i]
        const num = hashTableEncode[s[i]]+ addition
        encodedList[i] = decodeString[num%26]
    }

    return encodedList.join('')
};