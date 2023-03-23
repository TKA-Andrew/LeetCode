"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        self.dfs(root, ans)
        return ans

    def dfs(self, node: 'Node', ans: List):
        if node:
            ans.append(node.val)
            for child in node.children:
                self.dfs(child, ans)