#include<bits/stdc++.h>
using namespace std;
int n,m,location[110],cnt;
string o[110];
map<string,int>q;//reflect from the string name of type to number type
struct node {
    string myname;
    int el,k;
    int t[110];
    string xname[110];
}point[110];
int gl (int x) {
    if (x==1) return 1;
    if (x==2) return 2;
    if (x==3) return 4;
    if (x==4) return 8;
    return point[x-4].el*point[x-4].k;
}
int main () {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >>n;
    q["byte"]=1;
    q["short"]=2;
    q["int"]=3;
    q["long"]=4;
    for (int a=1;a<=n;a++) {
        int opt;
        cin >>opt;
        if (opt==1) {
            m++;
            cin >>point[m].myname>>point[m].k;
            q[point[m].myname]=m+4;
            for (int b=1;b<=point[m].k;b++) {
                string t;
                cin >>t;
                point[m].t[b]=q[t];
                cin >>point[m].xname[b];
                point[m].el=max(point[m].el,gl(point[m].t[b]));//find the length of each type
            }
            cout <<point[m].el*point[m].k<<" "<<point[m].el<<endl;
        }
        if (opt==2) {
            cout <<location[cnt]<<endl;
            string t;
            cin >>t>>o[cnt];
            location[cnt+1]=location[cnt]+point[q[t]-4].el*point[q[t]-4].k;
            cnt++;
        }
    }
    return 0;
}
