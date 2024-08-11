#include<bits/stdc++.h>
using namespace std;
struct pp{
    int a,b;
};
int n,m,k,a,b,c,s=0,t,d[10090];
vector<pp>q[10090];
int ff(){

    queue<int>p;
    p.push(1);
    while(!p.empty()){
        t=p.front();
        p.pop();
        for(int i=0;i<q[t].size();i++){
            if(d[t]+1<d[q[t][i].b]){
                d[q[t][i].b]=d[t]+1;
                p.push(q[t][i].b);
            }
        }

    }
}

int main(){
    pp t2;
    float s2;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++){
        cin>>a>>b>>c;
        t2.a=a;
        t2.b=b;
        q[a][q[a].size()]=t2;
    }
    for(int i=0;i<n;i++){
        d[i]=999999999;
    }
    ff();
    cout<<d[n];
    fclose(stdin);
    fclose(stdout);



    return 0;
}
