#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)//最大公倍数 
{
	//return 1;
	if (b==0) return a;
	return gcd(b, a%b);
}

void fenshu(int a, int b)//输出a/b (a>=0,b>0)
{
	if (b==1) cout << a;
	else cout << a << "/" << b;
}

int T, M, list[6000][3], a, b, c, d, e, f;
int fenzi, fenmu;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    for(int i=0;i<T;i++) cin >> list[i][0] >> list[i][1] >> list[i][2];
    for(int i=0;i<T;i++)
    {
    	a=list[i][0];b=list[i][1];c=list[i][2];//ax^2+bx+c=0
    	d=b*b-4*a*c;//判别式
    	if (d<0)cout << "NO";
    	else
    	{
    		if (int(sqrt(d))==sqrt(d))//有理数 
    		{
    			if (a>0) fenzi=-b+sqrt(d);
    			else fenzi=-b-sqrt(d);
    			fenmu=2*a;
    			if ((fenzi<0)xor(fenmu<0)) cout << "-";
    			fenmu=abs(fenmu);fenzi=abs(fenzi);
    			e=gcd(fenmu, fenzi);//约分 
    			fenzi/=e;fenmu/=e;
    			fenshu(fenzi, fenmu);
			}
			else//无理数 
			{
				//从根号中拆平方数 根号d-->f*根号d
				f=1;
				for(int j=2; j*j<d;j++)
				{
					if (d%(j*j)==0)
					{
						d/=(j*j);
						f*=j;
						j--;
					}
				} 
				fenzi=-b;
				if (fenzi != 0)
				{
			    	fenmu=2*a;
    		    	if ((fenzi<0)xor(fenmu<0)) cout << "-";
    		    	fenmu=abs(fenmu);fenzi=abs(fenzi);
    		    	e=gcd(fenmu, fenzi);//约分 
    		    	fenzi/=e;fenmu/=e;
    		    	fenshu(fenzi, fenmu);
    		    	cout << "+";////////////////////////////////////
				}
    			fenzi=f;
				fenmu=2*a;
    			fenmu=abs(fenmu);fenzi=abs(fenzi);
    			e=gcd(fenmu, fenzi);//约分 
    			fenzi/=e;fenmu/=e;
    			if (fenzi!=1) cout << fenzi << "*";
    			cout << "sqrt(" << d << ")";
    			if (fenmu!=1) cout << "/" << fenmu;
			}
		}
		cout << endl;
	}
    return 0;
}