#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int f[100005];
int sta[100005];
int top = 1;
int sum = 0;
int price = 0;

void dfs(int ed)
{
    int minn = 1e9,mini = 1;
    for(int i = 1;i < ed;i ++)
    {
        //cout << minn <<" ";
        if(minn > a[i])
        {
            mini = i;
            minn = a[i];
        }

    }
    if(mini == 1)
        return;
    sta[++top] = mini;
    dfs(mini-1);

}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >>d;
    f[0] = f[1] = 0;
    for(int i = 2;i <= n;i ++)
    {
        cin >> v[i];
        f[i] = f[i-1] + v[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sta[1] = n;
    dfs(n);
    sta[++top] =1;
//    int t = top;
//    while(top > 0)
//    {
//        cout << sta[top] <<" //\n";
//        top--;
//    }
//    top = t;
    while(top > 1)
    {
        int now = sta[top];
        top--;
        int next = sta[top];
        int len = f[next] - f[now];

        price += ceil(1.0 *(len - sum) / d) *a[now];
  //      cout << "/" << sum <<" ppp " << ceil((len - sum) * 1.0 / d) *a[now] << " /\n";
        sum += ceil(1.0 * len / d) * d;
        sum -= len;
    }
    cout << price;
    //cout << " ff\n"<<ceil(1.0*3/2) << endl;
    return 0;
}
