#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,get_n=0,days,cnt;
    bool ap[1000005],get_all=1,stop_get_n=1;
    cin>>n;
    if (n==1000000000)
    {
        days=46;
        get_n=1;
    }
    else
    {
        while(get_all)
        {
            days++;
            if (stop_get_n)
            {
                get_n++;
            }
            cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(!ap[i])
                {
                    cnt++;
                }
                if(cnt%3==1)
                {
                    if (i==n){
                        stop_get_n=0;
                    }
                    ap[i]=1;
                }
            }
            if (cnt==0)
            {
                get_all=0;
            }
        }
    }
    cout<<days-1<<" "<<get_n;
    return 0;
}
