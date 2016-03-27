#include <iostream>
#include <vector>
using namespace std;

int main() {
  int cnt, tmp;
  vector<int> nums;

  cin>>cnt;
  for(int i = 0; i < cnt; ++i ) {
    cin>>tmp;
    nums.push_back(tmp);
  }

  int i = cnt -1;
  for(; i > 0; --i)
    if( nums[i-1] > nums[i] ) break;

  if( i == 0 ) ++i;

  for(int j = 0; j < i; ++j)
    cout<<nums[j]<<' ';

  return 0;
}
