#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXM 3005*3005
using namespace std;
int n,m,cnt=1,tp,mxid,num[3005][27];
string s[3005],s1,s2,t[3005];
int main()
{
    freopen("dict.in" ,"r",stdin );
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
            num[i][s[i][j]-96]++;
        if(s1==""||s[i]<=s1)
        {
            s2=s1;
            s1=s[i],mxid=i;
        }
        else if(s2==""||s[i]<=s2)
            s2=s[i];
        for(int j=1;j<=26;j++)
            for(int k=1;k<=num[i][j];k++)
                t[i]+=(char)(j+96);
        // cout<<t[i]<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=mxid)
            cout<<(t[i]<s1);
        else
            cout<<(t[i]<s2);
    }
    return 0;
}