#pragma once
#include <iostream>
#include <ctime>
using namespace std;

time_t now = time(0);
tm* lct =localtime(&now);

class Masini{
 protected:
    int ID;
    float km;
    int an;
    bool Diesel;
 public:
    Masini():km(0),an(0){};
    Masini(int id, float k, int a, bool D):ID(id),km(k),an(a),Diesel(D){}
    virtual void afisare(){
        cout<<"Masina cu ID-ul:"<<ID<<endl;
        cout<<km<<" km, vechime, din anul "<<an<<", cu motor de tip:";
        if(Diesel)cout<<"Diesel"<<endl;
        else cout<<"NU Diesel"<<endl;
    }
    friend istream& operator>>(istream &fin, Masini &m){
        fin>>m.ID>>m.km>>m.an;
        string motor;
        fin>>motor;
        if(motor=="Diesel")m.Diesel=true;
        else m.Diesel=false;

        return fin;
    }
    virtual float polita(){return 0;}
    virtual float polita_DISCOUNT(){return 0;}
    virtual string getType(){return "Masina";}
    virtual int getID(){return ID;}
};

class Standard: public Masini{
    private:
      bool Manuala;
    public:
        Standard():Masini(){};
        Standard(int id, float k,int a,bool D,bool M):Masini(id,k,a,D),Manuala(M){}
        Standard(const Masini &m, bool M):Masini(m),Manuala(M){};
        friend istream& operator>>(istream &fin,Standard &v){
            fin>>(Masini&)v;
            string man;
            fin >>man;
            if(man=="Manuala")v.Manuala=true;
            else v.Manuala=false;

            return fin;
        }
        void afisare(){
            Masini::afisare();
            cout<<"Tip de transmisie:";
            if(Manuala)cout<<" Manuala"<<endl;
            else cout<<"Automata"<<endl;
        }
        float polita(){
            int vechime = lct->tm_year +1900 - an;
            float polita = vechime *100.0;
            if(Diesel)polita+=500;
            if(km>=200000)polita+=500;
            return polita;
        }
         float polita_DISCOUNT(){
            return polita()-polita()*0.05;
        }
        string getType(){return "Standard";}
        int getID(){return ID;}
};

class Autobuz: public Masini{
    private:
      int nr_loc;
    public:
       Autobuz():Masini(){};
       Autobuz(int id, float k,int a,bool D,int nr):Masini(id,k,a,D),nr_loc(nr){}
       Autobuz(const Masini &m, int nr):Masini(m),nr_loc(nr){}; 
       friend istream& operator>>(istream &fin,Autobuz &v){
            fin>>(Masini&)v;
            fin>>v.nr_loc;
            return fin;
        }
       void afisare(){
            Masini::afisare();
            cout<<"Numar de locuri:"<<nr_loc<<endl;
        }
        float polita(){
            int vechime = lct->tm_year +1900 - an;
            float polita = vechime *200.0;
            if(Diesel)polita+=1000;
            if(km>=100000 && km<200000)polita+=500;
            if(km>=200000)polita+=1000;
            return polita;
        }
         float polita_DISCOUNT(){
            return polita()-polita()*0.1;
        }
        string getType(){return "Autobuz";}
        int getID(){return ID;}
};

class Camion: public Masini{
    private:
      float tonaj;
    public:
        Camion():Masini(){};
        Camion(int id, float k,int a,bool D,float t):Masini(id,k,a,D),tonaj(t){}
        Camion(const Masini &m, float t):Masini(m),tonaj(t){};
        friend istream& operator>>(istream &fin,Camion &v){
            fin>>(Masini&)v;
            fin>>v.tonaj;
            return fin;
        }
        void afisare(){
            Masini::afisare();
            cout<<"Tonajul:"<<tonaj<<endl;
        }
        float polita(){
            int vechime = lct->tm_year +1900 - an;
            float polita = vechime *300.0;
            if(km>=800000)polita+=700;
            return polita;
        }
        float polita_DISCOUNT(){
            return polita()-polita()*0.15;
        }
        string getType(){return "Camion";}
        int getID(){return ID;}
};