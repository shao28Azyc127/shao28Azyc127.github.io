#include<bits/stdc++.h>

using namespace std;

int n,ans;
int a[10][6],b[6];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }

    for(b[1]=0;b[1]<=9;b[1]++)
    {
        for(b[2]=0;b[2]<=9;b[2]++)
        {
            for(b[3]=0;b[3]<=9;b[3]++)
            {
                for(b[4]=0;b[4]<=9;b[4]++)
                {
                    for(b[5]=0;b[5]<=9;b[5]++)
                    {
                        bool flag=true;
                        for(int i=1;i<=n;i++)
                        {
                            if(b[1]==a[i][1] && b[2]==a[i][2] && b[3]==a[i][3] && b[4]==a[i][4] && b[5]==a[i][5])
                            {
                                flag=false;
                                break;
                            }
                            int sum=0,t[6];
                            if(b[1]!=a[i][1])
                            {
                                sum++;
                                t[sum]=1;
                            }
                            if(b[2]!=a[i][2])
                            {
                                sum++;
                                t[sum]=2;
                            }
                            if(b[3]!=a[i][3])
                            {
                                sum++;
                                t[sum]=3;
                            }
                            if(b[4]!=a[i][4])
                            {
                                sum++;
                                t[sum]=4;
                            }
                            if(b[5]!=a[i][5])
                            {
                                sum++;
                                t[sum]=5;
                            }
                            if(sum>2)
                            {
                                flag=false;
                                break;
                            }

                            if(sum==2)
                            {
                                if(abs(t[1]-t[2])!=1)
                                {
                                    flag=false;
                                    break;
                                }
                                if(a[i][t[1]]-b[t[1]]==a[i][t[2]]-b[t[2]] || a[i][t[1]]+10-b[t[1]]==a[i][t[2]]-b[t[2]] || a[i][t[1]]+10-b[t[1]]==a[i][t[2]]+10-b[t[2]] || a[i][t[1]]-b[t[1]]==a[i][t[2]]+10-b[t[2]])
                                    continue;
                                flag=false;
                                break;
                            }
                        }
                        if(flag==false)
                            continue;
                        ans++;
                        //cout<<b[1]*10000+b[2]*1000+b[3]*100+b[4]*10+b[5]<<endl;


                    }
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
