#include <iostream>
#define N 12
using namespace std;
int n,k[N],ans;
struct lock{
    int c[N];
}a[N];
bool operator ==(lock x,lock y){
    for(int i=1;i<=5;i++){
        if(x.c[i]!=y.c[i])  return 0;
    }
    return 1;
}
bool check(string s){
    k[1]=s[0]-'0',k[2]=s[1]-'0',k[3]=s[2]-'0',k[4]=s[3]-'0',k[5]=s[4]-'0';
    for(int i=1;i<=n;i++){
        bool cflg=0,bflg=0;
        for(int j=1;j<=5;j++){
            //if(s=="04383")  cout<<bflg<<" "<<cflg<<endl;
            if(k[j]!=a[i].c[j]){
                if(k[j-1]==a[i].c[j-1]&&k[j+1]==a[i].c[j+1]){
                    if(cflg==0&&bflg==0)  cflg=1;
                    else  return 0;
                }else if(k[j+1]-k[j]==a[i].c[j+1]-a[i].c[j]){
                    if(bflg==0&&cflg==0)  bflg=1,j++;
                    else  return 0;
                }else if(k[j+1]-k[j]+10==a[i].c[j+1]-a[i].c[j]){
                    if(bflg==0&&cflg==0)  bflg=1,j++;
                    else  return 0;
                }else if(-k[j+1]+k[j]+10==-a[i].c[j+1]+a[i].c[j]){
                    if(bflg==0&&cflg==0)  bflg=1,j++;
                    else  return 0;
                }else  return 0;
            }
        }
        //if(s=="28395")  cout<<bflg<<" "<<cflg<<endl;
        if(bflg==0&&cflg==0)  return 0;
    }
    return 1;
}
void dfs(int p,string s){
    //cout<<s<<endl;
    if(p==5){
        if(check(s)){
            ans++;
            //cout<<s<<endl;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        dfs(p+1,s+(char)(i+'0'));
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  for(int j=1;j<=5;j++)  cin>>a[i].c[j];
    ans=0;
    dfs(0,"");
    cout<<ans<<endl;
    return 0;
}