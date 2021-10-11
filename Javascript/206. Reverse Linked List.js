/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

// Recursive approach
/*
var reverseList = function(head) {
    const updateListNode = function(currentNode, nextNode, newListNode) {
        if (nextNode.next !== null) {
            newListNode = new ListNode(nextNode.val, newListNode)
            currentNode = nextNode
            nextNode = currentNode.next
            newListNode = updateListNode(currentNode, nextNode, newListNode)
        } else {
            newListNode = new ListNode(nextNode.val, newListNode)
        }
        return newListNode
    }
    
    if (head === null) {
        return null
    }
    if (head.next === null) {
        return head
    }
    let currentNode = head
    let nextNode = currentNode.next
    let newListNode = new ListNode(currentNode.val)
    newListNode = updateListNode(currentNode, nextNode, newListNode)
    return newListNode
};
*/

// Iterative approach
var reverseList = function(head) {
    
    if (head === null) {
        return null
    }
    
    if (head.next === null) {
        return head
    }
    
    let currentNode = head
    let nextNode = currentNode.next
    let newListNode = new ListNode(currentNode.val)
    
    while (nextNode.next !== null) {
        newListNode = new ListNode(nextNode.val, newListNode)
        currentNode = nextNode
        nextNode = currentNode.next
    }
    
    return new ListNode(nextNode.val, newListNode) // add the last value to the first
};
