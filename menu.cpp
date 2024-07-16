
#include <iostream>  
#include <vector>
#include <typeinfo>
#include "angajati.hpp"
#include "masini.hpp"
#include "atelier.hpp"
#include "optiuni.cpp"
  
using namespace std; 

void display_options(){
    cout<<"1: Inregistreaza un Angajat"<<endl;
    cout<<"2: Deconecteaza un Angajat"<<endl;
    cout<<"3: Editeaza un Angajat"<<endl;
    cout<<"4: Introducere Autoturisme in sistem"<<endl;
    cout<<"5: Afla polita Autoturismului"<<endl;
    cout<<"0: Iesire din Program"<<endl;
}

int  main(){
     int option;
     vector<Angajat*> v;
     Employee_Scheduele *orare;
     Atelier coada_generala;
     
     ifstream fin("date.txt");
     citireMasini(fin,coada_generala);
     display_options();
     cout<<"Introduceti un numar corepsunzator uneia dintre optiunile de mai sus:"; cin>>option;
    
     for(int i=0;i<v.size();i++)orare[i].afisare();
     
    while(option!=0){
        switch(option){
            case 1:
                optiune_1(v);
                break;
            case 2:
                optiune_2(v);
                break;
            case 3:
                optiune_3(v);
                break;
            case 4:
                optiune_4(coada_generala,v,orare);
                break;
            case 5:
                optiune_5(coada_generala);
                break;
            default:
                cout<<"Aceasta optiune nu exista."<<endl;
                break;
        }
        display_options();
        cout<<"Introduceti un numar corepsunzator uneia dintre optiunile de mai sus:"; 
        cin>>option;
    } 
    cout<<"VA MULTUMIM PENTRU VIZITA! VA MAI ASTEPTAM!"<<endl;
    coada_generala.afisare();

    return 0;
}