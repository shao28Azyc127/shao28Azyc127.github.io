#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _a,_b,_c;
int resPOne;
int resPTwo;
int resPThree;
int resUnder;

struct underSQRT{
  int _under;
  int _out;
};

int gcd(int a, int b){
  int mini = a;
  int res = 1;
  if(a < 0){
    a = -a;
  }
  if(b < 0){
    b = -b;
  }
  mini = a;
  if(b < a){
    mini = b;
  }
  for(int i = 2; i <= mini; i++){
    if(a % i == 0 && b % i == 0){
      res = i;
    }
  }
  return res;
}

underSQRT solve(int num){
  underSQRT cur;
  if(num<0){
    num = -num;
  }
  cur._under = num;
  cur._out = 1;
  for(int i = 2; i*i <= num; i++){
    if(cur._under % i*i == 0){
      while(cur._under % (i * i) == 0){
	cur._under /= i*i;
	cur._out *= i;
      }
    }
  }
  return cur;
}


void ICO(){
  ifstream inFile("uqe.in");
  ofstream outFile("uqe.out");
  int testNum;
  int curInt;
  int delta;
  int aTwo;
  int minusB;
  bool fu;
  underSQRT cur;
  inFile >> testNum >> curInt;
  for(int i = 0; i < testNum; i++){
    inFile >> _a >> _b >> _c;
    delta = _b * _b - 4 * _a * _c;
    aTwo = 2 * _a;
    minusB = -1 * _b;
    fu = 0;
    if(delta < 0){
      outFile << "NO" << endl;
      continue;
    }
    if(solve(delta)._under != 1){
      if(minusB == 0){
	if(aTwo<0){
	  aTwo = -1*aTwo;
	  outFile << '-';
	}
	cur = solve(delta);
	curInt = gcd(cur._out,aTwo);
	outFile << cur._out/curInt << '*';
	outFile << "sqrt(" << cur._under << ")";
	if(aTwo != curInt){
	  outFile << '/' << aTwo/curInt;
	}
	outFile << endl;
      
	continue;
      }
      curInt = gcd(aTwo,_b);
      if(aTwo < 0 && minusB > 0 || aTwo > 0 && minusB<0){
	outFile << '-';
      }
      if(minusB < 0){
	minusB = -1 * minusB;
      }
      if(aTwo < 0){
	aTwo = -1 * aTwo;
	fu = 1;
      }
      outFile << minusB/curInt;
      if(aTwo != curInt){
	outFile << '/' << aTwo/curInt;
      }
      if(delta==0){
	outFile << endl;
	continue;
      }
      if(fu == 1){
	outFile << '-';
      }
      else{
	outFile << '+';
      }
      cur = solve(delta);
      curInt = gcd(cur._out,aTwo);
      if(cur._out != curInt)
	outFile << cur._out/curInt << '*';
      outFile << "sqrt(" << cur._under << ")";
      if(aTwo != curInt){
	outFile << '/' << aTwo/curInt;
      }
      outFile << endl;
      
    }else{
      minusB += solve(delta)._out;
      curInt = gcd(aTwo,minusB);
      if(aTwo < 0 && minusB > 0 || aTwo > 0 && minusB<0){
	outFile << '-';
      }
      if(minusB < 0){
	minusB = -1 * minusB;
      }
      if(aTwo < 0){
	aTwo = -1 * aTwo;
	fu = 1;
      }
      outFile << minusB/curInt;
      if(aTwo != curInt){
	outFile << '/'  << aTwo/curInt;
      }
      outFile << endl;
    }
  }
  inFile.close();
  outFile.close();
}

int main(){
  ICO();
  return 0;
}
