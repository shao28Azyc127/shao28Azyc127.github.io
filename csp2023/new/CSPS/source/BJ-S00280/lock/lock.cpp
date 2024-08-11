#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int h[3];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int i,j,n,m,k,s=0,x,y,l,r,o,i1,i2,i3,i4,i5,f1,f2,f3,f4,f5,f,l1,l2,l3,l4,l5,k1,k2,k3,k4,k5;
    cin>>n;
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=5;i++)
        {
            cin>>a[j][i];
            a[j][i]++;
        }
    }
    for(i1=1;i1<=10;i1++)
    {
        for(i2=1;i2<=10;i2++)
        {
            for(i3=1;i3<=10;i3++)
            {
                for(i4=1;i4<=10;i4++)
                {
                    for(i5=1;i5<=10;i5++)
                    {
                        f=1;
                        for(i=1;i<=n;i++)
                        {
                            f1=!(i1==a[i][1]);
                            f2=!(i2==a[i][2]);
                            f3=!(i3==a[i][3]);
                            f4=!(i4==a[i][4]);
                            f5=!(i5==a[i][5]);
                            l1=((i1-a[i][1])+10)%10;
                            l2=((i2-a[i][2])+10)%10;
                            l3=((i3-a[i][3])+10)%10;
                            l4=((i4-a[i][4])+10)%10;
                            l5=((i5-a[i][5])+10)%10;
                            if(f1+f2+f3+f4+f5<1||f1+f2+f3+f4+f5>2)
                            {
                                f=0;
                                break;
                            }
                            if(f1+f2+f3+f4+f5==2)
                            {
                                // if(i4==6&&i5==0)
                                // {
                                //     cout<<"!!!"<<k4<<" "<<k5<<'\n';
                                // }
                                if(f1+f2!=2&&f2+f3!=2&&f3+f4!=2&&f4+f5!=2)
                                {
                                    f=0;
                                    break;
                                }
                                if(f1+f2==2&&l1!=l2)
                                {
                                    f=0;
                                    break;
                                }
                                if(f2+f3==2&&l2!=l3)
                                {
                                    f=0;
                                    break;
                                }
                                if(f3+f4==2&&l3!=l4)
                                {
                                    f=0;
                                    break;
                                }
                                if(f4+f5==2&&l4!=l5)
                                {
                                    f=0;
                                    break;
                                }
                            }
                        }
                        s+=f;
                        // if(f)
                        // {
                        //     h[f1+f2+f3+f4+f5]++;
                        //     if(f1+f2+f3+f4+f5==2)
                        //     {
                        //         cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<'\n';
                        //     }
                        // }
                    }
                }
            }
        }
    }
    // cout<<h[1]<<" "<<h[2]<<"\n";
    cout<<s;
    return 0;
}