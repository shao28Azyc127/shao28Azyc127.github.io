#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
struct Node{
    int a,b,c;
}x[100000];
bool cmp(Node p,Node q){
    return p.a > q.a;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    s1 = k;
    for(int i = 0;i < m;i++){
        cin>>x[i].a>>x[i].b>>x[i].c;
    }
    sort(x,x+m-1,cmp);
    int s = 2e10;
    for(int i = 0;i < m && x[i].a == 1;i++){
        for(int j = i+1;j < m;j++){
            if(s1 >= x[j].c && s1 >= x[j].c){
                int t = x[i].b;
                s1++;
                if(x[j].a == t){
                    t = x[j].b;
                    s1++;
                }
            }
        }
        s = min(s1,s);
    }
    if(s == 0 || s == 2e10){
        cout<<-1;
        return 0;
    }
    cout<<s;
    return 0;
}
