#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
int types;
int possibilities[10][6];
int p[10];
int minuses[10][6];
int m[10];
int m2[10];
bool themap[20][10][10];

int rds[20][10];

int mains[20][10];
int ans;
int answercount=100000;
ifstream iff;
ofstream of;
int step(int a,int b){
if(a<=b)return b-a;
else
    return b+10-a;
}
int main(){
iff.open("lock.in");
of.open("lock.out");
iff>>types;

for(int i=1;i<=types;i++){
  for(int j=1;j<=5;j++){
      iff>>possibilities[i][j];

      //p[i]=p[i]*10+possibilities[i][j];
     // m[i]=m[i]*10+(possibilities[i][j]-possibilities[i][j-1]);
  }
  }
  for(int i=0;i<100000;i++){
      bool av=false;
      int ii=i;
      for(int j=1;j<=5;j++){
        m[j]=(int)(ii/pow(10,5-j));
        ii-=m[j]*pow(10,5-j);

      }


      for(int j=1;j<=types;j++){
         bool cando=true;
         int xm=0,xp=0;
         for(int k=1;k<=5;k++){
            if(possibilities[j][k]==m[k])
                xp++;
         }

        if(xp>=4){av=true;break;}
        else{
            if(xp==3){
                for(int k=2;k<=5;k++){

                  if(possibilities[j][k]!=m[k] &&step(possibilities[j][k],m[k]) == step(possibilities[j][k-1],m[k-1]))
                      {av=true;break;}

                   }
        }
        }

      }
      ans+=av;
   }

  of<<ans-1<<endl;
}
