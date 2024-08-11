#include<bits/stdc++.h>
using namespace std;

int book[114514];
int chuan[10][5];
int temp[5];

void print(int k){
    for(int i=0;i<5;i++)cout<<temp[i]<<' ';cout<<"(+"<<k<<")";
    cout<<'\n';
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>chuan[i][0]>>chuan[i][1]>>chuan[i][2]>>chuan[i][3]>>chuan[i][4];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)temp[k]=chuan[i][k];
            for(int k=0;k<10;k++)
                temp[j]=k,book[temp[0]*10000+temp[1]*1000+temp[2]*100+temp[3]*10+temp[4]]++;
        }
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<5;k++)temp[k]=chuan[i][k];
            for(int k=0;k<10;k++)
            {
                temp[j]=(temp[j]+k)%10,temp[j+1]=(temp[j+1]+k)%10,book[temp[0]*10000+temp[1]*1000+temp[2]*100+temp[3]*10+temp[4]]++;
                for(int k=0;k<5;k++)temp[k]=chuan[i][k];
            }
        }
    }

    int ans=0;
    for(int i=0;i<114514;i++)ans+=(book[i]==n);

    cout<<ans;
}