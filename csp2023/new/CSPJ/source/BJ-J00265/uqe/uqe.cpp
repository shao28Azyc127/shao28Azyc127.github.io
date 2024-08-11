#include<bits/stdc++.h>
using namespace std;
int t,m;
bool fang(int n)
{
	double d=sqrt(n);
	if(int(d)*int(d)==double(n)) return true;
	else return false;
}
int gcd(int a,int b)
{
	if(a==1) return 1;
	if(a==0) return b;
	else if(a>b) return gcd(b,a);
	else return gcd(b%a,a);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b-4*a*c<0) cout<<"NO"<<endl;
		if((-b+sqrt(b*b-4*a*c))/2*a>=(-b-sqrt(b*b-4*a*c))/2*a){
			if(fang(b*b-4*a*c)){
				int k=sqrt(b*b-4*a*c);
				int a1=gcd(abs(-b+sqrt(b*b-4*a*c)),abs(2*a)); 
				if(2*a/a1==1) cout<<(-b+sqrt(b*b-4*a*c))/a1<<endl;
				else
				cout<<(-b+sqrt(b*b-4*a*c))/a1<<"/"<<2*a/a1<<endl;
			}
			else{
				int f;
				for(int i=b*b-4*a*c;i>=1;i--){
					if(fang(i)&&gcd(i,b*b-4*a*c)==i){ f=i; break;}
				}
				int a2=gcd(abs(-b),2*a);
				int a3=gcd(sqrt(f),2*a);
				if(f==1){
				if((-b/a2)/(2*a/a2)==0&&sqrt(b*b-4*a*c)/2*a==0) cout<<0<<endl;
				else if((-b/a2)/(2*a/a2)==0&&b*b-4*a*c==1) cout<<1<<endl;
				else if(sqrt(b*b-4*a*c)/2*a==0&&2*a/a2==1) cout<<-b/a2<<endl;
				else if((-b/a2)/(2*a/a2)==0) cout<<"sqrt("<<b*b-4*a*c<<")"<<endl;
				else if(sqrt(b*b-4*a*c)/2*a==0) cout<<-b/a2<<"/"<<2*a/a2<<endl;
				else if(2*a/a2==1&&2*a==1) cout<<-b/a2<<"+"<<"sqrt("<<b*b-4*a*c<<")"<<endl;
				else if(2*a/a2==1) cout<<-b/a2<<"+"<<"sqrt("<<b*b-4*a*c<<")"<<"/"<<2*a<<endl;
				else if(2*a==1) cout<<-b/a2<<"/"<<2*a/a2<<"+"<<"sqrt("<<b*b-4*a*c<<")"<<endl;
				else
				cout<<-b/a2<<"/"<<2*a/a2<<"+"<<"sqrt("<<b*b-4*a*c<<")"<<"/"<<2*a<<endl;
			    }
				else{
				if(sqrt(f)/a3==1){
				    if(2*a/a2==0&&2*a/a3==0) cout<<0;
				    else if(sqrt((b*b-4*a*c)/f)/(2*a/a3)==0&&2*a/a2==1) cout<<-b/a2<<"/"<<endl;
				    else if((-b/a2)/(2*a/a2)==0&&2*a/a3==1) cout<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				    else if(sqrt((b*b-4*a*c)/f)/(2*a/a3)==0) cout<<-b/a2<<"/"<<2*a/a2<<endl;
				    else if((-b/a2)/(2*a/a2)==0) cout<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
					else if((2*a/a2)==1&&2*a/a3==1) cout<<-b/a2<<"+"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				    else if(2*a/a2==1) cout<<-b/a2<<"+"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				    else if(2*a/a3==1) cout<<-b/a2<<"/"<<2*a/a2<<"+"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				    else
				    cout<<-b/a2<<"/"<<2*a/a2<<"+"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				}
				else{
				if(2*a/a2==0&&2*a/a3==0) cout<<0;
				else if((sqrt((b*b-4*a*c)/f))/2*a/a3==0) cout<<-b/a2<<"/"<<2*a/a2<<endl;
				else if((-b-a2)/2*a/a2==0&&2*a/a3==1) cout<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				else if((-b-a2)/2*a/a2==0) cout<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				else if((-b-a2)/2*a/a2==0) cout<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				else if((sqrt((b*b-4*a*c)/f))/2*a/a3==0&&2*a/a2==1) cout<<-b/a2<<"/"<<endl;
				else if(2*a/a2==1&&2*a/a3==1) cout<<-b/a2<<"+"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				else if(2*a/a2==1) cout<<-b/a2<<"/"<<"+"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				else if(2*a/a3==1) cout<<-b/a2<<"/"<<2*a/a2<<"+"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				else
				cout<<-b/a2<<"/"<<2*a/a2<<"+"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
			    }
			    }
			}
		}
		/*if((-b+sqrt(b*b-4*a*c))/2*a<=(-b-sqrt(b*b-4*a*c))/2*a){
			if(fang(b*b-4*a*c)){
				int k=sqrt(b*b-4*a*c);
				int a1=gcd(abs(-b-sqrt(b*b-4*a*c)),abs(2*a)); 
				if(2*a/a1==1) cout<<(-b-sqrt(b*b-4*a*c))/a1<<endl;
				else
				cout<<(-b-sqrt(b*b-4*a*c))/a1<<"/"<<2*a/a1<<endl;
			}
			else{
				int f;
				for(int i=b*b-4*a*c;i>=1;i--){
					if(fang(i)&&gcd(i,b*b-4*a*c)==i){ f=i; break;}
				}
				int a2=gcd(abs(-b),2*a);
				int a3=gcd(sqrt(f),2*a);
				if(f==1){
				if(2*a/a2==1&&2*a==1) cout<<-b/a2<<"-"<<"sqrt("<<b*b-4*a*c<<")"<<endl;
				else if(2*a/a2==1) cout<<-b/a2<<"-"<<"sqrt("<<b*b-4*a*c<<")"<<"/"<<2*a<<endl;
				else if(2*a==1) cout<<-b/a2<<"/"<<2*a/a2<<"-"<<"sqrt("<<b*b-4*a*c<<")"<<endl;
				else
				cout<<-b/a2<<"/"<<2*a/a2<<"-"<<"sqrt("<<b*b-4*a*c<<")"<<"/"<<2*a<<endl;
			    }
				else{
					if(sqrt(f)/a3==1){
					if(2*a/a2==1&&2*a/a3==1) cout<<-b/a2<<"-"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				    else if(2*a/a2==1) cout<<-b/a2<<"-"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				    else if(2*a/a3==1) cout<<-b/a2<<"/"<<2*a/a2<<"-"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				    else
				    cout<<-b/a2<<"/"<<2*a/a2<<"-"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				}
				else{
				if(2*a/a2==1&&2*a/a3==1) cout<<-b/a2<<"-"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				else if(2*a/a2==1) cout<<-b/a2<<"/"<<"-"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
				else if(2*a/a3==1) cout<<-b/a2<<"/"<<2*a/a2<<"-"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<endl;
				else
				cout<<-b/a2<<"/"<<2*a/a2<<"-"<<sqrt(f)/a3<<"*"<<"sqrt("<<(b*b-4*a*c)/f<<")"<<"/"<<2*a/a3<<endl;
			    }
				}
			}
		}*/
	}
	return 0;
}
/*9 1000
1 -1 0
-1 -1 -1
1 -2 1
1 5 4
4 4 1
1 0 -432
1 -3 1
2 -4 1
1 7 1*/
