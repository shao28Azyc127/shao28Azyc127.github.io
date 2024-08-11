#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10;
struct st{
	int a[N];
}a[N];
bool check(st x,st y){
	st ret;
	for(int i=1;i<=5;i++)
		ret.a[i]=x.a[i]-y.a[i];
	int num=0,sum=0;
	for(int i=1;i<=5;i++){
		if(ret.a[i]!=0&&num!=0&&ret.a[i]!=num)	return false;
		if(ret.a[i]!=0)	num=ret.a[i],sum++;
	}
	if(sum==0)	return false;
	if(sum==1)	return true;
	if(sum==2){
		for(int i=1;i<5;i++){
			if(ret.a[i]!=0&&ret.a[i+1]==0)	return false;
			if(ret.a[i]!=0&&ret.a[i+1]!=0)	return true;
		}
		return false;
	}
	return false;
}
st s(int a,int b,int c,int d,int e){
	st ret;
	ret.a[1]=a,ret.a[2]=b,ret.a[3]=c,ret.a[4]=d,ret.a[5]=e;
	return ret;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i].a[j];
	int ans=0;
	for(int aa=0;aa<=9;aa++)
		for(int b=0;b<=9;b++)
			for(int c=0;c<=9;c++)
				for(int  d=0;d<=9;d++)
					for(int e=0;e<=9;e++){
						int can=1;
						for(int i=1;i<=n;i++)
							can*=check(s(aa,b,c,d,e),a[i]);
						if(can)
							ans++;
					}
	cout<<ans<<endl;
	return 0;
}