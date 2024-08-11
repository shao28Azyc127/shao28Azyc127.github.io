#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int ans[maxn],a[maxn][maxn],mmax[maxn],mmin[maxn];
string s[maxn];
long long n,m;


int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    //search min max bingcha
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='a')a[i][j]=1;
            else if(s[i][j]=='b')a[i][j]=2;
            else if(s[i][j]=='c')a[i][j]=3;
            else if(s[i][j]=='d')a[i][j]=4;
            else if(s[i][j]=='e')a[i][j]=5;
            else if(s[i][j]=='f')a[i][j]=6;
            else if(s[i][j]=='g')a[i][j]=7;
            else if(s[i][j]=='h')a[i][j]=8;
            else if(s[i][j]=='i')a[i][j]=9;
            else if(s[i][j]=='j')a[i][j]=10;
            else if(s[i][j]=='k')a[i][j]=11;
            else if(s[i][j]=='l')a[i][j]=12;
            else if(s[i][j]=='m')a[i][j]=13;
            else if(s[i][j]=='n')a[i][j]=14;
            else if(s[i][j]=='o')a[i][j]=15;
            else if(s[i][j]=='p')a[i][j]=16;
            else if(s[i][j]=='q')a[i][j]=17;
            else if(s[i][j]=='r')a[i][j]=18;
            else if(s[i][j]=='s')a[i][j]=19;
            else if(s[i][j]=='t')a[i][j]=20;
            else if(s[i][j]=='u')a[i][j]=21;
            else if(s[i][j]=='v')a[i][j]=22;
            else if(s[i][j]=='w')a[i][j]=23;
            else if(s[i][j]=='x')a[i][j]=24;
            else if(s[i][j]=='y')a[i][j]=25;
            else if(s[i][j]=='z')a[i][j]=26;
        }
    }
    for(int i=0;i<n;i++){
        sort(a[i],a[i]+m);
        mmax[i]=a[i][m-1];
        mmin[i]=a[i][0];
    }
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<n;j++){
            if(mmin[i]>=mmax[j]&&i!=j){
                ans[i]=0;
                flag=true;
                break;
            }
        }
        if(!flag){
            ans[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
return 0;
}
