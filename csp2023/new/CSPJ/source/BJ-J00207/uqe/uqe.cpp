#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long delta = 0;
  template<typename _EuclideanRingElement>
    _EuclideanRingElement
    gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
    {
      while (__n != 0)
	{
	  _EuclideanRingElement __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
    }
void solve(){
    long long a,b,c,e,f,g,h,i,j;
    long double d;
    cin >> a >> b >> c;
    delta = b * b - 4 * a * c;
    if(delta < 0){
        cout << "NO" << endl;
        return;
    }
    d = sqrt(delta);
    if(ceil(d) == d){
        e = a * 2;
        g = d - b;
        f = gcd(e,g);
        j = a * 2;
        h = 0 - d - b;
        i = gcd(e,h);
        e /= f;
        g /= f;
        h /= i;
        j /= i;
        if(e == 1 && j == 1){
            if(g > h){
                cout << g;
            }
            else{
                cout << h;
            }
        }
        else if(j == 1){
            if(g > h * e){
                if(e < 0){
                    cout << 0 - g << '/' << 0 - e;
                }
                else{
                    cout << g << '/' << e;
                }
            }
            else{
                cout << h;
            }
        }
        else if(e == 1){
            if(g * j > h){
                cout << g;
            }
            else{
                if(j < 0){
                    cout << 0-h << '/' << 0-j;
                }
                else{
                    cout << h << '/' << j;
                }
            }
        }
        else{
            if(g * j > h * e){
                if(e < 0){
                    cout << 0-g << '/' << 0-e;
                }
                else{
                    cout << g << '/' << e;
                }
            }
            else{
                if(j < 0){
                    cout << 0-h << '/' << 0-j;
                }
                else{
                    cout << h << '/' << j;
                }
            }
        }
        cout << endl;
    }
    else{
        e = a * 2;
        e *= e;
        f = a * 2;
        cout << "I can't solve it!!!!! RP++" << endl;
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m,n;
    cin >> m >> n;
    for(int i = 0;i < m;i++){
        solve();
    }
}
