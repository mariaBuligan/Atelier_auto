#include <ctime>   
#include <iostream>  
#include <vector>
#include <fstream>
#include "angajati.hpp"
  
using namespace std;  
  
void citire(istream &fin, vector<Angajat> &v){
      if(fin.eof())return;
      else{
            Angajat x;
            cout<<endl;
            string type;
            fin>>type;
            fin>>x;
            if(type=="Director"){
                  Director d(x);
                  v.push_back(d);
            }else if(type=="Mecanic"){
                  Mecanic m(x);
                  v.push_back(m);
            }else{
                  Asistent a(x);
                  v.push_back(a);
            }
            citire(fin,v);
      }
}

int main() {
 
 vector<Angajat> v;

 ifstream fin("date.txt");
  citire(fin,v);
  for(auto it : v) it.afisare();

      return 0;
}