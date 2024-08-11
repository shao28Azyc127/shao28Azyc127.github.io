#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
	int n,d;
	cin >> n >> d;
	int s[n+5],p[n+5];
	for(int i = 1; i <= n-1; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	double have = 0;
	int price = 0;
	if(s[1] % d == 0){
		have += s[1]/d;
		price += s[1]/d*p[1];
	}
	else{
        have += s[1]/d+1;
        price += (s[1]/d+1)*p[1];
	}
	for(int i = 2; i <= n-1; i++){
		if(s[i] <= have && p[i] >= p[i+1]){
            have -= s[i];
            have /= d;
		}
		else if(s[i] <= have && p[i] <= p[i+1]){
			int j = 2;
			while(p[j] > p[i]){
				/*have += s[j] / d;
				price += s[j] / d * p[i];
				j++;*/
				if(s[j] % d == 0){
                    have += s[j]/d;
                    price += s[j]/d*p[i];
                }
                else{
                    have += s[j]/d+1;
                    price += (s[j]/d+1)*p[i];
                }
			}
			have -= s[i];
            have /= d;
			i = j;
		}
		else if(s[i] > have && p[i] >= p[i+1]){
			if(s[i] % d == 0){
                    have += s[i]/d;
                    price += s[i]/d*p[i];
            }
            else{
                    have += s[i]/d+1;
                    price += (s[i]/d+1)*p[i];
            }
			have -= s[i];
            have /= d;
		}
		else{
			int j = 2;
			if(s[i] % d == 0){
                    have += s[j]/d;
                    price += s[j]/d*p[i];
            }
            else{
                    have += s[j]/d+1;
                    price += (s[j]/d+1)*p[i];
            }
			while(p[j] > p[i]){
				if(s[j] % d == 0){
                    have += s[j]/d;
                    price += s[j]/d*p[i];
                }
                else{
                    have += s[j]/d+1;
                    price += (s[j]/d+1)*p[i];
                }
                j++;
			}
			have -= s[i];
            have /= d;
			i = j;
		}
	}
	cout << price << endl;
	return 0;
}
