// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1191

#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 50000;
const int maxm = 50000;

int rabbit[maxn+5];
pair<int, int> arrow[maxm+5];
int father[maxn+5];

int n, m;

int find_index(int demage) {
    return upper_bound(rabbit, rabbit+n, demage) - rabbit - 1;
}

int union_find(int index) {
    while (index != -1 && father[index] != index) {
        if (father[index] != -1) 
            father[index] = father[father[index]];
        index = father[index];
    }
    if (index >= 0) {
        int index_ = index - 1;
        while (index_ != -1 && father[index_] != index_) {
            if (father[index_] != -1)
                father[index_] = father[father[index_]];
            index_ = father[index_];
        }
        father[index] = index_;
    } 
    return index;
}

bool find(int demage) {
    int index = find_index(demage);
    index = union_find(index);
    return index >= 0;
}

long long solve() {
    sort(rabbit, rabbit + n);
    sort(arrow, arrow + m);

    for (int i = 0; i < n; ++i)
        father[i] = i;

    int cnt = 0;
    long long ans = 0;

    for (int i  = 0; i < m; ++i) {
        int demage = -arrow[i].second;
        int price = arrow[i].first;
        if (find(demage)) {
            cnt ++;
            ans += price;
            if (cnt == n)
                return ans;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &rabbit[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &arrow[i].second, &arrow[i].first);
        arrow[i].second *= -1; // to sort by inversed demage
    }
    long long ans = solve();
    if (ans)
        printf("%lld\n", solve());
    else
        printf("No Solution\n");
}

// start from the rabbit with the most blood
// then find the arror with the least price that can kill it

// sort the arrow based on (price, demage)
// kill the rabbit with the most blood

// sort the rabbit
// for each arrow, binary search for the rabbit with the most blood

// union set with the avaliable index before this rabbit