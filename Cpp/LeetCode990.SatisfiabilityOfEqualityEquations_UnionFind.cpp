#include <vector>
#include <string>

class UnionFind {
    private:
        int count;
        std::vector<int> parent = std::vector<int> (26);
        std::vector<int> size= std::vector<int> (26);
    
      int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    public:
        UnionFind(int n) {
            this->count = n;
            for (int i =0;i<n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
    

    
       bool connected(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }
    
       void connect(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP==rootQ) {
                return;
            }
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
        }
    
        int getCount() {
            return count;
        }
};

class Solution {
public:
    bool equationsPossible(std::vector<std::string>& equations) {
        UnionFind* uf = new UnionFind(26);
        for (auto eq:equations) {
            if (eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf->connect(x-'a',y-'a');
            }
        }
        for (auto eq:equations) {
            if (eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                if (uf->connected(x-'a',y-'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};