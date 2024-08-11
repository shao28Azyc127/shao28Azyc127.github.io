#include<bits/stdc++.h>
using namespace std;

string a[3100];
string b[3100];
string c[3100];
char t[3100];

bool cmp1(char a,char b){return a<b;}
bool cmp2(char a,char b){return a>b;}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        //printf("%s\n",a[i].c_str());
        for(int j=0;j<m;j++)t[j]=a[i][j];
        //printf("%s\n\n",t);
        sort(t,t+m,cmp1);
        b[i]=t;
        sort(t,t+m,cmp2);
        c[i]=t;
    }

    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(j==i)continue;
            if(c[j]<b[i])
            {
                flag=false;
                break;
            }
        }
        cout<<(int)flag;
    }
    cout<<'\n';
    return 0;
}