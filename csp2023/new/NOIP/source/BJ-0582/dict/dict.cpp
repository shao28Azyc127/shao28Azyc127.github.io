#include <bits/stdc++.h>

using namespace std;


int n,m,key=0;

char a[3030][3030],b[3030][3030];


bool cmp(char x,char y){
    return x<y;
}

bool dmp(char x,char y){
    return x>y;
}

int main()
{
    //neverTLE
    //foreverAC
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+m+1,cmp);
        sort(b[i]+1,b[i]+m+1,dmp);
    }


    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                int u=1;
                if(a[i][u]<b[j][u]&&u<=m){
                    k++;
                    continue;
                }
                else if(u<=m){
                    u++;
                }
                //cout<<"1";
            }
        }
        //cout<<endl;
        if(k==(n-1)) cout<<"1";
        else cout<<"0";
    }

    return 0;
}
