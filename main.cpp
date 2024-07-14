  
#include <iostream>  
#include <vector>
#include <typeinfo>
#include "angajati.hpp"
#include "masini.hpp"
  
using namespace std;  

template <class T>
void afisare_vector(vector<T> &v){
      for(auto it:v) it->afisare();
}

int main() {

 vector<Angajat*> employes;
 vector<Masini*> cars;

 Masini m(123,100000,2009,true);
 Standard *volvo = new Standard(m,true);
 Autobuz *audi = new Autobuz (m,12);
 Camion *cam = new Camion(m,2.5);

 cars.push_back(volvo);
 cars.push_back(audi);
 cars.push_back(cam);

 Angajat a("Buligan","Maria",13,5,2003,1,7,2022);
 Mecanic *mec = new Mecanic(a);
 employes.push_back(mec);

 afisare_vector(employes);
 afisare_vector(cars);

 for(auto it:cars){
      cout<<it->polita()<<" "<<it->polita_DISCOUNT()<<endl;
 }




/*  adaugare_angajat(v);
 adaugare_angajat(v); */


      return 0;
}
