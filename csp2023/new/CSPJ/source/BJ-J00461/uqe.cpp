#include<bits/stdc++.h>
using namespace std;

const long double ld=1.0;

int t,m;
int a,b,c;

int part_sqrt(int x) //������������-O(sqrt(x))
{
    if (x<0) x=-x;
    int ret;
    int tmp=3;
    for (int i=1;i<=x;i+=tmp,tmp+=2)
    {
        if (x%i==0)
        {
            ret=i;
        }
    }
    return sqrt(ret);
}

void print(int p,int q) //sqrt(p)/q
{
    if (p<0)p=-p;
    int z=part_sqrt(p); int gcd;
    if (z!=1)
    {
        p/=z*z;
        gcd=__gcd(q,z);
        q/=gcd, z/=gcd;

        if (z!=1)
            printf("%d*",z);
    }
    if (q==1)
        printf("sqrt(%d)\n",p);
    else
        printf("sqrt(%d)/%d\n",p,q);
    return;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int p,q,gcd;
        scanf("%d%d%d",&a,&b,&c);
        double san=b*b-4*a*c;
        if (san<0) //�޽�
        {
            printf("NO\n");
            continue;
        }
        double x1=(-b+sqrt(san))/(2.0*a);
        double x2=(-b-sqrt(san))/(2.0*a);
        double maxx=max(x1,x2);
        if (maxx==int(maxx)) //��Ϊ����
        {
            printf("%d\n",int(maxx));
            continue;
        }
        //��������if����maxxΪ�����ģ�maxxΪ����
        if (c==0)
        {//��san=b*b,maxx=(-b+b)/(2a)��(-b-b)/(2a),maxxһ���Ƿ���
            //maxx=(-b+b)/(2a)=0������
            p=(-b-b), q=2*a;
            gcd=__gcd(p,q);
            p/=gcd, q/=gcd;
            if(q<0)
            {
                p=-p,q=-q;
            }
            printf("%d/%d\n",p,q);
            continue;
        }
        if (sqrt(san)==int(sqrt(san)))
        {
            p,q=2*a;
            if (x1>=x2)
            {
                p=(-b+sqrt(san));
            }
            else
            {
                p=(-b-sqrt(san));
            }
            gcd=__gcd(p,q);
            p/=gcd, q/=gcd;
            if(q<0)
            {
                p=-p,q=-q;
            }
            printf("%d/%d\n",p,q);
            continue;
        }
        //����ΪmaxxΪ������
        //maxx={(+/-)sqrt(ac)/a
        //     {(-b)/(2a)(+/-)sqrt(b^2-4ac)/2a

        if (b==0) //maxxΪ������ʱ���������
        {
            print(a*c,a);
            continue;
        }

        //maxxΪ������ʱ���������
        p=(-b), q=2*a;
        if (x2>x1) p=-p;
        gcd=__gcd(p,q);
        p/=gcd, q/=gcd;
        if (p<0&&q<0)
        {
            p=-p,q=-q;
        }
        else if(q<0)
        {
            p=-p,q=-q;
        }
        if (q==1)
            printf("%d+",q);
        else
            printf("%d/%d+",p,q);

        p=b*b-4*a*c;//p=sqrt(p)!
        q=2*a;
        //printf("\nb*b-4*a*c=%d*%d-4*%d*%d=%d-%d=%d",b,b,a,c,b*b,4*a*c,b*b-4*a*c);
        print(p,q);
    }
    return 0;
}
