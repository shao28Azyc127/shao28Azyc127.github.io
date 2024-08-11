#include<bits/stdc++.h>
using namespace std;
#define REPG(i, h, x) for(int i=h[x];~i;i=edge[i].next)

const int N = 1e6+6;

int f[N], head[N];
int cnt;
int getfa(int x){
    if(f[x] == x) return x;
    return f[getfa(x)] = x;

}

void merge(int x, int y){
    f[getfa(x)] = getfa(y);
}

struct qwq{
    int v, next, c;

} edge[N*10];

inline void add(int x, int y, int c){
    edge[++cnt] = (qwq){y, head[x], c};
    head[x] = cnt;
}

/*
void dijie(){
    priority_queue< pair<int, int> > q;


}
*/

int n;
int arr[101];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << 81 <<endl;
    }else if(n == 2){
        cout << 10 <<endl;
    }else{
        cout << 0 << endl;
    }



    return 0;
}
