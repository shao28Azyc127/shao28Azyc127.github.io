#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
string s;
int n;
int cnt;
int sum;
int k;
int a[2000010];
int b[2000010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	// cout<<1;
	cin>>s;
	for(int i=0;i<n;i++){

        for(int j=n-1;j>i;j--){
            if((j-i+1)%2==0){
                bool f=0;

                for(int k=i;k<=(j+i)/2;k++){
                    if(s[k]!=s[j-k+i]){
                        f=1;
                        break;
                    }

                }
                if(!f){
                    //cout<<i<<" "<<j<<"\n";
                    a[i]++;
                    b[j]++;
                    sum++;
                    if(k<j){
                        cnt++;
                        k=j;
                    }
                }
            }
        }
	}
	int cntt=0;
	for(int i=1;i<n-1;i++){
        if(s[i]!=s[i+1])
            cntt+=b[i]*a[i+1];
	}
	//cout<<sum<<endl;
	cout<<sum+cntt<<endl;
	//cout<<sum+cnt*(cnt-1)/2;
	return 0;
}
