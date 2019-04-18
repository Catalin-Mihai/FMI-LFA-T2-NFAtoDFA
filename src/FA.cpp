#include "FA.h"

FA::FA()
{

}

FA::~FA()
{
    //cout<<"called destructor FA"<<endl;
}

/*int FA::getStareIndexByLitera(string l)
{
    for(unsigned int i = 0; i < stari.size(); i++)
    {
        if(l.compare(stari[i].litera) == 0) return stari[i].index;
    }
    return -1;
}

FA::simbol FA::getSimbolByLitera(string l)
{
    for(unsigned int j = 0; j < simboluri.size(); j++)
    {
        if(simboluri[j].litera.compare(l) == 0)
        {
            return simboluri[j];
        }
    }
    simbol s;
    s.index = -1;
    s.litera = '\0';
    return s;
}

int FA::getSimbolIndexByLitera(string l)
{
    for(unsigned int j = 0; j < simboluri.size(); j++)
    {
        if(simboluri[j].litera.compare(l) == 0)
        {
            return simboluri[j].index;
        }
    }
    return -1;
}

int FA::getStareInitialaIndex()
{
    return this->stare_initiala.index;
}

bool FA::isStareFinalaIndex(int index)
{
    for(unsigned int i = 0; i < stari_finale.size(); i++)
    {
        if(stari_finale[i].index == index) return true;
    }
    return false;
}

istream &operator>>(istream &input, FA &fa)
{
    unsigned int nr;
    //stari
    input>>nr;
    FA::stare s;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s.litera;
        s.index = i;
        fa.stari.push_back(s);
    }

    //simboluri
    input>>nr;
    FA::simbol s2;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s2.litera;
        s2.index = i;
        fa.simboluri.push_back(s2);
    }

    //stare initiala
    input>>fa.stare_initiala.litera;
    fa.stare_initiala.index = fa.getStareIndexByLitera(fa.stare_initiala.litera);

    //stari finale
    input>>nr;
    FA::stare s3;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s3.litera;
        s3.index = fa.getStareIndexByLitera(s3.litera);
        fa.stari_finale.push_back(s3);
    }

    //tranzitii
    input>>nr;
    FA::tranzitie t;
    string l;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>l;
        t.plecare = fa.getStareIndexByLitera(l);
        input>>l;
        t.destinatie = fa.getStareIndexByLitera(l);
        input>>l;
        t.simb = fa.getSimbolByLitera(l);
        fa.tranzitii.push_back(t);
    }
    fa.CitesteTranzitii();
    return input;
}

void FA::Afiseaza()
{
    cout<<"Nr_stari: "<<this->stari.size()<<endl;
    cout<<"Stari: ";
    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        cout<<"(i:"<<this->stari[i].index<<",l:"<<this->stari[i].litera<<") ";
    }
    cout<<endl;
    cout<<"Nr simboluri: "<<this->simboluri.size()<<endl;
    cout<<"Simboluri: ";
    for(unsigned int i = 0; i < this->simboluri.size(); i++)
    {
        cout<<"(i:"<<this->simboluri[i].index<<",l:"<<this->simboluri[i].litera<<") ";
    }
    cout<<endl;
    cout<<"Starea initiala: (i:"<<this->stare_initiala.index<<",l:"<<this->stare_initiala.litera<<") ";
    cout<<endl;
    cout<<"Nr stari finale: "<<this->stari_finale.size()<<endl;
    cout<<"Starile finale: ";
    for(unsigned int i = 0; i < this->stari_finale.size(); i++)
    {
        cout<<"(i:"<<this->stari_finale[i].index<<",l:"<<this->stari_finale[i].litera<<") ";
    }
    cout<<endl;
    cout<<"Nr tranzitii: "<<this->tranzitii.size()<<endl;
    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        cout<<"(p:"<<this->tranzitii[i].plecare<<",d:"<<this->tranzitii[i].destinatie<<",l:"<<this->tranzitii[i].simb.litera<<",si:"<<this->tranzitii[i].simb.index<<") ";
    }
    cout<<endl;
    this->AfiseazaMatrice();
}*/

