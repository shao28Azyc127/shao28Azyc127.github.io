#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0,f=1;
	while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
	while(isdigit(c)){s=s*10+c-'0';c=getchar();}
	return s*f;
}
long long n , ans;
bool a[1000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    cin>>n;
    long long a1 , a2;
    long long sum = n;
    for(int i = 1;i<=n;i++){
    	for(int j = 1;j<=n;j++){
    		if(a[j] == false){
    			if(j == n){
    				a2 = i;
				}
    			///cout<<j<<" ";
    			a[j] = true;
				long long u = 2;
    			sum--;while(u!=0){
				j++;
				if(a[j] == false)
				  {
				  	u--;
				  }
			}
			}


		}//cout<<endl;
		if(sum == 0){
		cout<<i<<" ";
			break;

		}
	}
	cout<<a2<<endl;
	return 0;
}
