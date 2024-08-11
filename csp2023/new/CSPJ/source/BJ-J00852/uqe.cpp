#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long a[10000],b[10000],c[10000],n,i,j,m,d,w1,w2,W1,W2,r,N;
    cin>>n>>m;
    for(i=0;i<n;i++){
	    cin>>a[i]>>b[i]>>c[i];
	}
	for(i=0;i<n;i++){
	    d=b[i]*b[i]-4*a[i]*c[i];
	    if(d<0){
		    cout<<"NO"<<endl;
		    continue;
		}
		if(d==0){
		    w1=-b[i];
		    w2=2*a[i];
		    N=min(abs(w1),abs(w2));
		    for(j=2;j<=N;j++){
			    if(w1%j==0&&w2%j==0){
				    w1=w1/j;
				    w2=w2/j;
				    j--;
				}
			}
			if(w2==1) cout<<w1<<endl;
			else if(w2==-1) cout<<-w1<<endl;
			else if(w1*w2<0) cout<<"-"<<abs(w1)<<"/"<<abs(w2)<<endl;
			else if(w1==0) cout<<0<<endl;
			else cout<<w1<<"/"<<w2<<endl;
			continue;
		}
		if(sqrt(d)==int(sqrt(d))){
			if(a[i]>0) w1=-b[i]+sqrt(d);
			else w1=-b[i]-sqrt(d);
		    w2=2*a[i];
		    N=min(abs(w1),abs(w2));
		    for(j=2;j<=N;j++){
			    if(w1%j==0&&w2%j==0){
				    w1=w1/j;
				    w2=w2/j;
				    j--;
				}
			}
			if(w2==1) cout<<w1<<endl;
			else if(w2==-1) cout<<-w1<<endl;
			else if(w1*w2<0) cout<<"-"<<abs(w1)<<"/"<<abs(w2)<<endl;
			else if(w1==0) cout<<0<<endl;
			else cout<<w1<<"/"<<w2<<endl;
			continue;
		}
		w1=-b[i];
	    w2=2*a[i];
	    N=min(abs(w1),abs(w2));
	    for(j=2;j<=N;j++){
		    if(w1%j==0&&w2%j==0){
			    w1=w1/j;
			    w2=w2/j;
			    j--;
			}
		}
		W1=1;
		W2=2*abs(a[i]);
		for(j=2;j<=sqrt(d);j++){
		    if(d%(j*j)==0){
			    d=d/(j*j);
			    W1=W1*j;
			    j--;
			}
		}
		N=min(W1,W2);
	    for(j=2;j<=N;j++){
		    if(W1%j==0&&W2%j==0){
			    W1=W1/j;
			    W2=W2/j;
			    j--;
			}
		}
		if(w1==0) r++;
		else if(w2==1) cout<<w1<<"+";
		else if(w2==-1) cout<<-w1<<"+";
		else if(w1*w2<0) cout<<"-"<<abs(w1)<<"/"<<abs(w2)<<"+";
		else cout<<abs(w1)<<"/"<<abs(w2)<<"+";
		if(W1==1&&W2==1) cout<<"sqrt("<<d<<")"<<endl;
		else if(W2==1) cout<<W1<<"*"<<"sqrt("<<d<<")"<<endl;
		else if(W1==1) cout<<"sqrt("<<d<<")/"<<W2<<endl;
		else cout<<W1<<"*"<<"sqrt("<<d<<")/"<<W2<<endl;
	}
    return 0;
}
