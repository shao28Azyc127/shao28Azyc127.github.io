#include<bits/stdc++.h>
using namespace std;
struct fenshu
{
    int p,q;
};
bool ifzheng(double a)
{

    for(int i = 1;i <= 1000;i++)
    {
        if((1.0 * i) / 1 == abs(a)) return true;
    }
    return false;
}
bool ispingfang(int k)
{
    if(k == 1) return true;
    for(int i = 2;i * i <= k;i++)
    {

        if(k == (i * i))
        {

            return true;
        }
    }
    return false;
}
fenshu find(double a)
{
    int n = abs(floor(a)) + 1;
    fenshu x;
    for(int i = 1;i <= 1000;i++)
    {
        for(int j = 0;j <= n * i;j++)
        {
            if(1.0 * j / i == a)
            {

                x.p = j;
                x.q = i;
                return x;
            }

        }

    }
    for(int i = 1;i <= 1000;i++)
    {
        for(int j = -1 * n * i;j <= 0;j++)
        {
            if(1.0 * j / i == a)
            {

                x.p = j;
                x.q = i;
                return x;
            }

        }

    }

}
struct pair1
{

    int x,y;//x : xishu
    // y : beikaifangshu
};
struct pair2
{

    int x;
    double y;
};
pair1 fixsqrt(int p1,int k)
{
    for(int i = 2;i <= sqrt(k);i++)
    {
        while(k % (i * i) == 0)
        {
            p1 *= i;
            k /= (i * i);

        }

    }
    pair1 a;
    a.x = p1;
    a.y = k;
    return a;

}
pair2 fixsqrtfs(double p1,fenshu k)
{
    int fenm = k.q;
    int fenzi = k.p;
    pair1 t1,t2;
    t1 = fixsqrt(1,fenzi);
    t2 = fixsqrt(1,fenm);
    p1 *= t1.x;
    p1 /= t2.x;
    k.p = t1.y;
    k.q = t2.y;
    pair2 ans;
    ans.x = p1;
    ans.y = (1.0 * k.p / k.q);
    return ans;
}

double a,b,c;
int t,m;
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for(int k = 1;k <= t;k++)
    {
        cin >> a >> b >> c;
        double delta = b * b - (4 * a * c);
        if(delta < 0)
        {

            cout << "NO" << endl;
            continue;
        }
        if(delta == 0)
        {

            double val = 0;
            val = -1 * (1.0 * b / (2 * a));
            if(ifzheng(val) == true)
            {

                cout << val << endl;
                continue;
            }
            fenshu ans1;
            ans1 = find(val);
            if(ans1.q == 1)
            {

                cout << ans1.p << endl;
                continue;
            }
            else
            {
                cout << ans1.p << "/" << ans1.q << endl;
                continue;

            }

        }
        if(delta > 0)
        {

            double val = 0;

            val = -1 * (1.0 * b / (2 * a));
            if(ispingfang(delta))
            {
                val += sqrt(floor(delta)) / (2 * a);
                if(ifzheng(val) == true)
                {

                    cout << val <<endl;
                    continue;
                }
                else
                {
                    fenshu ans1;
                    ans1 = find(val);
                    cout << ans1.p << "/" << ans1.q << endl;
                    continue;

                }
            }
            else
            {
                if(val != 0)
                {

                    if(ifzheng(val) == true)
                    {

                        cout << val <<"+";
                    }
                    else
                    {
                        fenshu ans1;
                        ans1 = find(val);
                        cout << ans1.p << "/" << ans1.q << "+";

                    }
                }

                double p1 = 1;
                double temp = delta;
                if(ifzheng(temp))
                {
                    pair1 temp2;
                    temp2 = fixsqrt(p1,int(temp));
                    p1 = temp2.x;
                    p1 /= (2 * a);
                    temp = temp2.y;
                    if(ifzheng(p1))
                    {
                        if(p1 < 0) p1 = abs(p1);
                        if(p1 != 1) cout << p1 << "*";
                        cout << "sqrt("<< temp <<")"<<endl;
                    }
                    else
                    {

                        fenshu ans2;
                        ans2 = find(p1);
                        if(ans2.p < 0)
                        {

                            ans2.p = abs(ans2.p);
                        }
                        if(ans2.p != 1)
                        {
                            cout<< ans2.p<< "*";

                        }
                        cout <<"sqrt(" << temp << ")" <<"/"<<ans2.q<< endl;
                    }
                }
                else
                {
                    pair2 ans1;
                    fenshu k1 = find(delta);
                    ans1 = fixsqrtfs(1,k1);
                    fenshu ans2 = find(ans1.y);
                    double p1 = ans1.x;
                    p1 /= (2 * a);
                    if(ifzheng(p1))
                    {

                        if(ans2.q == 1)
                        {
                            if(p1 < 0)
                            {

                                p1 = abs(p1);
                            }
                            if(p1 != 1)cout<< p1 << "*";
                            cout <<"sqrt("<<ans2.p<<")"<<endl;
                        }
                        else
                        {
                            if(p1 < 0)
                            {

                                p1 = abs(p1);
                            }
                            if(p1 != 1)cout << p1 << "*" ;
                            cout << "sqrt("<<ans2.p << "/" << ans2.q <<")"<<endl;
                        }
                    }
                    else
                    {

                        fenshu ans3;
                        ans3 = find(p1);
                        if(ans2.q == 1)
                        {
                            if(ans3.p < 0)
                            {
                                ans3.p = abs(ans3.p);
                            }
                            if(ans3.p != 1)
                            {
                                cout << ans3.p << "*";
                            }
                            cout << "sqrt("<<ans2.p<<")"<< "/"<<ans3.q <<endl;
                        }
                        else
                        {
                            if(ans3.p < 0)
                            {
                                ans3.p = abs(ans3.p);
                            }
                            if(ans3.p != 1)cout<< ans3.p <<"*";
                            cout << "sqrt(" << ans2.p << "/" << ans2.q <<")"<< "/" << ans3.q <<endl;
                        }
                    }
                }
            }

        }

    }


    return 0;
}
