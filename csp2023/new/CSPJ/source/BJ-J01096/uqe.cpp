#include<bits/stdc++.h>
using namespace std;
int g(int a,int b){
	if(a==0||b==0){
		return max(a,b);
	}
	if(a>b){
		return g(a%b,b);
	} else{
		return g(a,b%a);
	}
}
int a1[2000];
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int nt,yt;
	cin>>nt>>yt;
	for(int i=1;i<=nt; i++){
		memset(a1,0,sizeof(a1));
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b-4*a*c<0){
			cout<<"no"<<endl;
			continue;
		}
		int t=b*b-4*a*c,j=2;
		while(j<=t){
			if(t%j==0){
				t=t/j;
				a1[j]++;
			} else{
				j++;
			}
		}
		if(t<1000){
			a1[t]++;
		}
		int sum=1;
		for(int j=1; j<=1000; j++){
			for(int k=1; k<=a1[j]/2; k++){
				sum=sum*j;
			}
		}
		if(b*b-4*a*c==0) sum=0;
		if(b*b-4*a*c==sum*sum){
			int cs=g(abs(-b+sum),abs(2*a));
			if((-b+sum<=0)+(2*a<=0)==1){
				if(abs(2*a/cs)==1){
					cout<<"-"<<abs(-b+sum)/cs<<endl;
				} else{
					cout<<"-"<<abs(-b+sum)/cs<<"/"<<abs(2*a)/cs<<endl;
				}
			} else{
				if(abs(2*a)/cs==1){
					cout<<abs(-b+sum)/cs<<endl;
				} else{
					cout<<abs(-b+sum)/cs<<"/"<<abs(2*a)/cs<<endl;
				}
			}
		}else{
			if(sum!=1){
				int cs=g(abs(sum),abs(2*a)),tmp=2*a;
				if((-b>=0)+(2*a>=0)!=1){
					if(2*a/cs==1){
						cout<<sum/cs<<"*";
						cout<<"sqrt("<<b*b-4*a*c/sum/sum<<")"<<endl;
					} else{
						cout<<sum/cs<<"*";
						cout<<"sqrt("<<b*b-4*a*c/sum/sum<<")";
						cout<<"/"<<tmp/cs<<endl;
					}
					
				}else{
					if(2*a/cs==1){
						cout<<"-"<<sum/cs<<"*";
						cout<<"sqrt("<<b*b-4*a*c/sum/sum<<")"<<endl;
					} else{
						cout<<"-"<<sum/cs<<"*";
						cout<<"sqrt("<<b*b-4*a*c/sum/sum<<")";
						cout<<"/"<<tmp/cs<<endl;
					}
					
				}
				
			} else{
				cout<<"sqrt("<<b*b-4*a*c/sum/sum<<")"<<"/"<<2*a<<endl;
			}
		}
	}
	return 0;
}