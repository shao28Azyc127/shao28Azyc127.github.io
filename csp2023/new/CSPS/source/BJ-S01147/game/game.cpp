#include <bits/stdc++.h>

using namespace std;
int n,k,a[2000005];
vector<int>b[30];
long long ans=0;
    string s;
 template<typename T>
 inline void read(T &sum){
    sum=0;int f=1;
    char c;
    while(!isdigit(c)){c=getchar();if(c=='-')f=-1;}
    while(isdigit(c))sum=sum*10+c-'0',c=getchar();
    sum*=f;
 }
 int f(int l,int r){
     if(r-l==0||r-l<-1)return 0;
     if(r-l==-1){return 1;}
     //cout<<l<<" "<<r<<endl;
     int m=b[a[l]].size()-1;
     int z=1,zz=0;
     /*for(int i=lower_bound(b[a[l]].begin(),b[a[l]].end(),l)-b[a[l]].begin();(i<m)&&(b[a[l]][i]<=r);i++){
            for(int j=i+1;(j<m)&&(b[a[l]][j]<=r);j+=2){
                    if(f(b[a[l]][i]+1,b[a[l]][j]-1)){
                            ans++;
                            cout<<b[a[l]][i]+1<<" "<<b[a[l]][j]-1<<endl;
                        if(b[a[l]][i]==l&&b[a[l]][j]==r)zz=1;
                    }
            }
     }*/
     int i=lower_bound(b[a[l]].begin(),b[a[l]].end(),l)-b[a[l]].begin(),j;
     for(j=i+1;(j<=m)&&(b[a[l]][j]<=r);j+=2){
            if(f(b[a[l]][i]+1,b[a[l]][j]-1)){
                ans++;
                cout<<1<<" "<<i<<" "<<j<<endl;
                if(b[a[l]][i]==l&&b[a[l]][j]==r)zz=1;
        }
        f(b[a[l]][j]+1,r);
    }
     return zz;
 }
int main()
{
    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);
    read(n);
    cin>>s;
    for(int i=0;i<30;i++)b[i].push_back(-1);
    for(int i=1;i<=s.size();i++)a[i]=s[i-1]-'a',b[a[i]].push_back(i);
    for(int i=0;i<=26;i++)f(b[i][1],n);
    cout<<ans;
    return 0;
}
