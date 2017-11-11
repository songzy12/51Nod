#include<iostream>
#include<deque>
#include<list>
#include<cassert>
#include<stdio.h>
using namespace std;

//deque<list<int>::iterator> q;
//list<int> l;
deque<int> q;

int k;
int sum1 = 0;
double sum2 = 0;

int b[101];

void insert(int v) {
    if (q.size() == k) {
        int t = q.front();
        sum1 -= t;
        sum2 -= t * t;
        b[t] --;
        q.pop_front();
    }
    sum1 += v;
    sum2 += v * v;
    b[v] ++;
    q.push_back(v);

    /*if (q.size() == k) {
        int t = *q.front();
        sum1 -= t;
        sum2 -= t * t;
        b[t] --;
        l.erase(q.front());
        q.pop_front();
    }
    list<int>::iterator iter = l.begin();
    while (iter != l.end() && *iter < v) {
        iter++;
    }
    q.push_back(l.insert(iter, v));
    sum1 += v;
    sum2 += v * v;
    b[v] ++;*/
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);
        int size = q.size();
        if (op == 1) {
            int v;
            scanf("%d", &v);
            insert(v);
        } else if (op == 2) {
            printf("%.2f\n", sum1 / size * 1.0);
        } else if (op == 3) {
            // caution! int -> double
            printf("%.2f\n", (sum2 - (sum1 * sum1) * 1.0 / size) / size);
        } else if (op == 4) {
            
                int w = q.size(), h = 0, p = w / 2;
                if(w & 1){
                    for(int i = 0;i <= 100; i++){
                        h += b[i];
                        if(h > p){
                            printf("%.2lf\n",(double)i);
                            break;
                        }
                    }
                }
                else{
                    int t = -1;
                    for(int i = 0;i <= 100; i++){
                        h += b[i];
                        if(h >=  p && t == -1) t = i;
                        if(h > p){
                            printf("%.2lf\n",(double)(t + i) / 2);
                            break;
                        }
                    }
                }

            //int cnt = 0;
            //list<int>::iterator iter = l.begin();
            //assert(q.size() == l.size());
            //if (q.size() % 2 == 1) {
            //    while (cnt < q.size() / 2) {
            //        iter++;
            //        cnt++;
            //    }
            //    int a = *iter;
            //    printf("%.2f\n", a * 1.0);
            //} else {
            //    while (cnt < q.size() / 2) {
            //        iter++;
            //        cnt++;
            //    }
            //    int a = *iter;
            //    int b = *(--iter); // caution! -- not ++
            //    printf("%.2f\n", (a + b) * 1.0 / 2);
            //}
        }
    }
    return 0;
}

// 51nod 大坑: 语言选择 "Visual C++" 而非 "C++ 11"

// 中位数的时候可以使用两个堆维护，删除元素时在 queue 里保存堆中指针
// 但是好像 priority_queue 没有按指针删除这个操作？
