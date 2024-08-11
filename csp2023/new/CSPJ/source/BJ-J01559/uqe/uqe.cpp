#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.ans","w",stdout);
	int a,b,c,t,m,s=0,v=0,s1=0,s2=0;cin>>t>>m;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		s=b*b-4*a*c;
		if(s<0)cout<<"NO";
		else{
			s1=(-b+sqrt(s))/2*a;
			s2=(-b-sqrt(s))/2*a;
				if(s1>s2&&s1==floor(s1))cout<<s1<<endl;
				else if(s2>s1&&s2==floor(s2)) cout<<s2<<endl;
				else{
					int q1=(-b)/2a; if(q1!=0)printf("%d+",q1);
					int q2=2a if(q2==1) cout<<"sqrt("<<floor(s)<<")";
					else if(q2==floor(q2)) cout<<q2<<"*sqrt("<<floor(s)<<")";
					else if((1/q2)==floor(1/q2)) cout<<"sqrt("<<floor(s)<<")/"<<1/q2;
//else cout<<
				}
		}	
	}
}
