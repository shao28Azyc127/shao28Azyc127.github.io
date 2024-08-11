#include<bits/stdc++.h>
using namespace std;

int k=3,n,day=1,s=0,g=0;
int a[10005];


int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);

cin>>n;
for(int i=1;i<=n;i++){
	a[i]=1;
}
while(true){


k=3;
for(int i=1;i<=n;i++){

	if(a[i]==1){
		
		if(k==3){
			a[i]=0;
			k=1;
		}else {
			k++;
		}
	}else if(a[i]==0){
		continue;
	}
}
if(a[n]==0&&g==0){
	s=day;
	g=1;
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)
		flag=1;
	}
	if(flag==0)
	break;
	day++;
}
cout<<day<<" "<<s;


fclose(stdin);
fclose(stdout);
return 0;
}
