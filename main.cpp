  
#include <iostream>  
#include <vector>
#include <typeinfo>
#include "angajati.hpp"
  
using namespace std;  
  
int main() {

 vector<Angajat*> v;
 adaugare_angajat(v);
 adaugare_angajat(v);
 for(auto it : v) {
      it->afisare();
} 
      editare_angajat(1,v);

       for(auto it : v) {
      it->afisare();
} 

      return 0;
}
