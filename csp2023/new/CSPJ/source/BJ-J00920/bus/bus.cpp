#include<fstream>

using namespace std;

ifstream cin ("bus.in");
ofstream cout ("bus.out");
const int N = 1e4 + 10,M = 2e4 + 10,K = 3e6 + 10;
struct node {
    int to;
    int next;
} a[M];
long long mi,p,n,m,k,u[M],v[M],ab[M],h[M],q[K],b[K],he,t;

void add(int aa,int bb){
    p ++;
    a[p].to = bb;
    a[p].next = h[aa];
    h[aa] = p;
}

void bfs(int x){
    he = t = 1;
    q[he] = 1;
    b[he] = x;
    while(he <= t){
        long long ta = q[he];
        long long tb = b[he];
        if(ta == n){
            int ccc = tb / k;
            if(ccc * k == tb){
                cout << tb << endl;
                exit(0);
            }
        }
        for(int i = h[ta];i v!= 0;i = a[i].next){
            int to = a[i].to;
            t ++;
            if(tb + 1 < ab[to]){
                continue;
            }
            q[t] = to;
            b[t] = tb + 1;
        }
        he ++;
    }
}

int main(){
    cin >> n >> m >> k;
    mi = 1000000;
    for(int i = 1;i <= m;i ++){
        cin >> u[i] >> v[i] >> ab[i];
        mi = min(mi,ab[i]);
        add(u[i],v[i]);
    }
    int mii = mi / k;
    for(int i = mii * k;i <= 1000000;i = i + k){
        for(int j = 1;j < K;j ++){
            q[j] = b[j] = 0;
        }
        bfs(i);
    }
    cout << "-1" << endl;
    return 0;
}
