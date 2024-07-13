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

    virtual void print(){
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
        bool este_major(int na,int nl, int nz){
             time_t now = time(0); 
             tm* ltm = localtime(&now);
             if(ltm->tm_year +1900 - na >18)return true;
             if(ltm->tm_mon +1 > nl)return true;
             if(ltm->tm_mday >= nz)return true;
             return false;
        }
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
            if(n.size()>30)cout<<"ERROR:Lungimea numelui este prea mare\n";
            else nume=n;
            if(p.size()>30)cout<<"ERROR:Lungimea prenumelui este prea mare\n";
            else prenume=p;
            if(este_major(na,nl,nz)){
            nastere.setA(na);  nastere.setL(nl);  nastere.setZ(nz); 
            }else cout<<"ERROR is a minor\n";

            angajare.setA(aa); angajare.setL(al); angajare.setZ(az);
        }
        Angajat(const Angajat &v):nastere(v.nastere),angajare(v.angajare){
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
        }
        ~Angajat(){}

        Angajat &operator=(const Angajat&v){
            if(this!= &v){
            nastere=v.nastere; angajare=v.angajare;
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
            }
            return *this;
        }
    static void printID(void){
        cout<<"ID:"<<ID<<endl;
    }
      void print(){
        Angajat::printID();
        cout<<nume <<" "<<prenume<<endl;
        cout<< "Nascut la data de:"; nastere.print(); cout<<endl;
        cout<< "Lucreaza de la data de:"; angajare.print(); cout<<endl;
     }

};
int Angajat::ID;
class Director: virtual public Angajat{
    private:
     float salariu;
     int Nr_angajat;
    public:
     Director():Angajat(){
         ++ID;
         coeficient=2;
     }
     Director(const Angajat &v):Angajat(v){
        Nr_angajat=++ID;
        int vechime=an_vechime();
         coeficient=2;
         cout<<"idull este:"<<ID<<" "<<coeficient<<" "<<vechime<<endl;
         salariu=coeficient*1000*(float)vechime;
     }
    ~Director(){
           --ID;
        Angajat::~Angajat();
    }
    void afisare(){
        Angajat::print();
        cout<<"Pozitie de DIRECTOR. Salariu:"<<salariu<<endl;
    }
};

class Mecanic: virtual public Angajat{
    private:
     float salariu;
    public:
     Mecanic():Angajat(){
         coeficient=1.5;
     }
     Mecanic(const  Angajat &v):Angajat(v){
        coeficient=1.5;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Mecanic(){
        Angajat::~Angajat();
    }
     void afisare(){
        Angajat::print();
        cout<<"Pozitie de MECANIC. Salariu:"<<salariu<<endl;
    }
    
};
class Asistent: virtual public Angajat{
     private:
        float salariu;
     public:
     Asistent():Angajat(){
         coeficient=1.0;
     }
     Asistent(const Angajat &v):Angajat(v){
        coeficient=1.0;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Asistent(){
        Angajat::~Angajat();
    }
     void afisare(){
        Angajat::print();
        cout<<"Pozitie de ASISTENT. Salariu:"<<salariu<<endl;
    }  
};