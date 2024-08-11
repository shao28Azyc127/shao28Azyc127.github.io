#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	int t;
	a=abs(a),b=abs(b);
	while(a%b){
        a%=b;
        t=a;
        a=b;
        b=t;
	}
	return b;
}
int isima(int a,int b,int c){
    int x=b*b-4*a*c;
    return x<0;
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);

	int t,m;
	scanf("%d%d",&t,&m);
	int a,b,c;
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&a,&b,&c);
		double wa=-b+sqrt(b*b-4*a*c);
		if(isima(a,b,c)){
            cout<<"NO"<<endl;
		}else if(wa!=(int)wa){
            if(b==0&&c==0){
                cout<<0<<endl;
            }else if(b==0){
                int mi=min(m,gcd(a,c));
                a/=mi;
                c/=mi;
                if(c>0){
                    cout<<"NO"<<endl;
                }else{
                    if(a==1){
                        if(sqrt(-c)*sqrt(-c)==-c){
                            cout<<sqrt(-c)<<endl;
                        }else{
                            cout<<"sqrt("<<-c<<')'<<endl;
                        }
                    }else{
                        int x=1,y=-c*a;
                        for(int i=2;i<=y;i++){
                            if(y%(i*i)==0){
                                x*=i;
                                y/=x*x;
                            }
                        }
                        if(x==1){
                            cout<<"sqrt("<<y<<")/"<<a<<endl;
                        }else{
                            cout<<x<<'*'<<"sqrt("<<y<<")/"<<a<<endl;
                        }
                    }
                }
            }else if(c==0){
                int mi=min(m,gcd(a,b));
                a/=mi;
                b/=mi;
                if(a*b>0){
                    cout<<0<<endl;
                }else{
                    if(a%b==0||a==1){
                        cout<<-b/a<<endl;
                    }else{
                        cout<<abs(b)<<'/'<<abs(a)<<endl;
                    }
                }
            }else{
                cout<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
            }
		}else{
            cout<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
