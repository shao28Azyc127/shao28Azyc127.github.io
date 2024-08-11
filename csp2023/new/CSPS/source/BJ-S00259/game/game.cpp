#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
int c[10000];
int c2[10000];
int beg;
int ans;
int plusl[10000];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++) c[i]=i+1;
    for(int i=1;i<=n-1;i++) c2[i]=i-1;
    c2[0]=-1;
    while(beg!=n&&c[beg]!=n){
        int bfans=ans;
        for(int i=beg;i<=n-2;i=c[i]){
            if(s[i]==s[c[i]]){
                ans++;
                if(i==beg)beg=c[c[i]];
                else c[c2[i]]=c[c[i]];
                c2[c[i]]=-2;
                c[i]=c[c[i]];
                c2[c[i]]=c2[i];
                c2[i]=-2;
            }
            //cout<<beg<<endl;for(int j=0;j<n;j++) cout<<c[j]<<" ";cout<<endl;for(int j=0;j<n;j++) cout<<c2[j]<<" ";cout<<endl;
            //break;
        }
        if(ans==bfans) break;
    }
    int plusind=0;
    for(int i=0;i<n-1;i=c2[i]==-2?c[i]:i+1){
        if(c2[i]==-2 && c[i]==c[c[i]-1] && c2[c[i]-1]==-2){
            plusl[plusind]++;
        }
        else if(plusl[plusind]!=0) plusind++;
    }
    for(int i=0;i<=plusind;i++){
        //cout<<plusl[plusind]<<" ";
        if(plusl[i]!=0) ans+=(plusl[i]*(plusl[i]-1)/2);
    }
    cout<<ans;
}