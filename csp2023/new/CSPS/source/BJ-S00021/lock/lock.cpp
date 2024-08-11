#include<bits/stdc++.h>
using namespace std;
int pwd[8];int lis[12][8];
bool ok[8];
int stp(int a,int b)
{
    int cnt=0;
    while(a!=b)
    {
        ++cnt;
        a=(a+1)%10;
    }
    return cnt;
}
int main()
{
    //bao li chu qi ji !!!
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;cin>>n;int cnt=0;
    if(n==1){cout<<81;return 0;}
    for(int i=1;i<=n;++i)
        for(int j=1;j<=5;++j)
            cin>>lis[i][j];
    for(pwd[1]=0;pwd[1]<=9;++pwd[1])
        for(pwd[2]=0;pwd[2]<=9;++pwd[2])
            for(pwd[3]=0;pwd[3]<=9;++pwd[3])
                for(pwd[4]=0;pwd[4]<=9;++pwd[4])
                    for(pwd[5]=0;pwd[5]<=9;++pwd[5])
                    {
                        memset(ok,0,sizeof(ok));
                        bool flag=true;
                        for(int i=1;i<=n;++i)
                        {
                            int cnt=0;
                            for(int j=1;j<=5;++j)
                                cnt+=pwd[j]!=lis[i][j];
                            //bigger than 2 is not ok
                            if(cnt>2){flag=false;break;}
                            //same is not ok
                            if(!cnt){flag=false;break;}
                            //one differ is ok
                            if(cnt==1){}
                            //not consecutive is not ok
                            else
                            {
                                int pos1;
                                for(pos1=1;pwd[pos1]==lis[i][pos1];++pos1);
                                if(pwd[pos1+1]==lis[i][pos1+1])
                                    {flag=false;break;}
                                //check if the choice is ok
                                int pos2=pos1+1;
                                if(stp(pwd[pos1],lis[i][pos1])
                                !=stp(pwd[pos2],lis[i][pos2]))
                                    {flag=false;break;}
                            }
                        }
                        if(flag)++cnt;
                    }
    cout<<cnt;
    fclose(stdin);fclose(stdout);
    return 0;
}
