#include<iostream>
using namespace std;
unsigned long long n,ans1,ans2,i2=1;
bool a[10000005],b;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1<<" "<<1<<endl;
		return 0;
	}else if(n==2){
		cout<<2<<" "<<2<<endl;
		return 0;
	}else if(n==3){
		cout<<3<<" "<<3<<endl;
		return 0;
	}else if(n==4){
		cout<<3<<" "<<1<<endl;
		return 0;
	}else if(n==5){
		cout<<4<<" "<<4<<endl;
		return 0;
	}else if(n==6){
		cout<<4<<" "<<2<<endl;
		return 0;
	}else if(n==7){
		cout<<4<<" "<<1<<endl;
		return 0;
	}else if(n==8){
		cout<<5<<" "<<5<<endl;
		return 0;
	}else if(n==9){
		cout<<5<<" "<<3<<endl;
		return 0;
	}else if(n==10){
		cout<<5<<" "<<1<<endl;
		return 0;
	}else{
		a[1]=1;
		for(unsigned long long j=1;j;j++){
			for(unsigned long long i=i2;i<=n;){
				for(unsigned long long k=1;k<=3;k++){
					while(1){
						if(a[i]==1)i++;
						else break;
					}
					i++;
				}
				while(1){
					if(a[i]==1)i++;
					else break;
				}
				a[i]=1;
				if(i==n&&(n-1)%3!=0){
					ans2=j;
			}
			for(unsigned long long i=1;i<=n;i++){
				if(a[i]==0){
					i2=i;
					b=1;
					break;
					}
				}
			if(b==0){
				ans1=j;
				if((n-1)%3==0)ans2=1;
				cout<<ans1<<" "<<ans2<<endl;
				return 0;
				}	
			}
		}
	}
	return 0;
}
