#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <typeinfo>
#include "masini.hpp"
#include "angajati.hpp"

using namespace std;


void display_queue(queue <Masini*> q){
    if(q.empty())cout<<"-"<<endl;
    else{
        while(!q.empty()){
             cout<<q.front()->getID()<<" ";
             q.pop();
        }
        cout<<endl;
    }
}

bool employee_not_overworked(queue <Masini*> q,string current_type){
    int masini_standard = 0, camioane = 0, autobuze = 0;
    while (!q.empty()) {
        if (q.front()->getType() == "Standard") masini_standard++;
        else if (q.front()->getType() == "Autobuz") autobuze++;
        else camioane++;
        q.pop();
    }
    if ((current_type == "Autobuz" && autobuze > 0) || (current_type == "Camion" && camioane > 0)) return false;
    if (current_type == "Standard" && masini_standard >= 3) return false;
    return true;
}


class Employee_Scheduele{
    protected: 
        Angajat* employee;
        queue <Masini*> q;
        float time;       //cel mai scurt timp in care se la elibera un loc liber la acest angajat
    public:
        Employee_Scheduele():time(10),employee(){}
        Employee_Scheduele(Angajat* v):employee(v){}

         bool AddTO_Employee_Scheduele(Masini* const v){
            if(employee_not_overworked(q,v->getType())== true){
                float vtime;

                 q.push(v);
                 //display_queue(q);

                if(v->getType() == "Standard")vtime=1.0;
                    else if(v->getType() == "Autobuz")vtime=2.0;
                         else vtime=2.5;
                if(vtime < this->time)this->time=vtime;      

                cout<<"Masina "<<v->getID()<<" va fi reparata de Angajatul "<<employee->getID()<<", in "<<vtime<<" zile."<<endl;
                return true;
            }
                return false;
            
        }

        void afisare(){
            cout<<"Angajatul  cu Id-ul :"<<employee->getID()<<" are de reparat urmatoarele Masini:"<<endl;
            display_queue(q);
        }
        int getEmployeeID(){return employee->getID();}
};

class Atelier{
    protected:
       map<Masini*,int> general;
    public:
       Atelier(){};

       void AddToGeneralQueue(Masini* v,int val){
            general.insert(pair<Masini*,int>(v,val));
            cout<<"Masina d-voastra a fost introdusa in coada de asteptare."<<endl;
       }

       void afisare(){
            cout<<"In asteptare se afla masinile:"<<endl;
            for(auto it=general.begin();it!=general.end();it++){
                cout<<"Autoturismul: "<<it->first->getID()<<" ,pentru angajatul:";
                if(it->second == 0)cout<<" fara preferinte"<<endl;
                else cout<< it->second<<endl;
            }
       }

       map<Masini*,int> &getMap(){return general;}

};

void Adauga_la_angajat(Atelier &coada_generala, Employee_Scheduele orare[],int n){
     map<Masini*,int> &mapa =coada_generala.getMap();
     
     for(auto it=mapa.begin();it!=mapa.end();){
        bool found_space=false;
        if(it->second == 0){
            for(int i=0;i<n;i++){
                if(orare[i].AddTO_Employee_Scheduele((it)->first)==true){
                    it=mapa.erase(it);
                    found_space=true;
                    break;
               }}
            if(found_space==false){
                cout<<"NU EXISTA NICI UN LOC DISPONIBIL"<<endl;
                 char rasp;
                cout<<"Masina "<<it->first->getID()<<" nu poate fi reparata momentan.Doriti sa parasiti atelierul sau sa asteptati?(d=da,n=nu):";
                cin>>rasp;
                if(rasp=='d'){
                     it=mapa.erase(it);
                }
                else{
                    it++;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(orare[i].getEmployeeID()==it->second ){
                    if(orare[i].AddTO_Employee_Scheduele((it)->first) == true){
                        it=mapa.erase(it);
                        break;
                    } 
                    else {
                        cout<<"ANGAJATUL DORIT NU ESTE DISPONIBIL"<<endl;
                         char rasp;
                         cout<<"Masina "<<it->first->getID()<<" nu poate fi reparata momentan.Doriti sa parasiti atelierul sau sa se ocupe un alt angajat?(d=da,n=nu):";
                        cin>>rasp;
                        if(rasp=='d'){
                           it=mapa.erase(it);
                        }else{
                            Masini *aux=it->first;
                            it=mapa.erase(it);
                            mapa.insert(pair<Masini*,int>(aux,0));
                        }
                }}
        }}
     }
};

void Setare_Angajati(Employee_Scheduele *orare,vector<Angajat*> ang){
      int i=0;
      for(auto it:ang){
            orare[i]=Employee_Scheduele(it);
            i++;
      }
};

