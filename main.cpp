
#include <iostream>  
#include <vector>
#include <typeinfo>
#include "angajati.hpp"
#include "masini.hpp"
#include "atelier.hpp"
  
using namespace std;  

template <class T>
void afisare_vector(vector<T> &v){
      for(auto it:v) it->afisare();
}

void Setare_Angajati(Employee_Scheduele *orare,vector<Angajat*> ang){
      int i=0;
      for(auto it:ang){
            orare[i]=Employee_Scheduele(it);
            i++;
      }
}

int main() {

 vector<Angajat*> employes;
 vector<Masini*> cars;

 Masini m(123,100000,2009,true);
 Masini m2(88,100000,2009,true);
 Masini m3(1767,100000,2009,true);

 Standard *volvo = new Standard(m,true);
 Autobuz *audi = new Autobuz (m2,12);
 Camion *cam = new Camion(m3,2.5);
 Camion *cam2= new Camion(m2,3);

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

 Atelier coada_generala;
 coada_generala.AddToGeneralQueue(volvo,0);
 coada_generala.AddToGeneralQueue(audi,0);
 coada_generala.AddToGeneralQueue(cam,1); 
  coada_generala.AddToGeneralQueue(cam2,1); 
 coada_generala.afisare();

Employee_Scheduele orare[employes.size()];
Setare_Angajati(orare,employes);
int n=sizeof(orare)/sizeof(orare[0]);
for(int i=0;i<n;i++)orare[i].afisare();

Adauga_la_angajat(coada_generala,orare,employes.size());

      return 0;
}
