#include<bits/stdc++.h>
using namespace std;
const int   N = 1e6+5;
int n,a[10][10],cnt;
int cf[6];
int is[N];
//int check1,check2,c1[100],c2[100];
int xiabiao1(int zu,int j,int x)//第j位改完后是x
{
    cnt = 0;
    for(int i = 1;i < j;i++)
        cnt+=a[zu][i]*cf[5-i];
    for(int i = j+1;i <= 5;i++)
        cnt+=a[zu][i]*cf[5-i];
    cnt+=x*cf[5-j];
//    cout<<zu<<' '<<j<<' '<<x<<' '<<cnt<<endl;
//	c1[check1+1] = cnt;
//    check1++;
    return cnt;
}
int xiabiao2(int zu,int j,int x)//第一个数字是j位，x是一个两位数
{
    cnt = 0;
    for(int i = 1;i < j;i++)
        cnt+=a[zu][i]*cf[5-i];
    for(int i = j+2;i <= 5;i++)
        cnt+=a[zu][i]*cf[5-i];
    cnt+=x*cf[5-j-1];
//    cout<<zu<<' '<<j<<' '<<x<<' '<<cnt<<endl;
//	c2[check2+1] = cnt;
//    check2++;
//    if(cnt==15)
//		cout<<j<<'*'<<x<<endl;
    return cnt;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cf[0] = 1,cf[1] = 10,cf[2] = 100,cf[3] = 1000,cf[4] = 10000,cf[5] = 100000;
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
            for(int k = 1;k <= 9;k++)
                is[xiabiao1(i,j,(a[i][j]+k)%10)]++;
        for(int j = 1;j <= 4;j++)
            for(int k = 1;k <= 9;k++)
                is[xiabiao2(i,j,(a[i][j]+k)%10*10+(a[i][j+1]+k)%10)]++;
    }
//    sort(c1+1,c1+check1+1);
//    sort(c2+1,c2+check2+1);
    int ans = 0;
//    cout<<is[15]<<"!";
    for(int i = 0;i <= 99999;i++)
        if(is[i]==n)
            ans++;
//    cout<<check1<<' '<<check2<<' '<<ans<<endl;
	cout<<ans<<endl;
/*    for(int i = 1;i <= check1;i++)
		cout<<c1[i]<<endl;
    for(int i = 1;i <= check2;i++)
		cout<<c2[i]<<endl;*/
    return 0;
}
