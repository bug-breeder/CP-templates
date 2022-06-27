#include <bits/stdc++.h>
using namespace std;

class fenwick_tree
{
private:
    vector<long long> data;
    int tree_size;

public:
    fenwick_tree(int tree_size = 0)
    {
        this->tree_size = tree_size;
        data.resize(tree_size + 1);
    }
    ~fenwick_tree() {}
    void update(int pos, long long val)
    {
        for (; pos <= tree_size; pos += pos & -pos)
            data[pos] += val;
    }
    long long query(int pos)
    {
        long long ret = 0;
        for (; pos > 0; pos -= pos & -pos)
            ret += data[pos];
        return ret;
    }
};
