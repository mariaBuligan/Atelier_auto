#include <iostream>  
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include "angajati.hpp"
#include "masini.hpp"
#include "atelier.hpp"

void citireMasini(ifstream &fin,Atelier &coada_generala){
    if(fin.eof())return;
    else{
        string type; int opt;
        fin>>type;
        if(type=="Standard"){
            Standard *new_car= new Standard();
            fin>>*new_car;
            fin>>opt;
            coada_generala.AddToGeneralQueue(new_car,opt);
        }else if(type=="Autobuz"){
            Autobuz *new_car= new Autobuz();
            fin>>*new_car;
            fin>>opt;
            coada_generala.AddToGeneralQueue(new_car,opt);
        }else{
            Camion *new_car= new Camion();
            fin>>*new_car;
            fin>>opt;
            coada_generala.AddToGeneralQueue(new_car,opt);
        }
        citireMasini(fin,coada_generala);
        
    }
}


void optiune_1(vector<Angajat*> &v){
    adaugare_angajat(v);
}
void optiune_2(vector<Angajat*> &v){
     int id_cautat;
     cout<<"Introduceti ID-ul Angajatului pentru deconectare:"; cin>>id_cautat;
     if(stergere_angajat(v,id_cautat))cout<<"Angajatul a fost deconectat cu succes"<<endl;
     else cout<<"Angajatul cu ID-ul:"<<id_cautat<<" nu a fost gasit."<<endl;
}
void optiune_3(vector<Angajat*> &v){
    int id_cautat;
    cout<<"Introduceti ID-ul Angajatului pentru a fi editat:"; cin>>id_cautat;
    if(editare_angajat(id_cautat,v))cout<<"Angajatul a fost editat cu succes"<<endl;
     else cout<<"Angajatul cu ID-ul:"<<id_cautat<<" nu a fost gasit."<<endl;
}
void optiune_4(Atelier &coada_generala, vector <Angajat*> &v, Employee_Scheduele *orare){
    if(v.size()==0){
        cout<<"NE PARE RAU< ATELIERUL ESTE INCHIS!"<<endl;
        return;
    }
    int n=v.size();
    orare = new Employee_Scheduele[n];
    Setare_Angajati(orare,v);
    

    for(int i=0;i<n;i++)orare[i].afisare();

    Adauga_la_angajat(coada_generala, orare, v.size());
    cout<<endl<<endl;
     for(int i=0;i<v.size();i++)orare[i].afisare();

}
void optiune_5(Atelier coada_generala){
    int id_cautat;
    map<Masini*,int> mapa=coada_generala.getMap();
    cout<<"Introduceti ID-ul Autotusimului dorit:"; cin>>id_cautat;
    
    auto it = find_if(mapa.begin(), mapa.end(), [&id_cautat](const std::pair<Masini*, int> it) { 
      return it.first->getID() == id_cautat; // Comparing with the object
     });

   if(it == mapa.end())cout<<"Angajatul cu ID-ul:"<<id_cautat<<" nu a fost gasit."<<endl;
   else {
    char promotie;
    cout<<"Aveti DISCOUNT?(d=da,n=nu): ";cin>>promotie;
    if(promotie=='n') cout<<"Polita Auoturismului cu ID-ul:"<<id_cautat<<" este de"<<it->first->polita();
    else cout<<"Polita Auoturismului cu ID-ul:"<<id_cautat<<" este de"<<it->first->polita_DISCOUNT();

   }
}
