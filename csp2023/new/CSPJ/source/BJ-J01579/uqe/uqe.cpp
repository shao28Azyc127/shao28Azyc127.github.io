//��ģ�⣬ϲ���ձ�
#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int T,M;
int delta;
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    if(b%a==0)
        return a;
    if(a>b)
        return gcd(b,a%b);
    if(b>a)
        return gcd(a,b%a);
}
int getpr(int x)
{
    int res=1;
    for(int i=sqrt(x);i>=2;i--)
    {
        int sqi=i*i;
        if(x%sqi==0)
        {
            res*=i;
            x/=sqi;
        //    cout<<x<<' '<<sqi<<endl;
        }
    }
    return res;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        delta=b*b-(4*a*c);

        //�޽��ж����Ѽ�飩
        if(delta<0)
        {
            printf("NO\n");
            continue;
        }
        int sqdelta=sqrt(delta);

        //������������Ѽ�飩
        if(sqdelta*sqdelta==delta)
        {
            int p;
            if(a>0) p=-b+sqdelta;
            if(a<0) p=-b-sqdelta;
            int q=2*a;
            if(q<0)
            {
                p=-p;
                q=-q;
            }
            if(p%q==0)
            {
                printf("%d\n",p/q);
                continue;
            }
            else
            {
                int g;
                if(p>0)
                    g=gcd(p,q);
                else
                    g=gcd(-p,q);
                p/=g;
                q/=g;
                printf("%d/%d\n",p,q);
                continue;
            }
        }

        //���������
        else
        {
            b=-b;
            //ǰ�ô�����ϵ����2a����p2�����Լ���Ķ���
            int pr=getpr(delta);
            delta/=(pr*pr);
            if(a<0)
            {
                a=-a;
                b=-b;
             //   pr=-pr;
            }
            a*=2;
            int g;

            //�������������
            if(b!=0)
            {
                //�����ж�
                if(b%a==0)
                {
                    printf("%d+",b/a);
                }
                //�������
                else
                {
                    if(b>0) g=gcd(b,a);
                    else g=gcd(-b,a);
                    int memoa=a;
                    b/=g;
                    memoa/=g;
                    printf("%d/%d+",b,memoa);
                }
            }

            //�������������
            //��Լ������
            if(pr!=1 && a!=1)
            {
              //  cout<<a<<' '<<pr<<endl;
                g=gcd(a,pr);
              //  cout<<g<<endl;
                a/=g;
                pr/=g;
            //    cout<<a<<' '<<pr<<endl;
            }
            if(a==1 && pr!=1)
            {
                printf("%d*sqrt(%d)\n",pr,delta);
                continue;
            }
            if(a!=1 && pr==1)
            {
                printf("sqrt(%d)/%d\n",delta,a);
                continue;
            }
            if(a==1 && pr==1)
            {
                printf("sqrt(%d)\n",delta);
                continue;
            }
            if(a!=1 && pr!=1)
            {
                printf("%d*sqrt(%d)/%d\n",pr,delta,a);
                continue;
            }
        }
    }
    return 0;
}
