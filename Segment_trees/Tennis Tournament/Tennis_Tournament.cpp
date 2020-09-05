#include <bits/stdc++.h>

using namespace std;

int ____ = [] () -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ( );



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    long long n, m;

    vector<long long> a;
    long long size_of_input;

    cin >> n >> m;
    size_of_input = n;

    a.reserve(size_of_input + 1);
    a.push_back(0);

    for (int i = 1; i <= size_of_input; ++i)
    {
        a[i] = i;
    }

    for (int i = 1; i <= m; ++i)
    {
        long long l, r, winner;

        cin >> l >> r >> winner;

        for (int j = l; j <= r; ++j)
        {
            if (a[j] == j && a[j] != winner) {
                a[j] = winner;
            } else if (a[winner] == winner && i == m) {
                a[winner] = 0;
            }
        }
    }

    for (int i = 1; i <= size_of_input; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
