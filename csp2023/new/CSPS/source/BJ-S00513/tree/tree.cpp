#include<bits/stdc++.h>
using namespace std;
struct tree{
    int a,b,c;
    int flag=0,o;
}t[1000001];
bool cmp(tree a,tree b){
    if(a.a>b.a){
        return 1;
    }
}
int n,start,en,road[100001],day=0,f=1,al,p;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
        t[i].o=i;

    }
    for(int i=1;i<n;i++){
        cin>>start>>en;
        road[start]=en;
    }

    sort(t+1,t+n+1,cmp);
    for(int k=0;k<=1000000;k++){
        day++;
        t[1].flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=day;j++){
                t[j].a-=max(t[j].b+day*t[j].c,1);
            }
            for(int j=1;j<=n;j++){
                if(road[i]==t[j].o){
                    t[j].flag=1;
                    break;
                }
            }
            for(int j=1;j<=n;j++){
                al+=t[i].a;
            }
            if(al<=0) break;
        }
        
        break;
    }

    cout<<day;
    return 0;
}