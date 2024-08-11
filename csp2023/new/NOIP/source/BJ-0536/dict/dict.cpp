#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long n,m;
string w[3005],maw[3005],miw[3005];
long long c[1005];
/*
void dfs(long long p){
    if(p>n){

    }
    for(int i=1;i<=n;i++){

    }
}
*/
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }//cout<<n<<endl;
    for(long long i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        for(int j=0;j<m;j++){
            c[w[i][j]]++;
        }
        string mas="",mis="";
        for(int j='z';j>='a';j--){
            for(int k=1;k<=c[j];k++){
                mas+=(char)j;
            }
        }
        for(int j='a';j<='z';j++){
            for(int k=1;k<=c[j];k++){
                mis+=(char)j;
            }
        }
        maw[i]=mas;
        miw[i]=mis;
        //cout<<mas<<endl<<mis<<endl;
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(miw[i]>=maw[j])flag=0;
        }
        if(flag){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
