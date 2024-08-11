#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int b[9][5];
int n,l = 0,ans = 0;
bool panduan(int a,int c,int d,int e,int f){
    int sum = a+f+c+d+e;
    if(sum == a&&!d&&!c&&!e&&!f||sum == e&&!d&&!c&&!a&&!f||sum == c&&!d&&!a&&!e&&!f||
       sum == d&&!a&&!c&&!e&&!f||sum == f&&!d&&!c&&!e&&!a){
        if(a == c&&d == e&&e == f&&a == d)return 0;
        return 1;
       }
    if(sum == a+c&&a == c&&d==0&&e==0&&f==0||sum == d+c&&c == d&&a==0&&e==0&&f==0||sum == d+e&&d == e&&a==0&&c==0&&f==0
       ||sum == e+f&&e == f&&a==0&&c==0&&d==0){
       return 1;
       }
    return 0;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3] >> b[i][4];
    }
    int c,d,e,f,g;
    for(int i = 0;i<=9;i++){
		for(int j = 0;j<=9;j++){
			for(int k = 0;k<=9;k++){
				for(int l = 0;l<=9;l++){
					for(int m = 0;m<=9;m++){
						for(int o = 0;o<n;o++){
							c = (b[o][0]+i)%10;
							d = (b[o][1]+j)%10;
							e = (b[o][2]+k)%10;
							f = (b[o][3]+l)%10;
							g = (b[o][4]+m)%10;
							if(panduan(c,d,e,f,g)){
								if(o == n-1){
                                    ans++;
								}
							}else{
								break;
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
