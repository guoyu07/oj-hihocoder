#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

using Item = pair<int, int>;
using Items = vector<Item>;

int zero_one_pack(int total, Items &items) {

  vector<int> res(total+1, 0);

  for( int i = 0; i < (int)items.size(); ++i) {
    for( int j = total; j >= items[i].first; --j)
      res[j] = max(res[j], res[j-items[i].first] + items[i].second);
  }

  return res.back();
}

int main() {
  int cnt, total;
  cin>>cnt>>total;

  Items items;
  int cost, worth;
  for( int i = 0; i < cnt; ++i) {
    cin>>cost>>worth;
    items.push_back({cost, worth});
  }

  cout<<zero_one_pack(total, items);

  return 0;

}
