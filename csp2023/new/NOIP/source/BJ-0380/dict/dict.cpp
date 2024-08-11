#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const int N=3005;
int n,m;
string s[N],s1[N],s2[N];
char temp[N];

bool cmp(char x,char y)
{
    return x>y;
}
string ssort(string a,int x)
{
    string b="";
    for(int i=1;i<=m;i++)
        temp[i]=a[i-1];
    if(x==1)//1 min
    {
        sort(temp+1,temp+1+m);
        for(int i=1;i<=m;i++)
            b+=temp[i];
    }
    else{
        sort(temp+1,temp+1+m,cmp);
        for(int i=1;i<=m;i++)
            b+=temp[i];
    }
    return b;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s1[i]=ssort(s[i],1);
        s2[i]=ssort(s[i],2);
    }
    for(int i=1;i<=n;i++)//i min
    {
        bool flag=1;
        for(int j=1;j<=n;j++)//j max
        {
            if(i==j)continue;
            if(s1[i]>=s2[j]){
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    return 0;
}
