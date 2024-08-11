#include<bits/stdc++.h>
using namespace std;
const int N = 3009;
int n, m, cnt=1;
int ans[N];
struct node{
    int t, loc;
    vector<int> s;
}a[N<<1];
bool cmp(node a, node b){
    if(a.s!=b.s) return a.s < b.s;
    if(a.loc==b.loc) return a.t < b.t;
    else return a.t > b.t;
}
bool cmpint(int a, int b){
    return a > b;
}
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin>>n>>m;
    char c;
    for(int i=1; i<=n; ++i){
        while(c<'a' || c>'z') c = getchar();
        for(int j=1; j<=m; ++j){
            a[cnt].s.push_back(c-'a');
            a[cnt].loc = i;
            a[cnt].t = 0;
            a[cnt+1].s.push_back(c-'a');
            a[cnt+1].loc = i;
            a[cnt+1].t = 1;
            c = getchar();
        }
        cnt += 2;
    }
    --cnt;
    for(int i=1; i<=cnt; ++i){
        if(a[i].t) sort(a[i].s.begin(), a[i].s.end(), cmpint);
        else sort(a[i].s.begin(), a[i].s.end());
    }
    sort(a+1, a+cnt+1, cmp);
    for(int i=1; i<=cnt; ++i){
        if(a[i].t) break;
        ans[a[i].loc] = 1;
    }
    for(int i=1; i<=n; ++i){
        printf("%d", ans[i]);
    }putchar('\n');
    return 0;
}






    //for(int i=1; i<=cnt; ++i){
    //    cout<<"loc = "<<a[i].loc<<" t = "<<a[i].t<<endl;
    //    for(int j=0; j<m; ++j){
    //        cout<<char(a[i].s[j]+'a');
    //    }
    //    cout<<endl;
    //}