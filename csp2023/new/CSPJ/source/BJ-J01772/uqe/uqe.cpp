#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0,f=1;
	while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
	while(isdigit(c)){s=s*10+c-'0';c=getchar();}
	return s*f;
}
long long T , M , a , b , c;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
     cin>>T>>M;
    while(T--){
    	cin>>a>>b>>c;
    	long long q =  b * b - 4 * (a * c);
    	if(q<0){
    		cout<<"NO"<<endl;
    		continue;
		}
		else{
			long long x1 , x2;
			x1 = ((-1 * b) + sqrt(q))/2 * a;
			x2 = ((-1 * b) - sqrt(q))/2 * a;
			cout<<max(x1,x2)<<endl;
		}
	}
	return 0;
}
