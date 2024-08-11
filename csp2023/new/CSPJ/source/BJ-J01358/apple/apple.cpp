#include <bits/stdc++.h>
using namespace std ;
struct node
{
    int nxt, pre ;
}a[10000010];
int n, nt, gongt ;
int main()
{
    freopen("apple.in", "r", stdin) ;
    freopen("apple.out", "w", stdout) ;
    scanf("%d", &n) ;
    int gong = n ;
    for(int i = 1 ; i <= n ; i++)
    {
        a[i].nxt = i + 1 ;
        a[i].pre = i - 1 ;
    }
    a[1].pre = -1 ;
    a[n].nxt = -1 ;
    int cnt = 0, head = 1 ;
    while(gong > 0)
    {
        gongt++ ;
        cnt = 0 ;
        int i = head ;
        while(i != -1)
        {
            cnt++ ;
            if(cnt % 3 == 1)
            {
                if(a[i].pre != -1)
                    a[a[i].pre].nxt = a[i].nxt ;
                if(a[i].nxt != -1)
                    a[a[i].nxt].pre = a[i].pre ;
                gong-- ;
                if(i == n)
                {
                    nt = gongt ;
                }
            }
            i = a[i].nxt ;
        }
        head = a[head].nxt ;

    }
    printf("%d %d", gongt, nt) ;
    return 0 ;
}
