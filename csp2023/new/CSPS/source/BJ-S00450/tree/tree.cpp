#include<bits/stdc++.h>
using namespace std;

int n;
struct node{
    int g;
    int cli;
    int gro;
}a[1010];
int t[1010];
bool f[1000][1000];
bool b[1000];
int mi=INT_MAX;

void dfs(int x,int idx){
    if(x>40){
        return;
    }
    bool p=true;
    for(int i=1;i<=n;i++){
        if(a[i].g>t[i]) p=false;
    }
    if(p){
        mi=min(mi,x);
        return;
    }

    for(int i=1;i<=n;i++){
        if(f[i][idx]){
            for(int i=1;i<=n;i++){
                if(b[i]){
                    t[i]+=max(a[i].cli+x*a[i].gro,1);
                }
            }
            b[i]=true;
            dfs(x+1,i);
            b[i]=false;
            for(int i=1;i<=n;i++){
                if(b[i]){
                    t[i]-=max(a[i].cli+x*a[i].gro,1);
                }
            }
        }
        if(f[idx][i]){
            for(int i=1;i<=n;i++){
                if(b[i]){
                    t[i]+=max(a[i].cli+x*a[i].gro,1);
                }
            }
            b[i]=true;
            dfs(x+1,i);
            b[i]=false;
            for(int i=1;i<=n;i++){
                if(b[i]){
                    t[i]-=max(a[i].cli+x*a[i].gro,1);
                }
            }
        }
    }
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].g>>a[i].cli>>a[i].gro;
    }
    int x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        f[x][y]=true;
    }

    b[1]=true;
    dfs(1,1);
    cout<<mi+1;

	fclose(stdin);
	fclose(stdout);
}
