#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int b[3123][30],c[3123][30];
string a[3123];
int n,m;
string now;
bool o=0;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char now;
            cin>>now;
            b[i][now-'a']++;
            c[i][now-'a']++;
        }
    for(int i=1;i<=n;i++)
        for(int j=27;j>=0;j--)
            while(b[i][j])
                a[i]=a[i]+(char)('a'+j),b[i][j]--;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++)
//            cout<<b[i][j];
//        cout<<endl;
//    }
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++)
//            a[i]=a[i]+b[i][j];
//    for(int i=1;i<=n;i++)
//        cout<<a[i]<<endl;
//    for(int i=1;i<=n;i++)
//        sort(b[i]+1,b[i]+1+m,cmp1);
    for(int i=1;i<=n;i++)
    {
        o=0;
        now="";
        for(int j=0;j<=27;j++)
            while(c[i][j])
                now=now+(char)('a'+j),c[i][j]--;
//        cout<<now<<endl;
        for(int j=1;j<=n;j++){
            if(i==j)    continue;
            if(a[j]<=now){
                o=1;
                break;
            }
        }
        if(o)   cout<<0;
        else    cout<<1;
    }
    return 0;
}
