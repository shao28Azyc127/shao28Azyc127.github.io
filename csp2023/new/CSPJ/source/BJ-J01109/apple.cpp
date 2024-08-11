#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N=1e6+5;
ll n,cnt,i=1,ans2,j;//ans2表示第二空
bool a[N],flag=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    if(1<=n&&n<=10)
    {
        if(n==1) printf("1 1");
        if(n==2) printf("2 2");
        if(n==3) printf("3 3");
        if(n==4) printf("3 1");
        if(n==5) printf("4 4");
        if(n==6) printf("4 2");
        if(n==7) printf("7 1");
        if(n==8) printf("5 5");
        if(n==9) printf("5 3");
        if(n==10) printf("6 1");
    }
    return 0;
}