#include <bits/stdc++.h>
using namespace std;

class seg_tree
{
private:
    int tree_size;
    vector<int> tree;

public:
    void build(int id, int l, int r, vector<int> &data)
    {
        if (l == r)
        {
            tree[id] = data[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, data);
        build(id * 2 + 1, mid + 1, r, data);
        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if (r == l && r == pos)
        {
            tree[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(id * 2, l, mid, pos, val);
        else
            update(id * 2 + 1, mid + 1, r, pos, val);
        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
    }
    int query(int id, int l, int r, int L, int R)
    {
        if (R < l || r < L)
            return INT_MAX;
        if (L <= l && r <= R)
        {
            return tree[id];
        }
        int mid = (l + r) / 2;
        return min(query(id * 2, l, mid, L, R), query(id * 2 + 1, mid + 1, r, L, R));
    }

    seg_tree(int tree_size = 0)
    {
        this->tree_size = tree_size;
        // tree = new int[4 * tree_size + 4];
        tree.resize(tree_size*4+4);
    }

    seg_tree(vector<int> &a, int &n)
    {
        tree_size = n+1;
        // tree = new int[4 * tree_size + 4];
        tree.resize(n*4+4);
        build(1, 1, n, a); // from 1 to n
    }
    ~seg_tree()
    {
        // delete[] tree;
    }
};