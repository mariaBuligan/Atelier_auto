#include <ctime>   
#include <iostream>  
#include <vector>
#include <fstream>
#include <typeinfo>
#include "angajati.hpp"
  
using namespace std;  
  
void citire(istream &fin, Angajat **v){
      int i=0;
      while(!fin.eof()){
            Angajat x;
            string type;
            fin>>type;
            fin>>x;
            if(type=="Director"){
                  Director d(x);
                  v[i]=new Director(d);
            }else if(type=="Mecanic"){
                  Mecanic m(x);
                 v[i]=new Mecanic(m);
            }else{
                  Asistent a(x);
                 v[i]=new Asistent(a);
            }
      }
}

int main() {

 ifstream fin("date.txt");
 int n=4;
 Angajat **v=new Angajat*[n];
  citire(fin,v);
  for(int i=0;i<n;i++){
      v[i]->afisare();
  }
      return 0;
}