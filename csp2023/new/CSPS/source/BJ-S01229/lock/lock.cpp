#include<bits/stdc++.h>
using namespace std;
#define hash has
int ans[1000005], n, a[10], hash, p;
bool book[1000005], bok[1000005];
void pp() {
    for(int j = 5; j; --j) {
        hash -= a[j] * p;
        for(int i = 9; ~i; --i) if(i ^ a[j]) {
            ++ans[hash + p * i];
            //cout<<hash + p * i<<endl;
        }
        hash += a[j] * p;
        p = (p << 3) + (p << 1);
    }
    p = 10;
    for(int j = 4; j; --j) {
        int aa = a[j + 1] - a[j];
        hash -= a[j] * p + a[j + 1] * p / 10;
        for(int i = 9; ~i; --i) if(i ^ a[j]) {
            //cout<<hash + p * i + p * ((i + aa + 10) % 10) / 10<<endl;
            ++ans[hash + p * i + p * ((i + aa + 10) % 10) / 10];
        }
        hash += a[j] * p + a[j + 1] * p / 10;
        p = (p << 3) + (p << 1);
    }
}
int check() {
    int ret = 0;
    p = 1;
    for(int j = 5; j; --j) {
        hash -= a[j] * p;
        for(int i = 9; ~i; --i) if(i ^ a[j] && ans[hash + p * i] == n - 1 && !bok[hash + p * i]) {
            ++ret;
            //bok[hash + p * i] = 1;
            //cout<<hash + p * i<<endl;
            //cout<<j<<" "<<i<<endl;
        }
        hash += a[j] * p;
        p = (p << 3) + (p << 1);
    }
    //cout<<ret<<endl;
    p = 10;
    for(int j = 4; j; --j) {
        int aa = a[j + 1] - a[j];
        hash -= a[j] * p + a[j + 1] * p / 10;
        for(int i = 9; ~i; --i) if(i ^ a[j] && ans[hash + p * i + p * ((i + aa + 10) % 10) / 10] == n - 1 && !bok[hash + p * i + p * ((i + aa + 10) % 10) / 10]) {
            ++ret;
            //bok[hash + p * i + p * ((i + aa + 10) % 10) / 10] = 1;
            //cout<<hash + p * i + p * ((i + aa + 10) % 10) / 10<<" "<<i<<" "<<j<<" "<<aa<<endl;
            //cout<<j<<" "<<i<<endl;
        }
        hash += a[j] * p + a[j + 1] * p / 10;
        p = (p << 3) + (p << 1);
    }
    return ret;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = n - 1; ~i; --i) {
        memset(book, 0, sizeof(book));
        p = 1;
        hash = 0;
        for(int j = 5; j; --j) {
            scanf("%d", a + j);
            hash += a[j] * p;
            p = (p << 3) + (p << 1);
        }
        //cout<<111111<<endl;
        p = 1;
        if(i) pp();
        else printf("%d", check());
    }
    return 0;
}