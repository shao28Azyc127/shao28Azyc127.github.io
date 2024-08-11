

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

struct Node {
  int _a;
  int _b;
  int _c;
};

vector<Node> _myList;
vector<string> _resList;
int _num = 0;
int _cc = 0;

ofstream outFile("uqe.out");

void GetResOne(int soloOne, int soloTwo) {

  bool flag = 0;
  string solo;
  string res = "";
  int numOne = soloOne;
  int numTwo = soloTwo;
  
  if(numOne < 0) {
    flag = 1;
    numOne = 0 - numOne;
  }

  //cout << numOne << ' ' << numTwo << endl;

  for(int i = 2; i < min(numOne, numTwo) + 1; i++) {
    if(numOne % i == 0 && numTwo % i == 0) {
      numOne /= i;
      numTwo /= i;
      i--;
    }
  }

  if(flag) {
    outFile << '-';
  }

  outFile << numOne;

  if(numTwo != 1) {
    outFile << '/' << numTwo;
  }

}

void GetResTwo(int soloOne, int soloTwo) {
  long long numOne = soloOne;
  int numTwo = soloTwo;
  int numThree = 1;
  int numFour = 0;
  bool flag = 0;
  string res = "";
  string solo = "";

  if(numOne < 0) {
    flag = 1;
    numOne = 0 - numOne;
  }

  for(int i = 2; i < sqrt(numOne) + 1; i++) {
    //cout << numOne << ' ' << i << endl;
    if(numOne % (i * i) == 0) {
      numOne /= i;
      numOne /= i;
      numThree *= i;
      i--;
    } 
    
  }

  for(int i = 2; i < min(numTwo, numThree) + 1; i++) {
    if(numTwo % i == 0 && numThree % i == 0) {
      numTwo /= i;
      numThree /= i;
      i--;
    }
  }
  
  if(numThree != 1) {
    outFile << numThree << '*';
  }

  outFile << "sqrt(" << numOne << ")";

  if(numTwo != 1) {
    outFile << '/' << numTwo;
  }
  
}

void GetRes(Node solo) {
  
  long long num = 0;
  string res = "";
  string str = "";
  int ccOne = 0;
  int ccTwo = 0;
  int ccThree = 0;
  num = solo._b * solo._b;

  num -= 4 * solo._a * solo._c;

  if(num < 0) {
    outFile << "NO" << endl;
    _resList.push_back(res);
    return;
  }

  if(int(sqrt(num)) * int(sqrt(num)) == num) {
    
    ccTwo = 2 * solo._a;
    if(ccTwo > 0) {
      ccOne = sqrt(num) - solo._b;
    }
    else {
      ccOne = solo._b + sqrt(num);
      ccTwo = 0 - ccTwo;
    }
    GetResOne(ccOne, ccTwo);
    outFile << endl;
    return;
  }
  ccTwo = 2 * solo._a;
  if(ccTwo > 0) {
    ccOne = 0 - solo._b;
    ccThree = num;
  }
  else {
    ccOne = solo._b;
    ccThree = 0 - num;
    ccTwo = 0 - ccTwo;
  }
  if(ccOne != 0) {
    GetResOne(ccOne, ccTwo);
    outFile << '+';
   
  }
  _resList.push_back(res);

  GetResTwo(ccThree, ccTwo);
  outFile << endl;
  
}

void ParseIn() {

  Node solo;
  
  ifstream inFile("uqe.in");

  inFile >> _num >> _cc;

  for(int i = 0; i < _num; i++) {
    inFile >> solo._a >> solo._b >> solo._c;

    _myList.push_back(solo);
  }
  
  inFile.close();
}

void Core() {
  for(int i = 0; i < _num; i++) {
    GetRes(_myList[i]);
  }
}

int main() {
  
  ParseIn();
  Core();

  outFile.close();

  return 0;
}
