#include <iostream>
#include <string.h>
#include <typeinfo>
#include <unordered_map>
#include <vector>
using namespace std;
class partial; class examen_final; class quizz; template <class partial, class examen_final, class quizz> class CatalogIndividual;
class examen
{
    protected:
        int numar;
        string materie;
        string data;
        float nota_scris;

    public:
        examen();
        examen(int, string, string, float);//const de initializare cu un nr dat
        examen(const examen&);//const de copiere
        virtual~examen();//destructor
        examen& operator=(const examen &);
        friend ostream& operator<<(ostream&, examen&);
        friend istream& operator>>(istream&, examen&);
        virtual void citire();
        virtual void afisare();
        friend class CatalogIndividual<partial,examen_final,quizz>;
};

class partial : public examen
{
    protected:
        float nota_oral;
    public:
        partial();
        partial(const partial&);//const de copiere
        partial(int,string,string,float,float);//const de initializare cu un nr dat
        ~partial();//destructor
        partial& operator=(const partial &);
        friend ostream& operator<<(ostream&, partial&);
        friend istream& operator>>(istream&, partial&);
        void citire();
        void afisare();
        friend class CatalogIndividual<partial,examen_final,quizz>;

};

class examen_final : public examen
{
    protected:
        int puncte_proiect;
    public:
        examen_final();
        examen_final(const examen_final&);//const de copiere
        examen_final(int,string,string,float,int);//const de initializare cu un nr dat
        ~examen_final();//destructor
        examen_final& operator=(const examen_final &);
        friend ostream& operator<<(ostream&, examen_final&);
        friend istream& operator>>(istream&, examen_final&);
        void citire();
        void afisare();
        friend class CatalogIndividual<partial,examen_final,quizz>;
};

class quizz : public examen
{
    protected:
        int nr_itemi;
    public:
        quizz();
        quizz(const quizz&);//const de copiere
        quizz(int,string,string,float,int);//const de initializare cu un nr dat
        ~quizz();//destructor
        quizz& operator=(const quizz &);
        friend ostream& operator<<(ostream&, quizz&);
        friend istream& operator>>(istream&, quizz&);
        void citire();
        void afisare();
};

examen :: examen()
{
    numar=0;
    materie="";
    data="";
    nota_scris=5;
}

examen :: examen(int nr, string mat, string dat, float nota)
{
    numar=nr;
    materie=mat;
    data=dat;
    nota_scris=nota;
}

examen :: examen(const examen& ob)
{
    if(materie!="")
        materie=ob.materie;
    else
        materie="";
    if(data!="")
        data=ob.data;
    else
        data="";
    numar=ob.numar;
    nota_scris=ob.nota_scris;
}
examen :: ~examen()
{
    cout<<"Distrugere obiect";
}
examen& examen :: operator=(const examen& ob)
{
    if(this!=&ob)
    {
        numar=ob.numar;
        materie=ob.materie;
        data=ob.data;
        nota_scris=ob.nota_scris;
    }
    return *this;
}

void examen :: citire()
{
    cout<<"Care este id-ul examenului?";
    cin>>numar;
    try
    {
        if(numar<=0)
            throw numar;
    }
    catch(int x){cout<<"introduceti un nr pozitiv: "; cin>>numar;}
    cout<<"Care este materia?";
    cin>>materie;
    cout<<"Care este data examenului?";
    cin>>data;
    cout<<"Care este nota obtinuta la scris?";
    cin>>nota_scris;
        try
    {
        if(nota_scris<1)
            throw nota_scris;
    }
    catch(float x){cout<<"introduceti o nota valida: "; cin>>nota_scris;}
}

void examen :: afisare()
{
    cout<<"Id examen: "<<numar<<endl;
    cout<<"Materie: "<<materie<<endl;
    cout<<"Data examen: "<<data<<endl;
    cout<<"Nota obtinuta la scris: "<<nota_scris;
}

istream& operator>>(istream& in, examen& ob)
{
    cout<<"Care este id-ul examenului?";
    in>>ob.numar;
    cout<<"Care este materia?";
    in>>ob.materie;
    cout<<"Care este data examenului?";
    in>>ob.data;
    cout<<"Care este nota obtinuta la scris?";
    in>>ob.nota_scris;

    return in;
}

ostream& operator<<(ostream& out, examen& ob)
{
    out<<"Id examen: "<<ob.numar<<endl;
    out<<"Materie: "<<ob.materie<<endl;
    out<<"Data examen: "<<ob.data<<endl;
    out<<"Nota obtinuta la scris: "<<ob.nota_scris;

    return out;
}

partial :: partial()
{
    nota_oral=5;
}

partial :: partial(int nr, string mat, string dat, float nota, float notao) : examen(nr,mat,dat,nota)
{
    nota_oral=notao;
}

partial :: partial(const partial& ob)
{
    numar=ob.numar;
    materie=ob.materie;
    data=ob.data;
    nota_scris=ob.nota_scris;
    nota_oral=ob.nota_oral;
}

partial :: ~partial()
{
    cout<<"Distrugere obiect";
}

partial& partial :: operator=(const partial& ob)
{
    if(this!=&ob)
    {
        numar=ob.numar;
        materie=ob.materie;
        data=ob.data;
        nota_scris=ob.nota_scris;
        nota_oral=ob.nota_oral;
    }
    return *this;
}

void partial :: citire()
{
    cout<<"Care este id-ul partialului?";
    cin>>numar;
        try
    {
        if(numar<=0)
            throw numar;
    }
    catch(int x){cout<<"introduceti un nr pozitiv: "; cin>>numar;}
    cout<<"Care este materia la care se sustine partial?";
    cin>>materie;
    cout<<"Care este data partialului?";
    cin>>data;
    cout<<"Care este nota obtinuta la scris?";
    cin>>nota_scris;
        try
    {
        if(nota_scris<1)
            throw nota_scris;
    }
    catch(float x){cout<<"introduceti o nota existenra: "; cin>>nota_scris;}
    cout<<"Care este nota obtinuta la oral?";
    cin>>nota_oral;
                try
    {
        if(nota_oral<1)
            throw nota_oral;
    }
    catch(float x){cout<<"introduceti o nota existenra: "; cin>>nota_oral;}
}

void partial :: afisare()
{
    cout<<"Id partial: "<<numar<<endl;
    cout<<"Materie partial: "<<materie<<endl;
    cout<<"Data partial: "<<data<<endl;
    cout<<"Nota obtinuta la scris: "<<nota_scris<<endl;
    cout<<"Nota obtinuta la oral: "<<nota_oral;
}

istream& operator>>(istream& in, partial& ob)
{
    cout<<"Care este id-ul partialului?";
    in>>ob.numar;
    cout<<"Care este materia la care se sustine partial?";
    in>>ob.materie;
    cout<<"Care este data partialului?";
    in>>ob.data;
    cout<<"Care este nota obtinuta la scris?";
    in>>ob.nota_scris;
    cout<<"Care este nota obtinuta la oral?";
    in>>ob.nota_oral;

    return in;
}

ostream& operator<<(ostream& out, partial& ob)
{
    out<<"Id partial: "<<ob.numar<<endl;
    out<<"Materie paetial: "<<ob.materie<<endl;
    out<<"Data partial: "<<ob.data<<endl;
    out<<"Nota obtinuta la scris: "<<ob.nota_scris;
    out<<"Nota obtinuta la oral: "<<ob.nota_oral;

    return out;
}

examen_final :: examen_final()
{
    puncte_proiect=10;
}

examen_final :: examen_final(int nr, string mat, string data, float nota, int pct) : examen(nr,mat,data,nota)
{
    puncte_proiect=pct;
}

examen_final :: examen_final(const examen_final& ob)
{
    numar=ob.numar;
    materie=ob.materie;
    data=ob.data;
    nota_scris=ob.nota_scris;
    puncte_proiect=ob.puncte_proiect;
}

examen_final :: ~examen_final()
{
    cout<<"Distrugere obiect";
}

examen_final& examen_final :: operator=(const examen_final& ob)
{
    if(this!=&ob)
    {
        numar=ob.numar;
        materie=ob.materie;
        data=ob.data;
        nota_scris=ob.nota_scris;
        puncte_proiect=ob.puncte_proiect;
    }
    return *this;
}

void examen_final :: citire()
{

    cout<<"Care este id-ul examenului final?";
    cin>>numar;
    try
    {
        if(numar<=0)
            throw numar;
    }
    catch(int x){cout<<"introduceti un numar pozitiv: "; cin>>numar;}
    cout<<"Care este materia la care se sustine examenul final?";
    cin>>materie;
    cout<<"Care este data examenului final?";
    cin>>data;
    cout<<"Care este nota obtinuta la scris?";
    cin>>nota_scris;
    try
    {
        if(nota_scris<1)
            throw nota_scris;
    }
    catch(float x){cout<<"introduceti o nota existenra: "; cin>>nota_scris;}
    cout<<"Care este punctajul obtinut la proeict?";
    cin>>puncte_proiect;
    try
    {
        if(puncte_proiect<=0)
            throw puncte_proiect;
    }
    catch(int x){cout<<"introduceti un punctaj valid: "; cin>>puncte_proiect;}
}

void examen_final :: afisare()
{
    cout<<"Id examen_final: "<<numar<<endl;
    cout<<"Materie examen_final: "<<materie<<endl;
    cout<<"Data examen_final: "<<data<<endl;
    cout<<"Nota obtinuta la scris: "<<nota_scris<<endl;
    cout<<"Punctajul obtinut la proeict: "<<puncte_proiect;
}

istream& operator>>(istream& in, examen_final& ob)
{
    cout<<"Care este id-ul examenului final?";
    in>>ob.numar;
    cout<<"Care este materia la care se sustine examenul final?";
    in>>ob.materie;
    cout<<"Care este data examenului final?";
    in>>ob.data;
    cout<<"Care este nota obtinuta la scris?";
    in>>ob.nota_scris;
    cout<<"Care este punctajul obtinut la proiect?";
    in>>ob.puncte_proiect;

    return in;
}

ostream& operator<<(ostream& out, examen_final& ob)
{
    out<<"Id examen final: "<<ob.numar<<endl;
    out<<"Materie examen final: "<<ob.materie<<endl;
    out<<"Data examen final: "<<ob.data<<endl;
    out<<"Nota obtinuta la scris: "<<ob.nota_scris;
    out<<"Punctajul obtinut la proiect: "<<ob.puncte_proiect;

    return out;
}


quizz :: quizz()
{
    nr_itemi=10;
}

quizz :: quizz(int nr, string mat, string dat, float nota, int itemi) : examen(nr,mat,dat,nota)
{
    nr_itemi=itemi;
}

quizz :: quizz(const quizz& ob)
{
    numar=ob.numar;
    materie=ob.materie;
    data=ob.data;
    nota_scris=ob.nota_scris;
    nr_itemi=ob.nr_itemi;
}

quizz :: ~quizz()
{
    cout<<"Distrugere obiect";
}

quizz& quizz :: operator=(const quizz& ob)
{
    if(this!=&ob)
    {
        numar=ob.numar;
        materie=ob.materie;
        data=ob.data;
        nota_scris=ob.nota_scris;
        nr_itemi=ob.nr_itemi;
    }
    return *this;
}

void quizz :: citire()
{
    cout<<"Care este id-ul quizz-ului?";
    cin>>numar;
    try
    {
        if(numar<=0)
            throw numar;
    }
    catch(int x){cout<<"introduceti un numar pozitiv: "; cin>>numar;}
    cout<<"Care este materia la care se sustine quizz?";
    cin>>materie;
    cout<<"Care este data quizz-ului?";
    cin>>data;
    cout<<"Care este nota obtinuta la scris?";
    cin>>nota_scris;
    try
    {
        if(nota_scris<=0)
            throw nota_scris;
    }
    catch(float x){cout<<"introduceti o nota existenra: "; cin>>nota_scris;}
    cout<<"Caati itemi contine quizz-ul?";
    cin>>nr_itemi;
    try
    {
        if(nr_itemi<=0)
            throw nr_itemi;
    }
    catch(int x){cout<<"introduceti un numar valid: "; cin>>nr_itemi;}
}

void quizz :: afisare()
{
    cout<<"Id quizz: "<<numar<<endl;
    cout<<"Materie quizz: "<<materie<<endl;
    cout<<"Data quizz: "<<data<<endl;
    cout<<"Nota obtinuta la scris: "<<nota_scris<<endl;
    cout<<"Numar itemi quizz: "<<nr_itemi;
}

istream& operator>>(istream& in, quizz& ob)
{
    cout<<"Care este id-ul quizz-ului?";
    in>>ob.numar;
    cout<<"Care este materia la care se sustine quizz?";
    in>>ob.materie;
    cout<<"Care este data quizz-ului?";
    in>>ob.data;
    cout<<"Care este nota obtinuta la scris?";
    in>>ob.nota_scris;
    cout<<"Cati itemi contine quizz-ul?";
    in>>ob.nr_itemi;

    return in;
}

ostream& operator<<(ostream& out, quizz& ob)
{
    out<<"Id quizz: "<<ob.numar<<endl;
    out<<"Materie quizz: "<<ob.materie<<endl;
    out<<"Data quizz: "<<ob.data<<endl;
    out<<"Nota obtinuta la scris: "<<ob.nota_scris;
    out<<"Numar itemi quizz: "<<ob.nr_itemi;

    return out;
}

template <class partial, class examen_final, class quizz> class CatalogIndividual
{
    int nr_matricol;
    int nr_examene;
    partial a;
    examen_final b;
    quizz c;
    partial*x; examen_final*y; quizz*z;

    public:
        void citire();
        void afisare();
        friend CatalogIndividual<partial,examen_final,quizz> operator+= (int , CatalogIndividual<partial,examen_final,quizz>&);
        CatalogIndividual<partial,examen_final,quizz>& operator=(CatalogIndividual<partial,examen_final,quizz>& );
        void fct(CatalogIndividual<partial,examen_final,quizz>, unordered_map <int, vector<int> >&);


};
template <class partial, class examen_final, class quizz> CatalogIndividual<partial,examen_final,quizz> operator+=(int i, CatalogIndividual<partial,examen_final,quizz>&v)
{
    v[i].citire();

}

/*template <class partial, class examen_final, class quizz> void CatalogIndividual<partial,examen_final,quizz> :: fct(CatalogIndividual<partial,examen_final,quizz> student, unordered_map <int, vector<int> >&umap)
{
    if(student.b.nota_scris<5)
        umap[student.b.numar]=student.nr_matricol;
}*/
 template <class partial, class examen_final, class quizz> CatalogIndividual<partial,examen_final,quizz>& CatalogIndividual<partial,examen_final,quizz>:: operator=(CatalogIndividual<partial,examen_final,quizz>& ob)
{
    if(this!=ob)
    {   int i;
        nr_matricol=ob.nr_matricol;
        nr_examene=ob.nr_examene;
        a=ob.a;
        b=ob.a;
        c=ob.c;
        x=new partial[nr_examene];
        for(i=0;i<nr_examene;i++)
            x[i]=ob.x[i];
        y=new examen_final[nr_examene];
        for(i=0;i<nr_examene;i++)
            y[i]=ob.y[i];
        z=new quizz[nr_examene];
        for(i=0;i<nr_examene;i++)
            z[i]=ob.z[i];
    }
    return this;
}
template <class partial, class examen_final, class quizz> void CatalogIndividual<partial,examen_final,quizz> :: citire()
{
    cout<<"Introduceti nr matricol: ";
    cin>>nr_matricol;
    cout<<"Introduceti nr de examene :";
    cin>>nr_examene;
    try
    {
        if(nr_examene<=0)
            throw nr_examene;
    }
    catch(int x){cout<<"introduceti un nr pozitiv de examene: "; cin>>nr_examene;}
    x=new partial[nr_examene];
    y=new examen_final[nr_examene];
    z=new quizz[nr_examene];
    int i; string tip;
    for(i=0;i<nr_examene;i++)
    {   cout<<"Examenul: "<<i+1<<endl;
        y[i].citire();
        cout<<"Are examenul "<<i+1<<" partial?";
        cin>>tip;
        if(tip=="da")
            {x[i].citire(); if((x[i].nota_scris+x[i].nota_oral)/2<5){cout<<"Se reia partialul"<<endl; x[i].citire();}}
        cout<<"Are examenul "<<i+1<<" quizz?";
        cin>>tip;
        if(tip=="da")
        {z[i].citire();}
    }
}

template <class partial, class examen_final, class quizz> void CatalogIndividual<partial,examen_final,quizz> :: afisare()
{   int i;
    cout<<"Nr matricol al studentului este: "<<nr_matricol<<endl;
    cout<<"Nr de examene este: "<<nr_examene<<endl<<endl;
    for(i=0;i<nr_examene;i++)
    {
        y[i].afisare();
        if(x[i].materie!="")
            x[i].afisare();
        else
            cout<<endl<<"Nu se sustine partial!"<<endl;
        if(z[i].materie!="")
            z[i].afisare();
        else
            cout<<endl<<"Nu se sustine quizz!"<<endl;
        cout<<endl<<endl;
    }
}

template<class quizz> class nr_quizz
{
    quizz*v;
    int nr_examene;
    int nr_studenti;
    CatalogIndividual<partial,examen_final,quizz>*studenti;
    public:
        void atribuire(quizz*,int, int, CatalogIndividual<partial,examen_final,quizz>*);
        void afisare();

};
template<class quizz> void nr_quizz<quizz> :: atribuire(quizz*a,int b, int c, CatalogIndividual<partial,examen_final,quizz>*d)
{
    int i;
    nr_examene=b; nr_studenti=c;
    for(i=0;i<nr_examene;i++)
        v[i]=a[i];
    for(i=0;i<nr_studenti;i++)
        studenti[i]=d[i];
}
template <class quizz> void nr_quizz<quizz> :: afisare()
{
    int i,nr=0,numar=0,j;
    for(i=0;i<nr_studenti;i++)
    {   nr=0;
        for(j=0;j<nr_examene;j++)
            if(v[j].materie!="")
                nr++;
        if(nr>=2)
            numar++;
    }
    cout<<numar;
}

int main()
{
    CatalogIndividual<partial,examen_final,quizz>*studenti;
    int nr_studenti;
    cout<<"Introduceti nr de studenti: ";
    cin>>nr_studenti;
           try
        {
            if(nr_studenti<=0)
            throw nr_studenti;
        }
        catch(int x){cout<<"Introduceti un nr pozitiv de studenti: "; cin>>nr_studenti; }
    studenti=new CatalogIndividual<partial,examen_final,quizz>[nr_studenti];
    int i;
    for(i=0;i<nr_studenti;i++)
      studenti[i].citire();
    for(i=0;i<nr_studenti;i++)
      studenti[i].afisare();
      vector< CatalogIndividual<partial,examen_final,quizz> > elev;
      for(i=0;i<nr_studenti;i++)
        elev.push_back(studenti[i]);
   /* for(i=0;i<nr_studenti;i++)
        elev[i].afisare();

     unordered_map<int, vector<int> >umap;
     for(int i=0;i<nr_studenti;i++)
        studenti[i].fct(studenti[i],umap);
*/
    return 0;
}
