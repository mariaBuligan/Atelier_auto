  
#include <iostream>  
#include <vector>
#include <typeinfo>
#include "angajati.hpp"
  
using namespace std;  
  
int main() {

 vector<Angajat*> v;
 Angajat a1;
 a1=Angajat("Buligan","Maria",13,5,2003,1,7,2022);
 Angajat a2;
 a2=Angajat("Popescu","Alexia",2,7,1998,1,10,2017);
 Director *d1=new Director(a1);
 Mecanic *m= new Mecanic(a2);
  Mecanic *m2= new Mecanic(a2);

 v.push_back(d1);
 v.push_back(m);
 v.push_back(m2);
 for(auto it : v) {
      it->afisare();
} 
      editare_angajat(1,v);

       for(auto it : v) {
      it->afisare();
} 

      return 0;
}
