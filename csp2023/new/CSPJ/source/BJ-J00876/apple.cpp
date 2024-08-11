#include<cstdio>
using namespace std;
int main()
{
    int n;
    int cnt=0;
    int cnt2=0;
    freopen(apple.in,'r',stdin);
    freopen(apple.out,'w',stdout);
    scanf("%d",&n);
    while(n>0)
    {
        cnt++;
        if(n%3==1&&cnt2==0)
        {
            cnt2=cnt;
        }
        n--;
        n-=n/3;
    }
    printf("%d ",cnt);
    printf("%d",cnt2);
    return 0;
}
