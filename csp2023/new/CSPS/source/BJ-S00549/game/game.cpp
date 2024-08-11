#include <iostream>
#define N 1000002
using namespace std;
int len,seed[N],sz[N],cnt,lst,ans;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>len>>s;
    for(int i=0;i<len;i++)  if(s[i]==s[i+1])  seed[cnt++]=i;
    for(int i=0;i<cnt;i++){
        int p=seed[i],siz=1;
        while(s[p-siz]==s[p+siz+1])  siz++;
        sz[i]=siz;
        ans+=siz;
    }
    int cnt2=0;
    for(int i=0;i<cnt;i++){
        //cout<<seed[lst]<<"+"<<sz[lst]<<"+1 "<<seed[i]<<"-"<<sz[i]<<endl;
        if(seed[lst]+sz[lst]==seed[i]-sz[i]){
            ans+=++cnt2;
            if((s[seed[lst]-sz[lst]]==s[seed[i]+sz[i]+1])&&(seed[lst]-sz[lst]-1>=0)&&(seed[i]+sz[i]+2<len)){
                //cnt2++;
                int siz=0;
                while((s[seed[lst]-sz[lst]-1-siz])==s[seed[i]+sz[i]+2+siz]&&(seed[lst]-sz[lst]-1>=siz)&&(seed[i]+sz[i]+2<len-siz))  siz++;
                cout<<siz<<endl;
                ans+=siz;
            }
        }else{
            lst=i;
            cnt2=0;
        }
    }
    cout<<ans;
    return 0;
}