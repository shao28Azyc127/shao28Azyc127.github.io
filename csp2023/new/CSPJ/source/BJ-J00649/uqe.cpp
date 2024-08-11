#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
void fun(int* a,int* b){
	for(int i=min(abs(*a),abs(*b));i>=2;i--){
		if(*a%i==0&&*b%i==0){
			*a/=i;
			*b/=i;
		}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>n>>m;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		int k=b*b-a*4*c;
		int p=sqrt(k);
		if(k<0){
			cout<<"NO\n";
			continue;
		}
		if(p*p==k){
			int r,w=2*a;
			if(a>0){
				r=-b+p;
			}else{
				r=-b-p;
			}
			fun(&r,&w);
			if(w<0){
				r=-r;
				w=-w;
			}
			if(w==1){
				cout<<r;
			}else{
				cout<<r<<"/"<<w;
			}
			cout<<"\n";
			continue;
		}
		int e1=-b,e2=2*a;
		fun(&e1,&e2);
		if(e2<0){
			e2=-e2;
			e1=-e1;
		}
		bool f=0;
		if(e1==0){
			f=1;
		}
		if(e1!=0&&e2==1){
			cout<<e1;
		}else if(e1!=0){
			cout<<e1<<"/"<<e2;
		}
		int c1=0;
		int w=2*a;
		if(w<0)
			w=-w;
		for(int i=p;i>=1;i--){
			if(k%(i*i)==0){
				c1=i;
				k/=(i*i);
				break;
			}
		}
		fun(&c1,&w);
		if(c1==0||c1==1){
			if(w==1){
				if(f){
					cout<<"sqrt("<<k<<")";
				}else{
					cout<<"+sqrt("<<k<<")";
				}
			}else{
				if(f){;
					cout<<"sqrt("<<k<<")/"<<w;
				}else{
					cout<<"+sqrt("<<k<<")/"<<w;
				}
			}
		}else{
			if(w==1){
				if(f){
					cout<<c1<<"*sqrt("<<k<<")";
				}else{
					cout<<"+"<<c1<<"*sqrt("<<k<<")";
				}
			}else{
				if(f){
					cout<<c1<<"*sqrt("<<k<<")/"<<w;
				}else{
					cout<<"+"<<c1<<"*sqrt("<<k<<")/"<<w;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}