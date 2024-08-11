#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int a[2011],b[2011];
int c,n,m,q;
int kx,ky;
int px[2011],ox[2011],vx[2011];
int py[2011],oy[2011],vy[2011];
void inline small(){//f<g
    if(a[n]>=b[n]){
        cout << 0;
        return;
    }
    //cout << 1;
    //return;
    int j=1;
    for(int i=1;i<=n;i++){
        if(a[i]<b[j]){
            while(j<=m&&a[i]<b[j]) j++;
            if(j>m) j=m;
        } else {
            while(j>=1&&a[i]>=b[j]) j--;
            if(j==0){
                cout << 0;
                return;
            }
        }
    }
    if(j<m){
        cout << 0;
        return;
    }
    cout << 1;
}
void inline big(){//f>g
    if(a[n]<=b[n]){
        cout << 0;
        return;
    }
    //cout << 1;
    //return;
    int j=1;
    for(int i=1;i<=n;i++){
        if(a[i]>b[j]){
            while(j<=m&&a[i]>b[j]) j++;
            if(j>m) j=m;
        } else {
            while(j>=1&&a[i]<=b[j]) j--;
            if(j==0){
                cout << 0;
                return;
            }
        }
    }
    if(j<m){
        cout << 0;
        return;
    }
    cout << 1;
}
void inline sol(){
    if(a[1]==b[1]||a[n]==b[n]){
        cout << 0;
        return;
    }
    if(a[1]<b[1]) small();
    else big();
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    sol();
    for(int i=1;i<=q;i++){
        /*
        memset(px,0,sizeof(px));
        memset(py,0,sizeof(py));
        memset(vx,0,sizeof(vx));
        memset(vy,0,sizeof(vy));
        memset(ox,0,sizeof(ox));
        memset(oy,0,sizeof(oy));
        */
        scanf("%d%d",&kx,&ky);
        for(int j=1;j<=kx;j++){
            scanf("%d%d",&px[j],&vx[j]);
            ox[j]=a[px[j]];
            a[px[j]]=vx[j];
        }
        for(int j=1;j<=ky;j++){
            scanf("%d%d",&py[j],&vy[j]);
            oy[j]=b[py[j]];
            b[py[j]]=vy[j];
        }
        sol();
        for(int j=1;j<=kx;j++) a[px[j]]=ox[j];
        for(int j=1;j<=ky;j++) b[py[j]]=oy[j];
    }
    cout << endl;
	return 0;
}
/*
too strict!!!
*/
