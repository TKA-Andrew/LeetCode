/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */



// CONSTRAINTS
/*
    - 1 <= n <= 3 * 104
    - edges.length == n - 1
    - edges[i].length == 2
    - 0 <= ai, bi < n
    - ai != bi
    - The given input represents a valid tree.
*/

// credit to: CAT RACKET DCODE https://www.youtube.com/watch?v=IyyApc1Tfs8
// credit to: Tianyu Qi https://github.com/tyqi11/leetcode/blob/master/834_Sum_of_Distances_in_Tree.java

// EXPLANATION
/*
            0
          /   \
         1     2
            /  |  \
           3   4   5

    We use count[i] array to record the number of child nodes including itself at each node i
        for example, count[2] = 4, count[3] = 1
    In the first DFS:
        We use res[i] array to store sum of distances from the node i to its children.
    In the second DFS:
        We change res[i] to sum of distances from all other nodes.
    
    In the first DFS, since node 0,3,4 and 5 don't have children, we will get:
            res[0] = 0
            res[3] = 0
            res[4] = 0
            res[5] = 0
        then, res[2] = res[3] + 1 + res[4] + 1 + res[5] + 1 = 3

        The "+1" above is the distance between node 2 and node 3,4,5
        And from this we can say that:
            res[2] = res[3] + count[3] + res[4] + count[4] + res[5] + count[5]

        Similary, we can get res[0] = res[1] + count[1] + res[2] + count[2] = 0 + 1 + 3 + 4 = 8

        Hence, in the first DFS, we will get:
            res[0] = 8 // correct answer
            res[1] = 0 // temporarily wrong answer
            res[2] = 3 // temporarily wrong answer
            res[3] = 0 // temporarily wrong answer
            res[4] = 0 // temporarily wrong answer
            res[5] = 0 // temporarily wrong answer
    
    In the second DFS:
        Now, we only have res[0] is correct. To find the correct res[2]:
            res[2] = res[root] + (-1 * count[2]) + (1*NumberOfNodes - count[2])
        The (-1*count[2]) is because node2 is 1 step closer to its children including itself
        as compared to node0. 
            For example, from node0 to node3 is 2 steps, but node2 to node3 is 1 step.
        Then, the (1*NumberOfNodes - count[i]) is to add the extra 1 step distance from the node2
        to the remaining of the nodes.
            For example, from node1 to node0 is 1 step, but node0 to node2 is 2 steps.
        Then we can say that:
            res[2] = res[0] - count[2] + n - count[2] = 8 - 4 + 6 - 4 = 6
            res[3] = res[2] - count[3] + n - count[3] = 6 - 1 + 6 - 1 = 10
        In general:
            res[child] = res[current] - count[child] + n - count[child]
*/

// Time Complexity: O(N), but 2 times traversal
// Space Complexity: O(N)
var sumOfDistancesInTree = function(n, edges) {
    if (edges.length === 0) {
        return [0]
    }
    let graph = {}; // this graph is to record all the neighbouring nodes of a node
    // parent node is considered as neighbour node as well, but it will be checked when DFS is running
    for (let i = 0; i<edges.length; i++) {
        let edge = edges[i]
        if (graph[edge[0]] === undefined) {
            graph[edge[0]] = []
        }
        graph[edge[0]].push(edge[1])
        if (graph[edge[1]] === undefined) {
            graph[edge[1]] = []
        }
        graph[edge[1]].push(edge[0])
    }
    let count = new Array(n).fill(1) // count by default added itself
    let res = new Array(n).fill(0)
    
    // Bottom-Up Depth-First Search
    // Recursive function that starts from root node, but get value of parent node from child node
    const bottomUpDFS = function (node, parent) {
        const children = graph[node]
        for (const child of children) {
            if (child !== parent) { // because parent is added to graph as well, so need to check
                bottomUpDFS(child, node) // get count[child] and res[child] before using them
                count[node] += count[child]
                res[node] += res[child] + count[child]
            }
        }
    }
    
    // Top-Down Depth-First Search
    // Recursive function that starts from root node, and get value of child node from parent node
    const topDownDFS = function (node, parent) {
        const children = graph[node]
        for (const child of children) {
            if (child !== parent) {
                // get res[child] before proceeding to the lower level through topDownDFS()
                res[child] = res[node] - count[child] + n - count[child]
                topDownDFS(child, node)
            }
        }
    }
    
    bottomUpDFS(0,-1)
    topDownDFS(0,-1)
    return res
    
};

// test
const n = 6
const edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
const expectedAnswer = [8,12,6,10,10,10]
console.log(sumOfDistancesInTree(n, edges))