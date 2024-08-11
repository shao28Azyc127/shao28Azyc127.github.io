#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int n;
int lock[9][6];
int ans[6];
bool flag[82];
int l1[6];
int cnt;
int l[82][5];
bool check(int now,int num,bool fl)
{
    if(now==6) return false;//通关，可以匹配
    if(l1[now]==l[num][now]) return check(now+1,num,fl);//无事发生
    else
    {
        if(fl==true) return true;
        else
        {
            if((l1[now+1]+(l[num][now]-l1[now]))%10==l[num][now+1])
                return check(now+2,num,true);
            else
                return check(now+1,num,true);
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<81<<endl;
        return 0;
    }
 //   for(int i=1;i<=n;i++)
  //      for(int j=1;j<=5;j++)
  //          cin>>lock[i][j];
/*    if(n>=4){
        for(int i=1;i<n-2;i++)
            for(int j=i+1;j<n-1;j++)
                for(int p=j+1;p<n;p++)
                    for(int l=p+1;l<=n;l++)
                        for(int k=1;k<=5;k++)
                        {
                            if(lock[i][k]==lock[j][k] && lock[j][k]==lock[p][l] && lock[l][k]==lock[p][k])
                                ans[k]=lock[i][k];
                        }
    }*/
    for(int i=1;i<=5;i++) cin>>l1[i];
    for(int i=1;i<=81;i++)
        for(int j=1;j<=5;j++)
            l[i][j]=l1[j];
    for(int j=1;j<=5;j++){
        for(int i=1;i<10;i++)
        {
            cnt++;
            l[cnt][j]=(l[cnt][j]+i)%10;
        }
    }
 //   cout<<cnt<<endl;
    for(int j=1;j<5;j++){
        for(int i=1;i<10;i++)
        {
            cnt++;
            l[cnt][j]=(l[cnt][j]+i)%10;
            l[cnt][j+1]=(l[cnt][j+1]+i)%10;
        }
    }
 //   for(int i=1;i<=81;i++){
 //       for(int j=1;j<=5;j++)
 //           cout<<l[i][j]<<' ';
 //       cout<<endl;
 //   }
    int ans=cnt;
    n--;
    while(n--)
    {
        for(int i=1;i<=5;i++) cin>>l1[i];
        for(int i=1;i<=81;i++)
        {
            if(flag[i]==false){
                flag[i]=check(1,i,false);
                if(flag[i]==true)
                    ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
