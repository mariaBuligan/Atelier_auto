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
        virtual ~Data()=default;
    
     int getZ(){return zi; }
     int getL(){return luna;}
     int getA(){return an; }

     void setZ(int x){ zi=x; }
     void setL(int x){ luna=x;}
     void setA(int x){ an=x; }

    virtual void afisare(){
        cout<<zi<<"."<<luna<<"."<<an;
    }

    friend istream &operator>>(istream &fin, Data &d){
        fin>>d.zi>>d.luna>>d.an;
        return fin;
    }

};
// /Users/mariabuligan/Documents/GitHub/Atelier_auto/angajati.hpp
// /Users/mariabuligan/Desktop/Extra/Atelier_auto/angajati.hpp
class Angajat{
    protected:
      int ID;
      string nume;
      string prenume;
      Data nastere;
      Data angajare;
      float coeficient;
      static int count;
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
            //cout<<"A fara paranteze"<<endl;
            ID=++count;
            nume='-';
            prenume="-";
            coeficient=0;
        }
        Angajat(string n,string p,int nz,int nl,int na,int az,int al, int aa){
            ID=count;
             //cout<<"A cu paranteze"<<endl;
            if(n.size()>30)cout<<"ERROR:Lungimea numelui este prea mare\n";
            else nume=string(n);
            if(p.size()>30)cout<<"ERROR:Lungimea prenumelui este prea mare\n";
            else prenume=string(p);
            if(este_major(na,nl,nz)){
            nastere.setA(na);  nastere.setL(nl);  nastere.setZ(nz); 
            }else cout<<"ERROR nu este major\n";
            angajare.setA(aa); angajare.setL(al); angajare.setZ(az);

        }
        Angajat(const Angajat &v): nastere(v.nastere),angajare(v.angajare){
            ID=++count;
             //cout<<"A copiere"<<endl;
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
        }
        virtual ~Angajat(){
            // cout<<"DESTRUCTOR A"<<endl;
            --count;
        }

        Angajat &operator=(const Angajat&v){
            if(this!= &v){
            ID=v.ID; nastere=v.nastere; angajare=v.angajare;
            nume=v.nume;
            prenume=v.prenume;
            coeficient=v.coeficient;
            }
            return *this;
        }

     virtual void afisare(){
        cout<<ID<<endl;
        cout<<nume <<" "<<prenume<<endl;
        cout<< "Nascut la data de:"; nastere.afisare(); cout<<endl;
        cout<< "Lucreaza de la data de:"; angajare.afisare(); cout<<endl;
     }

     friend istream &operator>>(istream &fin, Angajat &v){
        fin>>v.nume;
        fin>>v.prenume;
        fin>>v.nastere;
        fin>>v.angajare;
        return fin;
     }



};
int Angajat::count = 0;

class Director: virtual public Angajat{
    private:
     float salariu;
    public:
     Director():Angajat(){
         //cout<<"D fara paranteze"<<endl;
         coeficient=2;
     }
     Director(const Angajat &v):Angajat(v){
        //cout<<"D cu paranteze"<<endl;
         count++;
        int vechime=an_vechime();
         coeficient=2;
         salariu=coeficient*1000*(float)vechime;
     }
    ~Director(){
       // cout<<"DESTRUCTOR D"<<endl;
        Angajat::~Angajat();
    }
    Director &operator=(const Director &v){
        if(this!=&v){
        Angajat::operator=(v);
        salariu=v.salariu;
        }
        return *this;
    }
    void afisare(){
        Angajat::afisare();
        cout<<"Pozitie de DIRECTOR. Salariu:"<<salariu<<endl;
    }
    friend istream &operator>>(istream &fin, Director &v){
        fin>>(Angajat&)v;
        return fin;
    }
};

class Mecanic: virtual public Angajat{
    private:
     float salariu;
    public:
     Mecanic():Angajat(){
       // cout<<"M fara paranteze"<<endl;
         coeficient=1.5;
     }
     Mecanic(const  Angajat &v):Angajat(v){
         // cout<<"M cu paranteze"<<endl;
        coeficient=1.5;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Mecanic(){
           // cout<<"DESTRUCTOR M"<<endl;
        Angajat::~Angajat();
    }
    Mecanic &operator=(const Mecanic &v){
        if(this!=&v){
        Angajat::operator=(v);
        salariu=v.salariu;
        }
        return *this;
    }
     void afisare(){
        Angajat::afisare();
        cout<<"Pozitie de MECANIC. Salariu:"<<salariu<<endl;
    }
      friend istream &operator>>(istream &fin, Mecanic &v){
        fin>>(Angajat&)v;
        return fin;
    }
    
};
class Asistent: virtual public Angajat{
     private:
        float salariu;
     public:
     Asistent():Angajat(){
        //cout<<"As fara paranteze"<<endl;
         coeficient=1.0;
     }
     Asistent(const Angajat &v):Angajat(v){
        // cout<<"As cu paranteze"<<endl;
        coeficient=1.0;
        int vechime=an_vechime();
         salariu=coeficient*1000*(float)vechime;
     }
    ~Asistent(){
          //  cout<<"DESTRUCTOR As"<<endl;
        Angajat::~Angajat();
    }
    Asistent &operator=(const Asistent &v){
        if(this!=&v){
        Angajat::operator=(v);
        salariu=v.salariu;
        }
        return *this;
    }
     void afisare(){
        Angajat::afisare();
        cout<<"Pozitie de ASISTENT. Salariu:"<<salariu<<endl;
    }
      friend istream &operator>>(istream &fin, Asistent &v){
        fin>>(Angajat&)v;
        return fin;
    }
    
};


