#include <bits/stdc++.h>


using namespace std;

int ____ = [] () -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ( );


const int maxN = 3e5;
vector<int> a(maxN);
vector<vector<int>> tree(4*maxN);

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].push_back(a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(tree[v*2].begin(), tree[v*2].end(), tree[v*2+1].begin(), tree[v*2+1].end(), back_inserter(tree[v]));
    }
}

int find_heaviest (int v, int tl, int tr, int l, int r, int bag) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        vector<int>::iterator position = upper_bound(tree[v].begin(), tree[v].end(), bag);
        
        if (position != tree[v].begin())
            return *(--position);
        return 0;
    }
    int tm = (tl + tr) / 2;
    return max(find_heaviest(v*2, tl, tm, l, min(r, tm), bag), 
               find_heaviest(v*2+1, tm+1, tr, max(l, tm+1), r, bag));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, Q;

    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    build(a, 1, 0, N-1);
    string output = "";

    for (int i = 0; i < Q; ++i) {
        int l ,r, bag;
        cin >> l >> r >> bag;

        output.append(to_string(find_heaviest(1, 0, N-1, l, r, bag)) + "\n");        
    }

    cout << output;

    return 0;
}