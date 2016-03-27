#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  int tmp;
  while( a != 0 ){
    tmp = a;
    a = b % a;
    b = tmp;
  }
  return b;
}

int main() {
  unordered_set<int> set;
  long long n, m;
  cin>>n>>m;
  // to test the if the input is correct
  // cout<<(bool)cin.good()<<endl;

  int c_n = 0, c_m = 0, c_com = 0;

  int i = 1;
  for( i = 1; i < sqrt(n); ++i)
    if(n % i == 0) {
      c_n += 2;
      set.insert(i);
      set.insert( n / i);
    }

  if( i * i  == n ) {
    ++c_n;
    set.insert(i);
  }

  for( i = 1; i < sqrt(m); ++i) 
    if( m % i == 0 ) {
      c_m += 2;
      if( set.find(i) != set.end() ) ++c_com;
      if( set.find(m/i) != set.end() ) ++c_com;
    }

  if( i * i == m ) {
    ++c_m;
    if(set.find(i) != set.end() ) ++c_com;
  }

  int d = gcd( c_n*c_m, c_com);

  cout<< c_n*c_m/d<<' '<<c_com/d<<endl;

  return 0;
}
 
