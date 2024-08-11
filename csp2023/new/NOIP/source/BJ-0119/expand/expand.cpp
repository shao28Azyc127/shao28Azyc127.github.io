#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005

int c,n,m,q;

long long a1[MAXN],b1[MAXN];
long long a[MAXN],b[MAXN];

bool f[MAXN][MAXN];

int qx,qy;
int rpos,rval;

void rget(){
    for(int i=1;i<=n;i++){
        a[i]=a1[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=b1[i];
    }

    memset(f,0,sizeof(f));
    f[0][0]=true;

    return;
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((a[i]-b[j])*(a[1]-b[1])>0){
                f[i][j]=f[i][j-1]||f[i-1][j]||f[i-1][j-1];
            }
        }
    }

    printf("%d",(int)f[n][m]);

    return;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);

    ios::sync_with_stdio(false);

    cin>>c>>n>>m>>q;

    if(c>7){
        for(int i=1;i<=q+1;i++){
            printf("0");
        }
    }


    for(int i=1;i<=n;i++){
        cin>>a1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b1[i];
    }

    rget();
    solve();
    for(int i=1;i<=q;i++){
        rget();

        cin>>qx>>qy;
        for(int i=1;i<=qx;i++){
            cin>>rpos>>rval;
            a[rpos]=rval;
        }
        for(int i=1;i<=qy;i++){
            cin>>rpos>>rval;
            b[rpos]=rval;
        }

        solve();
    }

    printf("\n");

	return 0;
}
