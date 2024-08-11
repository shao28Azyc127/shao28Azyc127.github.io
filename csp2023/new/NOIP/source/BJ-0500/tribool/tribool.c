#include<stdio.h>
#define G getchar_unlocked()
r(){
  int i=0,c,f=0;
  while((c=G)<48)c=='-'&&(f^=1);
  for(;c>47;c=G)i=i*10+(c^48);
  return f?-i:i;
}
char nc(){
  char c=G;
  while(c=='\n'||c=='\r'||c==' ')c=G;
  return c;
}
min(a,b){return a<b?a:b;}
rev(char c){if(c=='U')return -1;if(c=='F')return 0;return 1;}
int n,m;
int trib[59049+1][10],sum=0,last[10];
char op[10];int x[10],y[10];
sumU(t){int s=0;for(int i=0;i<n;++i)trib[t][i]==-1&&(++s);return s;}
void dfs1(int d){
  if(d==n){
    for(int i=0;i<n-1;++i)
      trib[sum+1][i]=trib[sum][i];
    ++sum;return;
  }
  for(int i=-1;i<=1;++i)
    trib[sum][d]=i,dfs1(d+1);
}

main(){
  freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
  int c=r(),t=r();
  //printf("%d %d\n",c,t);
  if(c==1||c==2){
    //putchar('1');
    while(t--){
      int ans=2147483647;
      scanf("%d%d",&n,&m);
      sum=0;dfs1(0);
      //printf("sum=%d\n",sum);
      //for(int i=0;i<sum;++i,puts("")){
        //printf("[Number %d]: ",i);for(int j=0;j<n;++j)printf("%d ",trib[i][j]);
      //}
      for(int i=0;i<m;++i){
        op[i]=nc();
        if(isalpha(op[i]))x[i]=r()-1;
        else x[i]=r()-1,y[i]=r()-1;
        //printf("x[i]=%d y[i]=%d\n",x[i],y[i]);
      }

      //printf("QWQ\n");
      for(int i=0;i<sum;++i){
        //printf("QWQ\n");
        for(int j=0;j<n;++j)last[j]=trib[i][j];
        //for(int j=0;j<n;++j)printf("%d ",last[j]);puts("");
        for(int j=0;j<m;++j){
          if(isalpha(op[j]))last[x[j]]=rev(op[j]);//,printf("%d\n",last[x[j]]);
          else{
            //printf("%c %d %d\n",op[j],last[x[j]],last[y[j]]);
            if(op[j]=='-'&&(last[y[j]]^-1))last[x[j]]=!last[y[j]];
            else last[x[j]]=last[y[j]];
          }
        }
        for(int j=0;j<n;++j)
          if(last[j]^trib[i][j])goto _;
        //printf("i=%d passed\n",i);
        //for(int j=0;j<n;++j)printf("%d ",trib[i][j]);puts("");
        ans=min(ans,sumU(i));
        _:;
      }
      printf("%d\n",ans);
    }
  }
  else if(c==3||c==4){
    while(t--){
      int ans=0;
      scanf("%d%d",&n,&m);
      while(m--){
        *op=nc(),r();
        if(*op=='U')++ans;
      }
      printf("%d\n",ans);
    }
  }
  else if(c==5||c==6){
    while(t--){
      char opt;int x,ans=0;
      _Bool tri[100000];
      memset(tri,0,sizeof(tri));
      scanf("%d%d",&n,&m);
      for(int i=0;i<m;++i){
        opt=nc();
        if(opt=='U'){tri[r()-1]=1;}
        else x=r()-1,tri[x]=tri[r()-1];
      }
      for(int i=0;i<n;++i)ans+=tri[i];
      printf("%d\n",ans);
    }
  }
  else{
    ;
  }
}
