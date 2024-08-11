#include<iostream>
#include<cmath>
using namespace std;
int ls[100];
int k=0;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n; int m;
    cin >> n >> m;
    for(int i=1; i*i<=1000; i++)
    {
        ls[++k]=i*i;
    }
    while(n--)
    {
        int a; int b; int c;
        cin >> a >> b >> c;
        if(c==0)
        {
            cout << max(0, -b) << endl;
        }else if(b==0)
        {
            if(c>0) cout << "NO" << endl;
            else if(c==0) cout << 0 << endl;
            else{
                int pos=0;
                for(int i=1; i<=k; i++)
                {
                    if(ls[i]==c)
                    {
                        pos=i;
                        break;
                    }
                }
                if(pos)
                {
                    cout << pos << endl;
                }else{
                    cout << 4 << endl;
                }
            }
        }
        else cout << max((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a)) << endl;
    }
    return 0;
}
