#include<bits/stdc++.h>
using namespace std;
long long n,m,k,d,energy;//day problem limit decrease
struct node {
    long long x,y,z;//the xth day,you have run y day, and then you can get z
}p[100010];
bool cmp (node a,node b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int main () {
    long long c,T;
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >>c>>T;
    while (T--) {
        energy=0;
        cin >>n>>m>>k>>d;
        for (int a=1;a<=m;a++) {
            cin >>p[a].x>>p[a].y>>p[a].z;
            long long l=p[a].x-p[a].y+1;
            p[a].y=p[a].x;
            p[a].x=l;
        }
        sort(p+1,p+1+m,cmp);
        bool opt=false;
        long long ll,rr;
        for (long long a=1;a<=m;a++) {
            long long l=p[a].y-p[a].x+1;
            if (l>k) continue;
            if (l*d>p[a].z) continue;
            energy=energy-l*d+p[a].z;
        }
        cout <<energy<<endl;
    }
    return  0;
}
