#include<cstdio>
#include<iostream>
using namespace std;

int n, cnt = 3, ans, k;

bool flag[1000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int t = n;
    while(t)
    {
        ans++;
        for(int i=1; i<=n; i++)
        {
            if(!flag[i] && cnt==3 && i==n)
            {
                t--;
                k = ans;
                cnt = 1;
                flag[i] = 1;
                cout<<i<<endl;
            }
            else if(!flag[i] && i!=n && cnt==3)
            {
                t--;
                cnt = 1;
                flag[i] = 1;
                cout<<i<<endl;
            }
            else if(!flag[i] && i==n && cnt!=3)
            {
                cnt = 3;
            }
            else if(!flag[i] && i!=n && cnt!=3)
            {
                cnt++;
            }
            else if(flag[i] && i==n)
            {
                cnt = 3;
            }
        }
    }
    printf("%d %d", ans, k);
    fclose(stdin);
    fclose(stdout);




    return 0;
}
