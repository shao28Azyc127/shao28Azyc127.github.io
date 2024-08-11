#include<iostream>
using namespace std;
int f[10000][10000],n, m, k, d,c,t;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    //cin>>n>>m>>k>>d;
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        int l=k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=l;j++){
                f[i][j]=0;
            }
        }

        while(m--){
            int n1,n2,n3;
            cin>>n1>>n2>>n3;
            while(n2<=l){
                f[n1][n2]+=n3;
                n2++;
             //   cout<<n1<<n2<<n3;
            }
        }for(int i=1;i<=l;i++){
            f[0][i]=-9999;

        }


/*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=l;j++){
                cout<<f[i][j]<<'\t';
            }cout<<endl;
        }

*/



        for(int i=1;i<=n;i++){
                f[i][0]=-9999;
            for(int j=0;j<=l;j++){
                f[i][0]=max(f[i][0],f[i-1][j]);
            }
            for(int j=1;j<=l;j++){
                f[i][j]+=f[i-1][j-1]-d;
            }
        }
        int ans=-9999;
        for(int j=0;j<=l;j++){
            ans= max(ans,f[n][j]);
        }

        cout<<ans<<endl;
/*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=l;j++){
                cout<<f[i][j]<<'\t';
            }cout<<endl;
        }*/

    }








    return 0;
}

