#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,m;
int arr[15],ai[15],aj[15],x[100010];
char ac[15];

bool add(){
    int pos=1;
    arr[pos]++;
    while(arr[pos]==3){
        arr[pos]=0;
        pos++;
        arr[pos]++;
        if(pos>n){
            return false;
        }
    }
    return true;
}

signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>t;
    for(int i=1;i<=t;i=-(~i)){
        memset(ai,0,sizeof(ai));
        memset(aj,0,sizeof(aj));
        memset(x,0,sizeof(x));
        cin>>n>>m;
        if(c==1||c==2){
            for(int j=1;j<=m;j=-(~j)){
                cin>>ac[j]>>ai[j];
                if(ac[j]=='+'||ac[j]=='-'){
                    cin>>aj[j];
                }
            }
            int ans=n;
            do{
                for(int j=1;j<=n;j=-(~j)){
                    x[j]=arr[j];
                }
                for(int j=1;j<=m;j=-(~j)){
                    if(ac[j]=='+'){
                        x[ai[j]]=x[aj[j]];
                    }
                    else if(ac[j]=='-'){
                        if(x[aj[j]]==0){
                            x[ai[j]]=1;
                        }
                        else if(x[aj[j]]==1){
                            x[ai[j]]=0;
                        }
                        else{
                            x[ai[j]]=2;
                        }
                    }
                    else{
                        if(ac[j]=='F'){
                            x[ai[j]]=0;
                        }
                        else if(ac[j]=='T'){
                            x[ai[j]]=1;
                        }
                        else{
                            x[ai[j]]=2;
                        }
                    }
                }
                int cnt=0;
                for(int j=1;j<=n;j=-(~j)){
                    if(arr[j]==2){
                        cnt++;
                    }
                    if(x[j]!=arr[j]){
                        cnt=-1;
                        break;
                    }
                }
                if(cnt==0){
                    ans=0;
                    break;
                }
                if(cnt!=-1){
                    ans=min(ans,cnt);
                    if(ans==0){
                        break;
                    }
                }
            }while(add());
            cout<<ans<<endl;
        }
        else if(c==3||c==4){
            for(int j=1;j<=m;j=-(~j)){
                char ch;
                int ni;
                cin>>ch>>ni;
                if(ch=='F'){
                    x[ni]=0;
                }
                else if(ch=='T'){
                    x[ni]=1;
                }
                else{
                    x[ni]=2;
                }
            }
            int ans=0;
            for(int j=1;j<=n;j=-(~j)){
                if(x[i]==2){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
