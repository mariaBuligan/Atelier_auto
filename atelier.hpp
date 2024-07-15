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
    if(q.empty())cout<<"-";
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
          if((current_type == "Autobuz" && autobuze >0)|| (current_type == "Camion" && camioane >0)) return false;
          else return true;
          if(current_type=="Standard" && masini_standard >=3 )return false;
          else return true;
    }

}

class Employee_Scheduele{
    protected: 
        Angajat employee;
        queue <Masini*> q;
        float time;
    public:
        Employee_Scheduele():time(10),employee(){ }
        Employee_Scheduele(int id,Masini* &v){
           float vtime;
            string vtype = typeid(v).name();
            if(vtype.substr(1) == "Standard")vtime=1.0;
            else if(vtype.substr(1) == "Autobuz")vtime=2.0;
            else vtime=2.5;

            if(vtime<time)time=vtime;
            
            q.push(v);
        }
        void afisare(){
            cout<<"Angajatul  cu Id-ul :"<<employee.getID()<<"are de reparat urmatoarele Masini:"<<endl;
            display_queue(q);
        }


};

class Atelier{
    protected:
       map<Masini*,int> general;
    public:

};

