#include <ctime>   
#include <iostream>  
#include <vector>
#include "angajati.hpp"
  
using namespace std;  
  
int main() {
 
 vector<Angajat> v;
 char p[]="Maria";
 char n[]="Buligan";
 Angajat a1(n,p,13,5,2003,1,7,2022);
 Director d1(a1);
 Mecanic m(a1);
v.push_back(m);
v.push_back(d1);
for(auto it : v) it.afisare();

      return 0;
}