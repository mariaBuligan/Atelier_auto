  
#include <iostream>  
#include <vector>
#include "angajati.hpp"
  
using namespace std;  
  
int main() {

 vector<Angajat> v;
 Angajat a1;
 a1=Angajat("Buligan","Maria",13,5,2003,1,7,2022);
 Angajat a2;
 a2=Angajat("Popescu","Alexia",2,7,1998,1,10,2017);
 Director d1(a1),d2(a2);
 d1.afisare();
 d2.afisare();
 
 v.push_back(d1);

/* for(auto it : v) {
      it.afisare();
} */

      return 0;
}