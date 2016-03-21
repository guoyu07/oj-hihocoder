#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// require: vec are sorted in ascending order
int bin_search(int target, vector<int> &vec) {
    int l = 0, r = vec.size() - 1;
    
    while(l <= r) {
        int m = (l+r) / 2;
        if(target == vec[m]) return m + 1;
        else if(target > vec[m])
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

// sort version
int main() {
    // input
    int size, target;
    vector<int> vec;
    cin>>size>>target;
    for(int i = 0; i < size; ++i) {
        int num;
        cin>>num;
        vec.push_back(num);
    }
    
    // sort
    sort(vec.begin(), vec.end());

    // search
    cout<<bin_search(target, vec);
    
    return 0;
}

// TODO: non-sort version 
