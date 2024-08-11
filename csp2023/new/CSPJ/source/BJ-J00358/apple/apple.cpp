#include<bits/stdc++.h>
using namespace std;
struct data{
	int num;
	int key;
}a[100000001];
int n,q,r,m;	bool f=0;
bool cmp(data x,data y){
	if(x.num==y.num) return x.key<y.key;
	return x.num>y.num;
}
bool pd(){
	for(int i=1;i<=n;i++){
		if(a[i].num==1) return true;
	}
	return false;
}
int pd2(){

	int x=0;
	for(int i=1;i<=n;i++){
		if(a[i].num==1) x++;
	}
	return x;
}
void len(int &n){
	while(a[n].num==0) n--;
}
int main(){
	//int n,q,r;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	m=n;
	for(int i=0;i<=n;i++){
		a[i].key=i;
		a[i].num=1;
	}
	while(pd()){
		int k=0;
	
		for(int i=1;i<=n;i++){
			if(a[i].num==1)k++;
			if(k%3==1){
				a[i].znum=0;
			}
			for(int j=1;j<=n;j++){
				if(a[j].key==m&&a[j].num==0&&f==0){
					r=q;
					f=1;
					break;
				}
			}
		}q++;
		len(n);
		sort(a+1,a+1+n,cmp);
		
	}

	cout<<""<<q<<" "<<q;
	return 0;
}