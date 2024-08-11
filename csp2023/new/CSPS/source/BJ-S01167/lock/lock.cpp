#include<bits/stdc++.h>
using namespace std;
int n,pwd[10][6],cpwd[6],ans=0;
bool flag=0;
bool pd()
{
    for(int i=1;i<=n;i++)//mei ju mei ge mi ma
    {
        bool tf=0;
        for(int j=1;j<=5;j++)
            if(pwd[i][j]!=cpwd[j]&&!tf)//yi wei bu tong,ke yi tong guo bian hua de dao
                tf=1;
            else if(pwd[i][j]!=cpwd[j]&&tf)//gai mi ma you chao guo yi wei bu tong,wu fa tong guo zhuan dong yi ci de chu
                return 0;
    }
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d%d",&pwd[1],&pwd[2],&pwd[3],&pwd[4],&pwd[5]);
    if(n==1)
    {
        printf("81");
        return 0;
    }
    for(cpwd[1]=0;cpwd[1]<=9;cpwd[1]++)
        for(cpwd[2]=0;cpwd[2]<=9;cpwd[2]++)
            for(cpwd[3]=0;cpwd[3]<=9;cpwd[3]++)
                for(cpwd[4]=0;cpwd[4]<=9;cpwd[4]++)
                    for(cpwd[5]=0;cpwd[5]<=9;cpwd[5]++)
                    {
                        flag=0;
                        for(int i=1;i<=n;i++)//cha chong
                            if(cpwd[1]==pwd[i][1]&&cpwd[2]==pwd[i][2]&&cpwd[3]==pwd[i][3]&&cpwd[4]==pwd[i][4]&&cpwd[5]==pwd[i][5])
                            {
                                flag=1;
                                break;
                            }
                        if(flag)
                            continue;
                        if(pd())
                        {
                            //for(int i=1;i<=5;i++)
                            //    printf("%d",cpwd[i]);
                            //cout<<endl;
                            ans++;
                        }

                    }
    printf("%d",ans);
    return 0;
}
//P1-3 30
