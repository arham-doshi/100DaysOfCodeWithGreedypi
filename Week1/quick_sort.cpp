#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r) {
    int part = l;
    for(int i = l; i <= r; i++){
        if(v[i] < v[r]) {
            swap(v[part], v[i]);
            part++;
        }
    }
    swap(v[part], v[r]);
    return part;
}


void quick_sort(vector<int> &v, int l, int r) {

    if(l >= r) {
        return ;
    }

    int sz = r - l + 1;
    int pivot = l + (rand() % sz) ;
    
    swap(v[pivot], v[r]);
    int part = partition(v, l, r);
    quick_sort(v,l, part-1);
    quick_sort(v,part+1, r);
}


int main() {
    #ifndef ONLINE_JUDGE
    // to take input from file input.txt
    freopen("input.txt", "r", stdin); 
    // To send output to output.txt 
    freopen("output.txt"    , "w", stdout); 
    #endif

    srand(time(0));
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    quick_sort(v, 0, n-1);
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }



    return 0;
}