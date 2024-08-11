#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int flag=0;
    cin>>n;
    int a=n;
    int b=n;
    if(n<4)
    {
        cout<<n<<" "<<n;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if((n-1)%3==0)
    {
        a=1;
    }
    while(n>=4)
    {
        if((n-1)%3==0)
        {
            n=n-((n-1)/3+1);
            flag++;
            if(flag<a)
            {
                a=flag;
                cout<<flag;
            }
        }
        if((n-1)%3==1)
        {
            n=n-((n-2)/3+1);
            flag++;
        }
        if((n-1)%3==2)
        {
            n=n-((n-3)/3+1);
            flag++;
        }
    }
    flag=flag+n;
    cout<<flag<<" ";
    if(a==b)
    {
        cout<<flag;
    }
    else
    {
        cout<<a;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
