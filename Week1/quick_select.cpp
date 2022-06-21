#include <bits/stdc++.h>
using namespace std;

int partion(vector<int> &v, int l, int r){
	int j = l ; // l - j < pivot, j - r >= pivot
	for(int i = l; i <= r; i++){
		if (v[i] < v[r]){
			swap(v[j], v[i]);
			j++;
		}

	}
	swap(v[j], v[r]);
	return j;


}


int quick_sort(vector<int> &v, int l, int r, int index) {
	if (l >= r) {
		return l;
	}

	int sz = (r - l + 1);
	int pivot = l + (rand() % sz);
	swap(v[pivot], v[r]);
	int part = partion(v, l, r);
	// q l - part-1, q part+1, r
	// k == part, k < part , k > part
	if(index == part){
		return v[part];
	}
	else if (index < part) {
		return quick_sort(v, l, part-1, index);
	}
	else{
		return quick_sort(v, part+1, r, index);
	}
	
}


int main() {
	#ifndef ONLINE_JUDGE
	// to take input from file input.txt
	freopen("input.txt", "r", stdin); 
	// To send output to output.txt 
	freopen("output.txt"    , "w", stdout); 
	#endif

	srand(time(0));
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin>>v[i];
	}

	cout<<quick_sort(v, 0, n-1, k-1)<<endl;;
	



	return 0;
}