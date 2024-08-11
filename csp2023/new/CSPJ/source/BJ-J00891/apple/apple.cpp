#include<iostream>
using namespace std;
bool pd(bool a[],int n)
{
     for(int i = 0;i < n;i++)
     {
        if(a[i] == true)
        {
            return true;
        }
     }
     return false;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    bool a[n];
    for(int i = 0;i < n;i++)
    {
        a[i] = true;
    }
    int ans = 0;
    int ans1;
    while(pd(a,n))
    {
        ans = ans + 1;
        int num = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i])
            {
                num++;
            }
            if(num % 3 == 1 && a[i] == true)
            {
                a[i] = false;
                if(i == n-1)
                {
                    ans1 = ans;
                }
            }
        }
    }
    cout<<ans<<" "<<ans1;
    return 0;
}