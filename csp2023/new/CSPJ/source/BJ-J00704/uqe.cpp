#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1200;
bool vis[N];
int n,t,pos,p[N],q[N];
int qs(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int cj(int x){
	for(int i=1;i<=N;i++)
		q[i]=0;
	int i=1;
	while(x>1&&i<=pos){
		if(x%p[i]==0){
			q[p[i]]++;
			x/=p[i];
			continue;
		}else{
			i++;
		}
	}
	int an=0;
	for(int i=1;i<=pos;i++){
		if(q[p[i]]>1)
			an+=qs(p[i],q[p[i]]/2);
	}
	return an;
}
int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void init(){
	for(int i=2;i<=N;i++){
		bool flag=false;
		for(int j=1;j<=pos;j++){
			if(i%p[j]==0){
				flag=true;
				break;
			}
		}
		if(!flag){
			++pos;
			p[pos]=i;
		}
	}
	for(int i=1;i<=33;i++)
		vis[i*i]=true;
	vis[0]=true;
	cin>>n>>t;
}
int main(){
	init();
	freopen("upe.in","r",stdin);
	freopen("upe.out","w",stdout);
	for(int i=1;i<=n;i++){
		int a,b,c,der;
		cin>>a>>b>>c;
		der=b*b-4*a*c;
		if(der<0){
			cout<<"NO"<<endl;
			continue;
		}else{
			if(vis[der]){
				int t=-b+sqrt(der);
				int t2=2*a;
				if(t%t2==0){
					cout<<t/t2<<endl;
				}else{
					int t3=gcd(t,t2);
					if(t2/t3<0){
						t2=-t2;
						t=-t;
					}
					cout<<t/t3<<"/"<<t2/t3<<endl;
				}
			}else{
				int t=2*a;
				int t2=cj(der),t3;
				if(t2!=0)
					t3=der/(t2*t2);
				else
					t3=der;
				if(-b%t==0)
					cout<<-b/t<<"+";
				else{
					int t4=gcd(-b,t);
					if(t/t4<0){
						b=-b;
						t=-t;
					}
					cout<<-b/t4<<"/"<<t/t4<<"+";
				}
				if(t2%t==0){
					if(t2==0||t2==1)
						cout<<"sqrt("<<t3<<")"<<endl;
					else
						cout<<t2/t<<"*sqrt("<<t3<<")"<<endl;
				}
				else{
					int t4=gcd(t2,t);
					if(t/t4<0){
						t2=-t2;
						t=-t;
					}
					if(t2/t4==1){
						cout<<"sqrt("<<t3<<")/"<<t/t4<<endl;
					}else{
						cout<<t2/t4<<"*sqrt("<<t3<<")/"<<t/t4<<endl;
					}
				}
			}
		}
	}
	return 0;
}