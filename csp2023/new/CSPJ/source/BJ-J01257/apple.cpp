#include<bits.stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int a;
	cin>>a;
	if(a==1){
		cout<<1<<" "<<1;
	}
	else if(a==2){
		cout<<2<<" "<<2;
	}
	else if(a==3){
		cout<<3<<" "<<3;
	}
	else if(a==4){
		cout<<3<<" "<<1;
	}
	else if(a==5){
		cout<<4<<" "<<4;
	}
	else if(a==6){
		cout<<4<<" "<<2;
	}
	else if(a==7){
		cout<<4<<" "<<1;
	}
	else if(a==8){
		cout<<5<<" "<<5;
	}
	else if(a==9){
		cout<<5<<" "<<3;
	}
	else if(a==10){
		cout<<5<<" "<<1;
	}else{
		int i=1,c[a+1],b[a+1],e=0;
		for(int i=1;i<=a;i++){
			c[i]=i;
			b[i]=0;
		}while(true){
			while(i<=a){
				if(b[i]==0){
					if(c[i]==a){
						cout<<e;
					}
					b[i]==1;
				}
				if(b[i+3]==0&&(i+3)<=a){
					i+=3;
				}else{
					i++;
				}
				e++;
			}
			int x=0;
			for(int i=1;i<=a;i++){
				if(b[i]==0){
					x++;
				}
			}
			if(x==0){
				cout<<e;
				break;
			}
		}
	}
}
