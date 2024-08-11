int a[8][5],n,b[5],ans;
bool c;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	}
	if(n==1){
		printf("81");
	}
	else{
		for(int i=0;i<5;i++){
			for(int k=1;k<=9;k++){
				for(int j=0;j<5;j++){
					b[j]=a[0][j];
				}
				b[i]=(b[i]+k)%10;
				c=1;
				for(int j=1,s;j<n&&c;j++){
					for(s=0;s<5&&b[s]==a[j][s];s++){}
					if(s==5){
						c=0;
					}
					if((b[s]-a[j][s])%10==(b[s+1]-a[j][s+1])%10&&s<4){
						s++;
					}
					for(s++;s<5&&b[s]==a[j][s];s++){}
					if(s<5){
						c=0;
					}
				}
				if(c){
					ans++;
				}
			}
		}
		for(int i=0;i<4;i++){
			for(int k=1;k<=9;k++){
				for(int j=0;j<5;j++){
					b[j]=a[0][j];
				}
				b[i]=(b[i]+k)%10;
				b[i+1]=(b[i+1]+k)%10;
				c=1;
				for(int j=1,s;j<n&&c;j++){
					for(s=0;s<5&&b[s]==a[j][s];s++){}
					if(s==5){
						c=0;
					}
					if((b[s]-a[j][s])%10==(b[s+1]-a[j][s+1])%10&&s<4){
						s++;
					}
					for(s++;s<5&&b[s]==a[j][s];s++){}
					if(s<5){
						c=0;
					}
				}
				if(c){
					ans++;
				}
			}
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}