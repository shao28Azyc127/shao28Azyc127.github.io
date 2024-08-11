#include<bits/stdc++.h>
using namespace std;
long long n,l;
int qq[76]={2,3,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,121,127,131,137,139,149,151,157,163,167,169,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,289,293,307,311,313,317,331,337,347,349};
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>l;
    int a,b,c;
    for(int i=0;i<n;i++){
    	cin>>a>>b>>c;
    	if(b*b-4*a*c<0){
    		cout<<"NO"<<endl;
		}else{
			int d=b*b-4*a*c;
			if(b==0&&d==0){
				cout<<"0"<<endl;
			}else if(d==0){
				if(b%(2*a)!=0){
					cout<<-b<<"/"<<2*a<<endl;
				}else{
					cout<<-b/(2*a)<<endl;
				}
			}else if(b==0){
				int dd=1;
				for(int kk=0;kk<76;kk++){
					if(d%(qq[kk]*qq[kk])==0){
						if(a%qq[kk]==0){
							a/qq[kk];
						}else{
							dd*=qq[kk];
						}
						d/=qq[kk]*qq[kk];
					}
				}if(dd==1){
					cout<<"sqrt("<<d<<")";
					if(a!=1&&a!=0){
						cout<<"/"<<2*a<<endl;
					}else{
						cout<<endl;
					}
				}else{
					cout<<dd<<"*"<<"sqrt("<<d<<")";
					if(a!=1&&a!=0){
						cout<<"/"<<2*a<<endl;
					}else{
						cout<<endl;
					}
				}
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

