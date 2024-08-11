#include <iostream>
using namespace std;
short road[10001][10001];
bool now[10001];
int n,m,k,a,b,t;
bool find=true;
void visit(int s){
    if(s==n){
        find=false;
        return ;
    }
    now[s]=true;
    for(int i=1;i<=n;i++){
        if(!now[i]&&road[s][i]&&road[s][i]<=t){
            visit(i);
        }
        if(!find) return ;
    }
    now[s]=false;
    return ;
}
int main(){
    freopen("bus.in",'r',stdin);
    freopen("bus.out",'w',stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>a>>b>>t;
    	road[a][b]=t;
    }
    t=0;
    while(true){
        visit(1);
        if(!find){
            cout<<t;
            return 0;
        }
        t+=k;
    }
    return 0;
}