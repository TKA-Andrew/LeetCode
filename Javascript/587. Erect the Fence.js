// credit to: Anjali Rani Pahal https://www.youtube.com/watch?v=u27dS6Opv7o
// This is solved using Monotone Chain Algorithm
// For other alogrithms, please refer to https://leetcode.com/problems/erect-the-fence/solution/

/**
 * @param {number[][]} trees
 * @return {number[][]}
 */


// EXPLANATION
/*
    Let's say every 'x' represents a tree:

        9           x               x
        8                   x           x
        7
        6                   x
        5                                   x
        4                           x
        3           x           
        2   x               x       
        1
        0   1   2   3   4   5   6   7   8   9   
    
    We will have trees = [[1,2], [3,3], [5,2], [7,4], [9,5], [8,8], [7,9], [5,8], [5,6], [3,9]].
    Our expected answer will be [[1,2], [5,2], [9,5], [8,8], [7,9], [3,9]]

    1) We sort the trees according to their x coordinates. If they have same x coordinate, sort according to y coordinates
        sortedTrees = [[1,2], [3,3], [3,9], [5,2], [5,6], [5,8], [7,4], [7,9], [8,8], [9,5]]

    2) Now, we traverse through the sorted trees, and an array[] called 'hull' to push the coordinates of the trees. 
       We will get the fence's coordinates from lower part then upper part in anti clockwise direction.

    3) For every 2 latest trees in the hull and the next tree, we need to check whether their direction is in clockwise direction.
       If the next tree is in clockwise direction, it means it is a outer tree that should be fence.

        let's say we take the sorted trees is [treeP, treeQ, treeR]

                  treeR
               /  
        treeP   
               \ 
                  treeQ
        
                        treeQ[1] - treeP[1]
        gradientPQ = -----------------------------
                        treeQ[0] - treeP[0]

                        treeR[1] - treeP[1]
        gradientPR = -----------------------------
                        treeR[0] - treeR[0]

        difference in gradient = gradientPR - gradientPQ

        if (difference in gradient > 0) {
            means P -> Q -> R is in anti clockwise direction
        } else if (difference in gradient < 0) {
            means P-> Q -> R is in clockwise direction
        }

        Since we only want to know the sign of the difference instead of exact magnitude,
        we can simplify the equeation to:
            isClockwise = ((treeR[1] - treeP[1])*(treeQ[0] - treeP[0]) - (treeR[0] - treeP[0])*(treeQ[1] - treeP[1])) < 0

    4) Now we can use the above equation to know whether the direction of latest 3 trees are in clockwise direction,
       If yes, we will remove the tree from our hull.

       For example, in third loop, we already have [1,2] and [3,3] in our hull array, and we are checking it with the [3,9] tree:

        9           c               x
        8                   x           x
        7
        6                   x
        5                                   x
        4                           x
        3           h           
        2   h               x       
        1
        0   1   2   3   4   5   6   7   8   9   
        
        from [1,2] -> [3,3] -> [3,9] it is obviously anti-clockwise direction, so we will not remove last tree in hull, 
        and will push the [3,9] into hull.

        Now in the fourth loop, we will check [3,3], [3,9] and [5,2]:

        9           h               x
        8                   x           x
        7
        6                   x
        5                                   x
        4                           x
        3           h           
        2   h               c       
        1
        0   1   2   3   4   5   6   7   8   9   

        from [3,3] -> [3,9] -> [5,2] it is in clockwise direction, so we should remove the last tree in hull:
            hull.pop() then we will get hull = [[1,2], [3,3]]

        Now, we still have 2 trees in hull can be checked with the [5,2] tree:

        9           x               x
        8                   x           x
        7
        6                   x
        5                                   x
        4                           x
        3           h           
        2   h               c       
        1
        0   1   2   3   4   5   6   7   8   9   

        from [1,2] -> [3,3] -> [5,2] it is in clockwise direction as well, so we should remove the last tree in hull:
            hull.pop() then we will get hull = [[1,2]]

        Now we only have one tree in hull, which is not enough for checking direction, so we will push [5,2] into hull first.
            hull.push([5,2]) then we will get hull = [[1,2], [5,2]]

        9           x               x
        8                   x           x
        7
        6                   x
        5                                   x
        4                           x
        3           x           
        2   h               h       
        1
        0   1   2   3   4   5   6   7   8   9   

        That's how we get the lower hull. When reach the last tree in trees, we will have this:

        9           x               x
        8                   x           x
        7
        6                   x
        5                                   h
        4                           x
        3           x           
        2   h               h       
        1
        0   1   2   3   4   5   6   7   8   9 

    5) Now, we need to get the upper hull. We will traverse the trees in reverse direction, 
       except the last tree because it is already been included: for (let i = trees.length - 2; i >= 0; i--)

    6) The process in step 5 is the same as step 4. We are looking for trees' coordinates that form largest anti-clockwise circle.

    7) Then, we need to remove the duplicates from the array. And that's how we get the answer.

*/

var outerTrees = function(trees) {
    
    // sort according to x coordinates
    // if x coordinates are the same, sort according to y coordinates
    trees = trees.sort(function(a, b) {
      if (a[0] == b[0]) {
        return a[1] - b[1];
      }
      return a[0] - b[0];
    });
    
    const isClockwise = function (treeP, treeQ, treeR) {
         return ((treeR[1] - treeP[1])*(treeQ[0] - treeP[0]) - (treeR[0] - treeP[0])*(treeQ[1] - treeP[1])) < 0
    }
    
    const hull = []
    
    for (let i = 0; i < trees.length; i++) {
        while(hull.length>=2 && isClockwise(hull[hull.length - 2], hull[hull.length-1], trees[i])) {
            hull.pop(); // pop if the trees are in clockwise direction
        }
        hull.push(trees[i])
    }
    
    for (let i = trees.length-2; i >= 0; i--) { // trees.length - 2 is to skip the last tree that is included in hull
        while(hull.length>=2 && isClockwise(hull[hull.length - 2], hull[hull.length-1], trees[i])) {
            hull.pop(); // pop if the trees are in clockwise direction
        }
        hull.push(trees[i])
    }

    const uniqueHullSet = new Set(hull) // to remove duplicates by converting array to set
    const fence = Array.from(uniqueHullSet) // convert set to array
    return fence

};

// test
const trees = [[1,2], [3,3], [5,2], [7,4], [9,5], [8,8], [7,9], [5,8], [5,6], [3,9]]
const expectedAnswer = [[1,2], [5,2], [9,5], [8,8], [7,9], [3,9]]
console.log(outerTrees(trees))