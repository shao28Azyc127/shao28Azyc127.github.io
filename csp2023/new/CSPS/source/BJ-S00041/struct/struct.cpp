

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
  string _type;
  string _name;
};

struct Solo {
  int _cc;
  int _solo;
  string _name;
  string _type;
  int _num;
  vector<Node> _line;
};

int _num = 0;
vector<Solo> _typeList;

ofstream outFile ("struct.out");

Solo GetResOne(Solo solo) {

  int cc = 0;
  int num = -1;
  Solo res = solo;
  
  for(int i = 0; i < solo._num; i++) {

    if(solo._line[i]._type == "byte") {
      cc = max(cc, 1);
      num += 1;
      continue;
    }
    if(solo._line[i]._type == "short") {
      cc = max(cc, 2);
      while(num % 2 != 0) {
	num++;
      }
      num += 2;
      continue;
    }
    if(solo._line[i]._type == "int") {
      cc = max(cc, 4);
      while(num % 4 != 0) {
	num++;
      }
      num += 4;
      continue;
    }
    if(solo._line[i]._type == "long") {
      cc = max(cc, 8);

      while(num % 8 != 0) {
	num++;
      }
      num += 8;
      continue;
    }
    
    for(int m = 0; m < _typeList.size(); m++) {
      //cout << _typeList[m]._name << ' ' << solo._line[i]._type << endl;
      if(_typeList[m]._type == solo._line[i]._type) {

	while(num % _typeList[m]._cc != 0) {
	  num++;
	}
	
	cc = max(cc, _typeList[m]._cc);
	num += _typeList[m]._solo;
	//cout << num << endl;
      }
    }
    
  }

  if(num % cc != 0) {
    num /= cc;
    num++;
    num *= cc;
  }

  outFile << num << ' ' << cc << endl;
  res._solo = num;
  res._cc = cc;
  return res;
}

void ParseIn() {

  int curInt = 0;
  int num = 0;
  string str = "Error";
  Solo solo;
  Node curNode;

  ifstream inFile("struct.in");

  inFile >> _num;

  for(int i = 0; i < _num; i++) {

    inFile >> curInt;

    if(curInt == 1) {
      solo._line.clear();
      inFile >> solo._type >> solo._num;

      for(int m = 0; m < solo._num; m++) {
	inFile >> curNode._type >> curNode._name;
	solo._line.push_back(curNode);
      }
      solo = GetResOne(solo);
      _typeList.push_back(solo);
      solo._line.clear();
      continue;
    }

    if(curInt == 2) {
      inFile >> str >> solo._name;
      outFile << num << endl;

      if(str == "byte") {
	num++;
      }
      if(str == "short") {
	while(num % 2 != 0) {
	  num++;
	}
	num += 2;
      }
      if(str == "int") {
	while(num % 4 != 0) {
	  num++;
	}
	num += 4;
      }
      if(str == "long") {
	while(num % 8 != 0) {
	  num++;
	}
	num += 8;
      }

      for(int m = 0; m < _typeList.size(); m++) {
	if(_typeList[m]._type == str) {
	  while(num % _typeList[m]._cc != 0) {
	    num++;
	  
	  }
	  num += _typeList[m]._num;
	}
      
      }
    }
    
  }
  
  inFile.close();
}

int main() {

  ParseIn();

  outFile.close();
  return 0;
}
