#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

const int maxm = 5e4;
const int maxn = 5e4;

// insight: the well can be seen as monotonous

int main() {
    int n, m;
    cin>>n>>m;
    
    stack<int> q;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        if (q.empty())
            q.push(temp);
        else
            q.push(min(q.top(), temp));
    }

    int ans = m;

    for (int j = 0; j < m; ++j) {
        cin>>temp;
        if (q.empty()) {
            continue;
        }
        while (!q.empty() && q.top() < temp) {
            q.pop();
        }
        if (q.empty()) {
            ans = j;
            continue;
        } else {
            q.pop();
            if (q.empty())
                ans = j + 1;
        }   
    }
    cout<<ans<<endl;
    return 0;
}