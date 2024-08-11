#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;//violent
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","r",stdout);
    int n;cin>>n;
    if(n==1){cout<<81;return 0;}
    int s[10],cnt=0;
    for(int i=0;i<n;i++)
    {
        char s_[5];
        cin>>s_[0]>>s_[1]>>s_[2]>>s_[3]>>s_[4];
        s[i]+=int(s_[0]-'0')*10000;
        s[i]+=int(s_[1]-'0')*1000;
        s[i]+=int(s_[2]-'0')*100;
        s[i]+=int(s_[3]-'0')*10;
        s[i]+=int(s_[4]-'0');
    }
    s[0]-=2;
    for(int i=0;i<100000;i++)//summon
    {
        int flag=0;
        for(int j=0;j<n;j++)//compare
        {
            if(i==s[j])break;
            for(int k=0;k<50;k++)//edit1
            {
                if(k%10==0)continue;
                int p=pow(10,k/10);
                int e=((i/p)%(p*10))*p;
                int a=(i/(p*10))*p*10,b=i%p;
                e=(e+(k%10)*p)%p;
                if(a+b+e==s[j])
                {flag++;break;}
            }
            for(int k=0;k<40;k++)//edit2
            {
                if(k%10==0)continue;
                int p=pow(10,k/10);
                int e=((i/p)%(p*10))*p;
                int a=(i/(p*100))*p*100,b=i%p;
                e=(e+(k%10)*p*10+(k%10)*p)%(p*10);
                if(a+b+e==s[j])
                {flag++;break;}
            }
        }
        if(flag>n)cnt++;
    }
    cout<<cnt;
    return 0;
}