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



void display_queue(queue <Masini*> q){
    if(q.empty())cout<<"-"<<endl;
    else{
        while(!q.empty()){
             cout << '\t' << q.front();
             q.pop();
        }
        cout<<endl;
    }
}

bool employee_not_overworked(queue <Masini*> q,string current_type){
    if(q.empty())return true;
    else if(q.size()>=5)return false;
    else{
        int masini_standard=0,camioane=0,autobuze=0;
        while(!q.empty()){
            if(q.front()->getType() == "Standard")masini_standard++;
            else if(q.front()->getType() == "Autobuz")autobuze++;
            else camioane++;
        }
        cout<<"SUNT IN VERIFICARE:"<<masini_standard<< " "<<camioane<<" "<<autobuze<<endl;
          if((current_type == "Autobuz" && autobuze >0)|| (current_type == "Camion" && camioane >0)) return false;
          else return true;
          if(current_type=="Standard" && masini_standard >=3 )return false;
          else return true;
    }

}

class Employee_Scheduele{
    protected: 
        Angajat* employee;
        queue <Masini*> q;
        float time;       //cel mai scurt timp in care se la elibera un loc liber la acest angajat
    public:
        Employee_Scheduele():time(10),employee(){}
        Employee_Scheduele(Angajat* v):employee(v){}

         bool AddTO_Employee_Scheduele(Masini* v){
            if(employee_not_overworked){
                 q.push(v);


                float vtime;
                if(v->getType() == "Standard")vtime=1.0;
                    else if(v->getType() == "Autobuz")vtime=2.0;
                         else vtime=2.5;

                if(vtime<this->time)this->time=vtime;        
                cout<<"Masina d-voastra va fi reparata de Angajatul "<<employee->getID()<<", in "<<vtime<<" zile."<<endl;
                return true;
            }else{
                cout<<"Angajatul nu este disponibil momentan. Va fi disponibil in:"<<time<<" zile."<<endl;
                return false;
            }
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

       map<Masini*,int> getMap(){return general;}

};

void Adauga_la_angajat(Atelier coada_generala, Employee_Scheduele orare[],int n){
     map<Masini*,int> mapa =coada_generala.getMap();
     bool found_space=false;

     for(auto it=mapa.begin();it!=mapa.end();it++){
        if(it->second ==0){
            for(int i=0;i<n;i++){
                if(orare[i].AddTO_Employee_Scheduele((it)->first)){
                    found_space=true;
                    break;
               }}
            if(found_space==false)cout<<"NU EXISTA NICI UN LOC DISPONIBIL"<<endl;
        }else{
            for(int i=0;i<n;i++){
                if(orare[i].getEmployeeID()==it->second ){
                    if(orare[i].AddTO_Employee_Scheduele((it)->first)) break;
                    else cout<<"ANGAJATUL DORIT NU ESTE DISPONIBIL"<<endl;
                }
            }
        }

     }
}

