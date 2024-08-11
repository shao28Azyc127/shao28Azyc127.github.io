//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

string s[3005];
string t[3005];
string u[3005];

bool cmp1(char x,char y){
    return x<y;
}

bool cmp2(char x,char y){
    return x>y;
}

char c[3005];
char d[3005];

signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int m; cin>>m;

    for(int i=1;i<=n;i++){
        cin>>s[i];

        for(int j=1;j<=m;j++){
            c[j]=d[j]=s[i][j-1];
        }

        sort(c+1,c+m+1,cmp1);
        sort(d+1,d+m+1,cmp2);

        for(int j=1;j<=m;j++){
            //cout<<c[j];
            t[i]+=c[j];
        }
        //cout<<endl;
        for(int j=1;j<=m;j++){
            //cout<<d[j];
            u[i]+=d[j];
        }
        //cout<<endl;
        //cout<<t[i]<<" "<<u[i]<<endl;
    }

    if(n==1){
        cout<<1;
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            int f; f=1;
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }

                if(s[i]>=s[j]){
                    f=0;
                }
            }

            cout<<f;
        }

        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            int f; f=1;
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }

                //cout<<t[i]<<" "<<u[i]<<endl;
                if(t[i]>=u[j]){
                    f=0;
                }
            }

            cout<<f;
        }
    }

    cout<<endl;
    return 0;
}
