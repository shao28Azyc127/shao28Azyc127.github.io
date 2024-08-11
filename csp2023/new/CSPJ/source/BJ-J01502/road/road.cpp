#include<bits/stdc++.h>
using namespace std;

int n,d,x,c,t,m;

struct node{
    int a,v;
}a[100010];

int main(){
    int i,j;

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> d;

    for(i = 1;i <= n - 1;i++){
        cin >> a[i].a;
    }

    for(i = 1;i <= n;i++){
        cin >> a[i].v;
    }

    x = 1;

    while(x != n){
        i = x + 1;
        t = a[i - 1].a;
        while(a[i].v >= a[x].v && i < n){
            i++;
            t += a[i - 1].a;
        }
        c += a[x].v * ceil((t - m) * 1.0 / d);
        m += ceil((t - m) * 1.0 / d) * d - t;
        x = i;
//        cout << x << " " << t << " " << c << " " << m << endl;
    }

    cout << c << endl;
}