#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
void print_you(int x,int y){
	double n=x*1.0/y;
	if((int)n==n){   //是整数
		cout<<n;
		return;
	}
	else{
		int a=x,b=y;
		int g=__gcd(a,b);
		if(b/g<0){
			cout<<-a/g<<"/"<<-b/g;
		}
		else cout<<a/g<<"/"<<b/g;
		return;
	}
}
void solve(){
	cin>>a>>b>>c;
	double delt=b*b-4*a*c;
	if(delt<0){
		cout<<"NO"<<endl;
		return ;
	}
	double xa=(-b+sqrt(delt))/(2*a);
	double xb=(-b-sqrt(delt))/(2*a);
	//cout<<"x:"<<xa<<" "<<xb<<endl;
	if(xa>=xb){    //x1大
		//cout<<"x1 "; 
		if(sqrt(delt)==(int)sqrt(delt)){   //是有理数
		//	cout<<"有理数 ";
			print_you(-b+sqrt(delt),2*a);
			cout<<endl;
		}
		else{
		//	cout<<"实数 ";
			double q1=(-b)*1.0/(2*a);
			//cout<<-b<<" "<<2*a<<" "<<q1<<endl;
			if(q1!=0){
				print_you(-b,2*a);
				cout<<"+";
			}
			int r=delt;
			int s=1;
			
			for(int i=(int)sqrt(delt);i>=1;i--){	
				if(r%(i*i)==0&&r>=i*i){
					r/=i*i;
					s*=i;
				}
			}
			double q2=s*1.0/(2*a);
			double q3=1/q2;
			if(q2==1){
				cout<<"sqrt("<<r<<")"<<endl;
			}
			else if(q2==(int)q2){
				cout<<q2<<"*sqrt("<<r<<")"<<endl;
			}
			else if(q3==(int)q3){
				cout<<"sqrt("<<r<<")/"<<q3<<endl;
			}
			else{
				int g=__gcd(s,2*a);
				//cout<<s<<" "<<2*a<<" "<<g<<endl;
				cout<<s/g<<"*sqrt("<<r<<")/"<<(2*a)/g<<endl;
			}
		}
	}
	else{
		if(sqrt(delt)==(int)sqrt(delt)){   //是有理数
			print_you(-b-sqrt(delt),2*a);
			cout<<endl;
		}
		else{
			double q1=(-b)*1.0/(2*a);
			if(q1!=0){
				print_you(-b,2*a);
				cout<<"+";
			}
			int r=delt;
			int s=1;
			//cout<<r<<" "<<(int)sqrt(delt)<<endl;
			for(int i=(int)sqrt(delt);i>=1;i--){	
				if(r%(i*i)==0&&r>=i*i){
					r/=i*i;
					s*=i;
				}
			}
			//cout<<r<<" "<<s<<endl;
			double q2=s*1.0/(-2*a);
			double q3=1/q2;
			if(q2==1){
				cout<<"sqrt("<<r<<")"<<endl;
			}
			else if(q2==(int)q2){
				cout<<q2<<"*sqrt("<<r<<")"<<endl;
			}
			else if(q3==(int)q3){
				cout<<"sqrt("<<r<<")/"<<q3<<endl;
			}
			else{
				int g=__gcd(s,(-2*a));
				cout<<s/g<<"*sqrt("<<r<<")/"<<(-2*a)/g<<endl;
			}
		}	
	}
}
int main(){
		freopen("uqe.in","r",stdin);
		freopen("uqe.out","w",stdout);
		cin>>T>>M;
		while(T--){
			solve();
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
