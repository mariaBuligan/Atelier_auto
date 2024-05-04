#include <ctime>   
#include <iostream>  
#include <vector>
#include <fstream>
#include "angajati.hpp"
  
using namespace std;  
  
void citire(istream &fin, vector<Angajat> &v){
      while(!fin.eof()){
            string type;
            fin>>type;
            Angajat x;
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
      }
}

int main() {
 
 vector<Angajat> v;
 ifstream fin("date.txt");
  citire(fin,v);
  for(auto it : v) it.afisare();

      return 0;
}