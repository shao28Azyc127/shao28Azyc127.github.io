#include<bits/stdc++.h>
using namespace std;
int ans = 0;
/*bool xiao(char a[] , int cd)
{
    int cishu = cd / 2;
    for(int i = 0;i<= cd;i++)
    {
        for(int j = 0;j<=cd;j++)
        {
            int s = 1;
            if(a[j] == '0')
                continue;
            for(;a[j+s]=='0';s++)
            {
            }
            if(a[j] == a[j+s])
                --cishu;

        }
    }
    if(cishu==1)
        return true;
    else
        return false;
}*/
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n;
    cin>>n;
    char a[n];
    for(long long i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    for(long long i = 2; i <= n; i = i + 2)// chang2 du4
    {
        for(long long j = 0;j <= (n-i);j++)//tou2 bu4
        {
            char ap[i];
            long long l = 0;
            for(long long k = j;k<(j+i);k++)
            {
                ap[l] = a[k];
                //cout<<ap[l];
                ++l;
            }//mei3 ju3 zi3 chuan4
           // cout<<" "<<i;
           // cout<<endl;
            if(i==2)
            {
                if(ap[0] == ap[1])
                    ++ans;
                    continue;
            }
            if(i==4)
            {
                if((ap[0]==ap[1] && ap[2] == ap[3]) || (ap[0] == ap[3] && ap[1] == ap[2]))
                    ++ans;
                    continue;
            }

            long long cishu = 0;//xiao1 diao4 de ci4 shu
            for(long long k = j;k<=i ;k++)
            {

                for(long long l = j;l<i;l++)
                {
                    if(ap[l]== '0')
                    {
                        continue;
                    }
                    int pp = 1;
                    for(pp;ap[l+pp]=='0';pp++)
                    {
                    }
                    if(ap[l] == ap[l+pp] && ap[l] != '0')
                    {
                        cishu++;
                        //cout<<"2222"<<ap[l]<<" "<<ap[l+pp]<<endl;
                        ap[l] = '0';
                        ap[l+pp] = '0';
                    }

                }

            }
            if(i == (cishu * 2))
                {++ans;
                for(int ff = 0;ff<l;ff++)
                    {
                     //   cout<<ap[ff];
                    }
                    //cout<<" "<<cishu;
                    //cout<<endl;
                }//ru2 guo3 chang2 du4 zheng3 hao3 shi4 ci4 shu4 de er4 bei4 , na4 me4, da2 an4 ++

        }
    }
    cout<<ans<<endl;
    return 0;
}
