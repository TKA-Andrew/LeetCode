/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */

var orderlyQueue = function(s, k) {
    if (k > 1) {
       return s.split('').sort((a, b) => a.localeCompare(b)).join('');
    }
    let smallest = s
    for (let i = 0; i<s.length; i++) {
        s = `${s.slice(1)}${s[0]}`
        if (s.localeCompare(smallest) < 0) {
            smallest = s
        }
    }
    return smallest
};

// test
const testString1 = "cba"
const k1 = 1
console.log('TEST 1')
console.log('Expected Answer: acb')
console.log('Returned Answer:', orderlyQueue(testString1, k1))
const testString2 = "baaca"
const k2 = 3
console.log('TEST 2')
console.log('Expected Answer: aaabc')
console.log('Returned Answer:', orderlyQueue(testString2, k2))

