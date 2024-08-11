#include <bits/stdc++.h>
using namespace std;

float delta(int a,int b,int c)
{
    return b * b - 4.0 * a * c;
}

bool shigen(int a, int b, int c)
{
    float dlt = delta(a,b,c);
    if (dlt >= 0) {return true;}
    else {return false;}
}
/*
float solve(int a,int b,int c)
{
    float dlt = delta(a,b,c);
    float sdlt = sqrt(dlt);
	if (dlt == 0) {
        return -1 * (b / 2*a );
    } else {
        if (sdlt-sdlt/10 == 0){
            return max(b * -1 + sdlt/2*a,b*-1+sdlt/2*a);
        } else {
            return NULL;
        }
    }
}
*/
int gcd(int a,int b)
{
    int k=-1;
    for (int i = 1; i* i <=max(a,b);i++)
    {
        if (a % i == 0) {
            if (b % i == 0){
                k = max(k,i);      
            }
        }
    }
    return k;
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
	int pf[10] = {1,4,9,16,25,36,49,64,81,100};
	int sqtf[10] = {1,2,3,4,5,6,7,8,9,10};
	int a,b,c;
    int t,m;
    cin >> t >> m;
    int dlt = delta(a,b,c);
	float sdlt = sqrt(dlt);
	string root;
    for (int i = 1;i<= t;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (shigen(a,b,c))
        {
            //solve
			if (dlt == 0) {
		        return -1 * (b / 2*a );
		    } else {
		        if (sdlt-sdlt/10 == 0){
		            // cout << gcd(dlt*dlt,2*a);
					cout << max(b * -1 + sdlt/2*a,b*-1+sdlt/2*a);
		        } else {
					for (int i = 1;i<= t ; i++)
					{
						int dlt2 = dlt;
						if ((dlt2 - dlt2 / pf[i]/ 10) ==0)
			            {
			            	dlt2 /= pf[i];
			            	int qtf=0;
			            	qtf += sqtf[i];
							printf("%d+%d*sqrt(%d)",b*-1,qtf,dlt2);
						}
					}
		        }
		    }
        } else {
            cout << "NO";
        }
    }
    return 0;
}
