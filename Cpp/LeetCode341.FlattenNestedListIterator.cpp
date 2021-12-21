#include <queue>
#include <vector>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    std::queue<int> q;
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        for (const auto& nestedEle:nestedList) {
            enque_helper(nestedEle);
        }
    }
    
    void enque_helper(const NestedInteger &nestedEle) {\
        if (nestedEle.isInteger()) {
                q.push(nestedEle.getInteger());
        } else {
            for (const auto& subEle:nestedEle.getList()) {
                enque_helper(subEle);    
            }
        }

    }
    
    int next() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */