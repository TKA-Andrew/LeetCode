/**
 * @param {string} text
 * @return {number}
 */

// using Javascript Map
var maxNumberOfBalloons = function(text) {
    const map = new Map();
    map.set('b', 0);
    map.set('a', 0);
    map.set('l', 0);
    map.set('o', 0);
    map.set('n', 0);

    for (const ch of text) {
        if (map.has(ch)) {
            map.set(ch, map.get(ch) + 1);
        }
    }
    let minimum = map.get('b') //get anyone as minimum
    map.set('l', Math.floor(map.get('l')/2));
    map.set('o', Math.floor(map.get('o')/2));
    for (const [ch,value] of map) {
        if (value < minimum) {
            minimum = value;
        }
    }
    return minimum;
};

// using Javascript Object
// var maxNumberOfBalloons = function(text) {
//     const hashTable = {
//         b: 0,
//         a: 0,
//         l: 0,
//         o: 0,
//         n: 0
//     }    

//     for (const ch of text) {
//         if (hashTable[ch] !== undefined) {
//             hashTable[ch] = hashTable[ch] + 1
//         }
//     }
//     let minimum = hashTable['b'] //get anyone as minimum
//     hashTable['l'] = Math.floor(hashTable['l']/2)
//     hashTable['o'] = Math.floor(hashTable['o']/2)
//     console.log(hashTable)
//     for (const key in hashTable) {
//         const value = hashTable[key]
//         if (value < minimum) {
//             minimum = value;
//         }
//     }
//     return minimum;
// };