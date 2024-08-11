#include<bits/stdc++.h>
using namespace std;
int T, M, a, b, c, v, s, r;
double x, p1, p2;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    for(int i=1;i<=T;i++){
        cin >> a >> b >> c;
        s=b*b-4*a*c;
        if(s<0) cout << "NO" << endl;
        else{
            x=((b*-1)+sqrt(s))/(2*a);
            for(int j=(M*-1);j<=M;j++){
                for(int k=1;k<=M;k++){
                    for(int l=1;l<=M;l++)
                        if(j+k*sqrt(j)==x)
                        {
                            p1=j;
                            p2=k;
                            r=l;
                        }
                }
            }
            if(p1!=0) cout << p1 << "+" << endl;
            if(p2==1) cout << "sqrt(" << r << ");" << endl;
            else if((int)p2%1==0) cout << p2 << "*sqrt(" << r << ");" << endl;
            else cout << "sqrt(" << r << ")/" << p1 << ";" << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
