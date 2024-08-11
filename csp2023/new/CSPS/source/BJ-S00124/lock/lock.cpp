#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int maxa = 6;
int cal[maxa];
int a[maxn][maxa];//个数，位数
int n,ans;///test_tp should be deleted
bool judge(){
    int tp,pl[3],ca[3];
    for(int i=1;i<=n;i++){
        tp=pl[1]=pl[2]=ca[1]=ca[2]=0;
        for(int j=1;j<=5;j++){
            if(cal[j]!=a[i][j]){
                tp++;
                if(tp>2)return false;
                pl[tp]=j;
                ca[tp]=cal[j]-a[i][j];
                while(ca[tp]<0)ca[tp]+=10;
            }
        }
        if(tp==0)return false;
        if((tp==2)&&(pl[1]!=pl[2]-1))return false;
        if((tp==2)&&(ca[1]!=ca[2]))return false;
    }
    return true;
}
void solve(int dig){
    if(dig!=maxa){
        for(int i=0;i<=9;i++){
            cal[dig]=i;
            solve(dig+1);
        }
    }
    else{
        if(judge())ans++;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    solve(1);
    cout<<ans<<endl;
    /*cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=5;i++){
        cin>>cal[i];
    }
    cout<<judge()<<endl;*/
    return 0;
}
