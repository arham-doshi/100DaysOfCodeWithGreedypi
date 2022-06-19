#include <bits/stdc++.h>
using namespace std;

// We will try to make the arr monotonically increasing.
// If an element at index i is less than the element at index i-1 then,
// least number to make array sorted will be equal to the number at i-1.


int main()
{    
  
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
   
  }
  
  long long ans=0;
  for (int i = 1; i < n; i++){
  	if (v[i] < v[i-1]) {
  		long long increment = v[i-1] - v[i];
  		v[i] += increment;
  		ans += increment;
  	}

  }

  cout<<ans<<endl;
    return 0;
}