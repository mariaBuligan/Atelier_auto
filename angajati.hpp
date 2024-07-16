#pragma once
#include <iostream>
#include <ctime>   
using namespace std;

class Data{
    private:
        int zi;
        int luna;
        int an;
    public:
        Data():zi(0),luna(0),an(0){}
        Data(int z, int l,int a):zi(z),luna(l),an(a){}
        friend bool operator>(const Data &d1,const Data &d2){
            if(d1.an>=d2.an)return true;
            if(d1.luna>=d2.luna)return true;
            if(d1.zi>=d2.zi)return true;
            return false;
        }
        friend bool operator==(const Data &d1,const Data &d2){
            if(d1.an==d2.an && d1.luna==d2.luna && d1.zi==d2.zi)
            return true;

            return false;
        }
    
     int getZ(){return zi; }
     int getL(){return luna;}
     int getA(){return an; }

     void setZ(int x){ zi=x; }
     void setL(int x){ luna=x;}
     void setA(int x){ an=x; }

     void print(){
        cout<<zi<<"."<<luna<<"."<<an;
    }
    
};
class Angajat{
    protected:
      static int ID;
      string nume;
      string prenume;
      Data nastere;
      Data angajare;
      float coeficient;
    public:
        int an_vechime(){
             time_t now = time(0); 
             tm* ltm = localtime(&now);
            return ltm->tm_year +1900 - angajare.getA();
        }

        Angajat(){
            nume='-';
            prenume="-";
            coeficient=0;
        }
        Angajat(string n,string p,int nz,int nl,int na,int az,int al, int aa){
             nume=n;
             prenume=p;
            nastere.setA(na);  nastere.setL(nl);  nastere.setZ(nz); 
            angajare.setA(aa); angajare.setL(al); angajare.setZ(az);
        }
        Angajat(const Angajat &v):nastere(v.nastere),angajare(v.angajare){
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
        }
        virtual ~Angajat(){}

        Angajat &operator=(const Angajat&v){
            if(this!= &v){
            nastere=v.nastere; angajare=v.angajare;
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
            }
            return *this;
        }
      virtual void afisare(){
        cout<<nume <<" "<<prenume<<endl;
        cout<< "Nascut la data de:"; nastere.print(); cout<<endl;
        cout<< "Lucreaza de la data de:"; angajare.print(); cout<<endl;
     }
      virtual int getID(){ return 0;}
      void set_nume(string n,string p){
            nume=n;prenume=p;
      }
      void set_nastere(int nz,int nl,int na){
         nastere.setZ(nz);
         nastere.setL(nl);
         nastere.setA(na);
      }
      void set_angajare(int nz,int nl,int na){
         angajare.setZ(nz);
         angajare.setL(nl);
         angajare.setA(na);
      }

};
int Angajat::ID;
class Director: virtual public Angajat{
    private:
     float salariu;
     int Nr_angajat;
    public:
     Director():Angajat(){
         Nr_angajat=++ID;
         coeficient=2;
     }
     Director(const Angajat &v):Angajat(v){
        Nr_angajat=++ID;
        int vechime=an_vechime();
         coeficient=2;
         //cout<<"idull este:"<<ID<<" "<<coeficient<<" "<<vechime<<endl;
         salariu=coeficient*1000*(float)vechime;
     }
    ~Director(){
           --ID;
        Angajat::~Angajat();
    }
    void afisare(){
        cout<<"ID:"<<Nr_angajat<<endl;
        Angajat::afisare();
        cout<<"Pozitie de DIRECTOR. Salariu:"<<salariu<<endl;
    }
   int getID(){return Nr_angajat;}
};

class Mecanic: virtual public Angajat{
    private:
     float salariu;
     int Nr_angajat;
    public:
     Mecanic():Angajat(){
        Nr_angajat=++ID;
         coeficient=1.5;
     }
     Mecanic(const  Angajat &v):Angajat(v){
        Nr_angajat=++ID;
        coeficient=1.5;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Mecanic(){
        Angajat::~Angajat();
        --ID;
    }
     void afisare(){
        cout<<"ID:"<<Nr_angajat<<endl;
        Angajat::afisare();
        cout<<"Pozitie de MECANIC. Salariu:"<<salariu<<endl;
    }
      int getID(){return Nr_angajat;}
};
class Asistent: virtual public Angajat{
     private:
        float salariu;
        int Nr_angajat;
     public:
     Asistent():Angajat(){
        Nr_angajat=++ID;
         coeficient=1.0;
     }
     Asistent(const Angajat &v):Angajat(v){
        Nr_angajat=++ID;
        coeficient=1.0;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Asistent(){
        Angajat::~Angajat();
        --ID;
    }
     void afisare(){
        cout<<"ID:"<<Nr_angajat<<endl;
        Angajat::afisare();
        cout<<"Pozitie de ASISTENT. Salariu:"<<salariu<<endl;
    }  
     int getID(){return Nr_angajat;}
};

bool este_major(int nz,int nl, int na){
             time_t now = time(0); 
             tm* ltm = localtime(&now);
             int age = ltm->tm_year + 1900 - na;
    return (age > 18) || (age == 18 && (ltm->tm_mon + 1 > nl || (ltm->tm_mon + 1 == nl && ltm->tm_mday >= nz)));
}
bool este_in_viitor(int z,int l,int a){
             time_t now = time(0); 
             tm* ltm = localtime(&now);
             if (a > ltm->tm_year + 1900) return true;  
             if (a == ltm->tm_year + 1900 && l > ltm->tm_mon + 1) return true;
             if (a == ltm->tm_year + 1900 && l == ltm->tm_mon + 1 && z > ltm->tm_mday) return true;
             return false;
}

void stergere_angajat(int Id, vector <Angajat*> &v){
    for(int i=0;i<v.size();i++){
        if(v[i]->getID()==Id){ 
            v.erase(v.begin()+i);
            break;
        }
   } 
}

bool editare_angajat(int Id, vector <Angajat*> &v){
    string n,p;
    cout<<"Introduceti noul nume:"; cin>>n;
    cout<<"Introduceti noul prenume:"; cin>>p;
     for(int i=0;i<v.size();i++){
       if(v[i]->getID()==Id){ 
            v[i]->set_nume(n,p);
             return true;
       }
     }
     return false;
}


void adaugare_angajat(vector <Angajat*> &v){
    string n,p;
    char tip;
    int nz,nl,na,az,al,aa;

    cout<<"Introduceti numele:"; cin>>n;
    while(n.size()>30){
        cout<<"ERROR:Lungimea numelui este prea mare\n";
        cin>>n;
     }

    cout<<"Introduceti prenumele:"; cin>>p;
     while(p.size()>30){
        cout<<"ERROR:Lungimea prenumelui este prea mare\n";
        cin>>p;
     }
     cout<<"Introduceti data de nastere(zz ll aaa):"; cin>>nz>>nl>>na;
     cout<<nz<<" "<<nl<<" "<<na<<endl;
     if(este_major(nz,nl,na)==false){
        cout<<"NU angajam minori. Angajatul nu a fost creat."<<endl;
        return;
     }
     cout<<"Introduceti data angajarii(zz ll aaa):"; cin>>az>>al>>aa;
          cout<<az<<" "<<al<<" "<<aa<<endl;
     while(este_in_viitor(az,al,aa)){
        cout<<"Data gresita. Introduceti din nou(zz ll aaaa):"<<endl;
        cin>>az>>al>>aa;
     }
     cout<<"Introduceti tipul de angajat(d=Direcor, m= Mecanic, a=Asistent):";cin>>tip;
     while(tip!='d' && tip!='m' && tip!='a'){
        cout<<"Eroare la introducerea datelor. Introduceti una dintre urmatoarele optiuni 'd'=Director, 'm'= Mecanic, 'a'=Asistent.";
        cin>>tip;
     }

     Angajat a(n,p,nz,nl,na,az,al,aa);
     if(tip=='d'){
        Director *d = new Director(a);
        v.push_back(d);
     }else if(tip=='m'){
        Mecanic *m = new Mecanic(a);
        v.push_back(m);
     }else{
        Asistent *as= new Asistent(a);
        v.push_back(as);
     }

     cout<<"ANGAJAT CREEAT CU SUCCES!"<<endl;
};

bool stergere_angajat(vector <Angajat*> &v,int id){
         for(int i=0;i<v.size();i++){
            if(v[i]->getID()== id){ 
                auto it=v.begin()+i;
                v.erase(it);
                return true;
            }}
    return false;
}
