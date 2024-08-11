#include<iostream>
#include<string>
using namespace std;

const int maxn=3000+10;
int n,m;
string words[maxn];
char mx[maxn],mxmn[maxn],mn[maxn];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>words[i];
        mxmn[i]=127; mn[i]=127;
        for(int j=0;j<m;j++)mx[i]=max(mx[i],words[i][j]),mn[i]=min(mn[i],words[i][j]);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)mxmn[i]=min(mxmn[i],mx[j]);
    for(int i=1;i<=n;i++)cout<<(mn[i]<mxmn[i]);
    cout<<endl;
}