#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n,d;
	scanf("%d%d",&n,&d);
	int a[N],p[N];
	for(int i=1;i<=n-1;i++){
        scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
        scanf("%d",p+i);
	}

	int mi_p=p[1];
	int rem=0;//
	int sum=0;
	if(a[1]%d==0){
		sum+=a[1]/d*p[1];
	}else{
		sum+=(a[1]/d+1)*p[1];
		rem=(a[1]/d+1)*d-a[1];
	}
	for(int i=2;i<=n-1;i++){
		a[i]-=rem;
		rem=0;
		mi_p=min(mi_p,p[i]);
		if(a[i]%d==0){
			sum+=a[i]/d*mi_p;
		}else{
			sum+=(a[i]/d+1)*mi_p;
			rem=(a[i]/d+1)*d-a[i];
		}
	}

	cout<<sum;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
