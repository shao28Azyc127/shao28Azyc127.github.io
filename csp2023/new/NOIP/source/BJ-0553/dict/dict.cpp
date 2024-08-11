#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[50];
	int n,m,s,l;
	bool answ[50];
	string b[50];
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);


	/*cin>>a[1];
	if(a[1]>'A'){
		cout<<"T";
	}else{
		cout<<"F";
	}*/
	cin>>n>>m;
	//cout<<n<<m;
if(n==1){
	cout<<"1";
}else if(m==1){


        for(int i=1;i<=n;i++){
		cin>>a[i];
	}


	for(int i=1;i<=n;i++){
		//cin>>a[i];
	//if(i==1){
	
	//	answ[1]=1;
	//}else{
		answ[i]=1;
		for(int j=1;j<n;j++){
			if(a[i]>=a[j] && i!=j){
				answ[i]=0;

					//debugging
	//				if(i=14)
	//	cout<<a[i]<<" "<<j<<" "<<a[j]<<" F"<<endl;





			}
		}

	//}
	//debugging
	//
	//cout<<i<<endl;
	//
	//
	
	}
	for(int k=1;k<=n;k++){
		cout<<answ[k];
	}
}else if(m==2){
//	cin>>b[1];
//	cout<<b[1][0]<<" "<<b[1][1];
	char tmptgt[5],tmpsrc[5];
	for(int i=1;i<=n;i++){
                cin>>b[i];
        }
	for(int i=1;i<=n;i++){
		answ[i]=1;
	//	if(b[i][0]>b[i][1]){
	//		tmptgt[1]=b[i][1];tmptgt[2]=b[i][0];
	//	}else{tmptgt[1]=b[i][0];tmptgt[2]=b[i][1];}
		for(int j=1;j<=n;j++){
	//		if(b[j][0]>b[j][1]){
	//			tmpsrc[1]=b[j][0];tmpsrc[2]=b[j][1];
	//	}else{tmpsrc[1]=b[j][1];tmpsrc[2]=b[j][0];}

		if(i!=j){
		//else if(tmptgt[1]>tmpsrc[1]){answ[i]=0;}
		//else if(tmptgt[1]=tmpsrc[1] && tmptgt[2]>=tmpsrc[2]){answ[i]=0;}
		if(b[i][0]>b[i][1]){
			//if(i==4)cout<<"H"; //debug
			if(b[i][1]>b[j][1] && b[i][1]>b[j][0]){answ[i]=0;}
			else if(b[i][1]==b[j][1] && b[i][0]>=b[j][0] && b[j][1]>b[j][0]){answ[i]=0;}
			else if(b[i][1]==b[j][0] && b[i][0]>=b[j][1] && b[j][0]>b[j][1]){answ[i]=0;}
		}else{
			if(b[i][0]>b[j][1] && b[i][0]>b[j][0]){answ[i]=0;}
                        else if(b[i][0]==b[j][1] && b[i][1]>=b[j][0] && b[j][1]>b[j][0]){answ[i]=0;}
                        else if(b[i][0]==b[j][0] && b[i][1]>=b[j][1] && b[j][0]>b[j][1]){answ[i]=0;}
		}

		}
		//debug
		// if(i==4){
                 //      cout<<b[i][0]<<b[i][1]<<" "<<b[j][0]<<b[j][1]<<" "<<answ[i]<<endl;}

		
		
		}
			}
	for(int k=1;k<=n;k++){
                cout<<answ[k];
        }

}else{
	for(int k=1;k<=n;k++){
                cout<<random()%2;
        }


}


	return 0;

}





// Nov.18, 2023 NOIP
//By Tim Kevin
//Beijing, P.R.China