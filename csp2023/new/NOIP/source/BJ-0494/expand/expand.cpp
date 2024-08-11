#include<bits/stdc++.h>
using namespace std;
long long n,m,c,q,x[110000],y[110000],xx[110000],yy[110000],flag;
void dfs1(int pos1,int pos2){
    if(flag) return ;
    if(pos1==n&&pos2==m){
        flag=1;
        return ;
    }
    int posx=pos1,posy=pos2;
    while(xx[posx+1]>yy[posy]){
        if(posx<n){
            //cout << posx << " " << posy << "\n";
            posx++;
            dfs1(posx,posy);
        }
        if(flag) return ;
        if(posx==n) break;
    }
    posx=pos1,posy=pos2;
    while(xx[posx]>yy[posy+1]){
        if(posy<m){
            //cout << posx << " " << posy << "\n";
            posy++;
            dfs1(posx,posy);
        }
        if(flag) return ;
        if(posy==m) break;
    }
    if(flag) return ;
    return ;
}
void dfs2(int pos1,int pos2){
    if(flag) return ;
    if(pos1==n&&pos2==m){
        flag=1;
        return ;
    }
    int posx=pos1,posy=pos2;
    while(xx[posx+1]<yy[posy]){
        if(posx<n){
            //cout << posx << " " << posy << "\n";
            posx++;
            dfs2(posx,posy);
        }
        if(flag) return ;
        if(posx==n) break;
    }
    posx=pos1,posy=pos2;
    while(xx[posx]<yy[posy+1]){
        if(posy<m){
            //cout << posx << " " << posy << "\n";
            posy++;
            dfs2(posx,posy);
        }
        if(flag) return ;
        if(posy==m) break;
    }
    if(flag) return ;
    return ;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=m;i++) cin >> y[i];
    for(int i=0;i<=q;i++){
        flag=0;
        for(int j=1;j<=n;j++){
            xx[j]=x[j];
        }
        for(int j=1;j<=m;j++){
            yy[j]=y[j];
        }
        if(i){
            int k1,k2;
            cin >> k1 >> k2;
            for(int j=1;j<=k1;j++){
                int q,w;
                cin >> q >> w;
                xx[q]=w;
            }
            for(int j=1;j<=k2;j++){
                int q,w;
                cin >> q >> w;
                yy[q]=w;
            }
        }
        if(xx[1]==yy[1]){
            cout << 0;
            continue;
        }
        else if(xx[1]>yy[1]){
            if(xx[n]<=yy[m]){
                cout << 0;
                continue;
            }
            //cout << xx[1] << "\n";
            dfs1(1,1);
            cout << flag;
        }else if(xx[1]<yy[1]){
            if(xx[n]>=yy[m]){
                cout << 0;
                continue;
            }
            //cout << xx[1] << " " << yy[1] << "\n";
            dfs2(1,1);
            cout << flag;
        }
    }
    return 0;
}
