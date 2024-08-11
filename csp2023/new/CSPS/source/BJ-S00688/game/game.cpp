#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=2e6+10;
typedef long long LL;

int n;
string s;
int stk[N],top;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    s=' '+s;
    // bool flag=1;
    // for(int i=1;i<=n;i++)
    // {
    //     if(s[i]!='a'&&s[i]!='b')
    //     {
    //         flag=0;
    //         break;
    //     }
    // }
    // if(flag)
    // {

    // }
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        top=0;
        LL cnt=0;
        for(int j=i;j<=n;j++)
        {
            if(top&&s[stk[top]]==s[j]) top--;
            else stk[++top]=j;
            if(!top) cnt++;
        }
        ans+=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N=2e6+10;
// typedef long long LL;

// int n;
// string s;
// LL fe[N],fm[N];
// int m;
// struct node{
//     char c;
//     int num;
// }a[N];
// int stk[N],top;

// int main()
// {
//     freopen("game.in","r",stdin);
//     freopen("game.out","w",stdout);
//     scanf("%d",&n);
//     cin>>s;
//     s=' '+s;
//     char cur=' ';
//     for(int i=1;i<=n;i++)
//     {
//         if(s[i]!=cur)
//         {
//             cur=s[i];
//             a[++m].c=s[i];
//             a[m].num=1;
//         }
//         else a[m].num++;
//     }
//     LL ans=0,ra=0;
//     for(int i=1;i<=m;i++)
//     {
//         if(top&&a[stk[top]].c==a[i].c)
//         {
//             if(a[i].num%2==0)
//             {
//                 fe[i]=a[i].num/2+fe[i-1];
//                 fm[i]=(a[i].num/2-1)*fe[i-1]+(a[i].num/2-1)*fm[stk[top]];
//                 ans+=a[i].num/2*(a[i].num/2+1)/2+a[i].num/2*fe[i-1];
//             }
//             else
//             {
//                 fe[i]=a[i].num/2+fm[stk[top]];
//                 fm[i]=a[i].num/2+1+fe[i-1];
//                 ans+=a[i].num/2*(a[i].num/2+1)+a[i].num/2*fe[i-1]+(a[i].num/2+1)*fm[stk[top]];
//             }
//             top--;
//         }
//         else
//         {
//             if(a[i].num%2==0)
//             {
//                 fe[i]=a[i].num/2+fe[i-1];
//                 fm[i]=a[i].num/2*(a[i].num/2-1)/2;
//                 ans+=a[i].num/2*(a[i].num/2+1)/2+a[i].num/2*fe[i-1];
//             }
//             else
//             {
//                 fe[i]=a[i].num/2;
//                 fm[i]=a[i].num/2*(a[i].num/2+1)/2;
//                 ans+=a[i].num/2*(a[i].num/2+1)+a[i].num/2*fe[i-1];
//                 stk[++top]=i;
//             }
//         }
//         printf("%lld\n",ans-ra);
//         ra=ans;
//     }
//     for(int i=1;i<=m;i++) printf("%c %d\n",a[i].c,a[i].num); 
//     for(int i=1;i<=m;i++) printf("%lld %lld\n",fe[i],fm[i]); 
//     // for(int i=1;i<=n;i++) printf("%lld ",f[i]);
//     // printf("\n");
//     printf("%lld",ans);
//     return 0;
// }
// /*
// 7
// aabbacc
// */