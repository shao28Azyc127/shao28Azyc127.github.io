#include <bits/stdc++.h>

using namespace std;

int NuM,T,n,m,l[100044],r[100044],diff;  //x[l]=(-)x[r]
char op[100044];
int x[100044],y[100044];

void init(){
    for(int i=1;i<=m;i++){
            y[i]=x[i];
    }
}

void give(){

    char opr;
    int i;
    int j;
    for(int u=1;u<=m;u++){
        opr=op[u];
        i=l[u];
        j=r[u];
        if(opr=='-') y[i]=-1*y[j];
        else if(opr=='+') y[i]=y[j];
        else if(opr=='U') y[i]=0;
        else if(opr=='T') y[i]=1;
        else if(opr=='F') y[i]=-1;
    }

}

int same(){

    for(int i=1;i<=n;i++){
        if(x[i]!=y[i]){
            diff=i;
            return 0;
        }
    }
    return 1;
}

int main()
{
    //neverTLE
    //foreverAC
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>NuM>>T;
    while(T--){

        int ans=0;

        cin>>n>>m;
        for(int i=1;i<=n;i++){
            x[i]=1;
        }
        init();
        for(int u=1;u<=m;u++){
            cin>>op[u];
            if(op[u]=='-'||op[u]=='+') cin>>l[u]>>r[u];
            else cin>>l[u];
        }
        give();

        int t=same();
        while(!t){
            x[diff]=-1*x[diff];
            init();
            give();
            if(!same()){
                x[diff]=0;
                init();
                give();
            }

            t=same();
        }

        for(int i=1;i<=n;i++){
            if(x[i]==0) ans++;

        }
        cout<<ans<<endl;
    }
}
