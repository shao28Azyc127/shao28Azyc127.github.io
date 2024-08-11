#include <iostream>
#include <cstdio>

using namespace std;
//const int N=1e5;
int l[10][10],cnt;
//bool a[5];
int ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin >>l[i][j];
        }
    }
    if(n==1){
        ans+=5*9;
        ans+=4*9;
    }
    else if(n==2)
    {
        for(int i=1;i<=5;i++)
        {
            if(l[1][i]!=l[2][i]){
                cnt++;
            }
        }//cout <<cnt<<endl;
        if(cnt==1){
            ans=10;
        }
    }

    cout <<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
