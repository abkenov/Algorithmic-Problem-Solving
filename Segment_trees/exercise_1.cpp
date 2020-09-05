#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<long long> tree;

// long long power(long long a, long long  b) {

// 	long long result = a;

// 	for(long long i = 1; i < b; i++){
// 		result = result * a;
// 	}

// 	if(b == 0) return 1;

// 	return result;
// }

void build(vector<long long> &a, int v, int tl, int tr) {

	if(tl == tr){
		cout << tl << ",";
		tree[v] = a[tl];
	} else {
		long long tm = (tl + tr) / 2;

		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);

		tree[v] = max(tree[v*2], tree[v*2+1]);
		// tree[v] = tree[v*2] + tree[v*2+1];
	}
}

int sum(int v, int tl, int tr, int l, int r){
	if(l < r) return 0;
	if(l == tl && r == tr) return tree[v];

	int tm = (tl + tr) / 2;

	return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1 ,tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int winner) {
    if (tl == tr) {
    	if (tree[v] == winner)
        	tree[v] = 0;
        else
        	tree[v] = winner;

    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, winner);
        else
            update(v*2+1, tm+1, tr, pos, winner);
        // tree[v] = tree[v*2] + tree[v*2+1];
        if (tree[v] == v)
        	tree[v] = winner;
        if (tree[v] == winner)
        	tree[v] = 0;
    }
}

int main() {
	long long n, m;

	ifstream myinput;
	ofstream myoutput;
	vector<long long> a;
	long long size_of_input;

	myinput.open("input.txt");
	myoutput.open("output.txt");

	myinput >> n >> m;
	size_of_input = n;

	a.reserve(size_of_input + 1);
	a.push_back(0);
	tree.reserve(4 * size_of_input);

	for (int i = 1; i <= size_of_input; ++i)
	{
		a[i] = i;
	}

	build(a, 1, 1, size_of_input);

	for(int i = 0; i < size_of_input * 4; i++){
		cout << tree[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < m; i++){
		long long tl, tr, val;
		myinput >> tl >> tr >> val;

		update(1, tl, tr, val ,val);

		for (int i = 1; i < size_of_input * 4; ++i)
		{
			myoutput << tree[i] << " ";
		}
		myoutput << "\n";
	}

	myinput.close();
	myoutput.close();

	return 0;
}