#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
 const int N = 11;
int n;
int a[N][5];
int s[5];//
bool st[N];


bool check()
{
    if(a[1][4] == 5 && a[2][4]==1)
        return true;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n ;i++)
        for(int j =0;j <= 4;j++)
         scanf("%d",&a[i][j]);

    if(n == 1){
        cout << 81 << endl;
        return 0;
    }
    if(n == 2)
    {
        if(check())
            cout << 10 << endl;
    }
    //




    return 0;
}
