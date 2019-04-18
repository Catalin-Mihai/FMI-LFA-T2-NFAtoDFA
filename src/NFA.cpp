#include "NFA.h"

NFA::NFA()
{

}

NFA::~NFA()
{
    //cout<<"called destrucor NFA"<<endl;
}

int NFA::GetMultiStariNumber() const
{
    return multistari.size();
}

void NFA::AddMultiStare(MultiStare multiStare)
{
    multistari.push_back(multiStare);
}

int NFA::GetMultiStareIndexByLitera(string litera) const
{
    for(int i = 0; i < this->GetMultiStariNumber(); i++)
    {
        //Iteram prin toate literele sa vedem daca exista macar una
        for(unsigned int j = 0; j < this->multistari[i].litere.size(); j++)
        {
            if((this->multistari[i].litere[j]).compare(litera) == 0)
            {
                return (this->multistari[i]).GetIndex();
            }
        }
    }
    return -1;
}

NFA::simbol NFA::getSimbolByLitera(string l)
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

int NFA::getStareIndexByLitera(string l)
{
    for(unsigned int i = 0; i < stari.size(); i++)
    {
        if(l.compare(stari[i].litera) == 0) return stari[i].index;
    }
    return -1;
}

void NFA::CitesteTranzitii()
{
    tabel.resize(this->stari.size());
    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        tabel[i].resize(this->simboluri.size());
    }

    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        for(unsigned int j = 0; j < this->simboluri.size(); j++)
        {
            tabel[i][j] = -1;
        }
    }

    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        tabel[i].resize(this->simboluri.size());
    }

    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        tabel[tranzitii[i].plecare][tranzitii[i].simb.index] = tranzitii[i].destinatie;
    }
}

istream &operator>>(istream &input, NFA &nfa)
{
    unsigned int nr;
    //stari
    input>>nr;
    string litera;
    FA::stare s;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s.litera;
        s.index = i;
        nfa.stari.push_back(s);
    }

    //simboluri
    input>>nr;
    FA::simbol s2;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s2.litera;
        s2.index = i;
        nfa.simboluri.push_back(s2);
    }

    //stare initiala
    input>>litera;
    nfa.stare_initiala = nfa.getStareIndexByLitera(litera);

    //stari finale
    input>>nr;
    FA::stare s3;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>s3.litera;
        s3.index = nfa.getStareIndexByLitera(s3.litera);
        nfa.stari_finale.push_back(s3.index);
    }

    //tranzitii
    input>>nr;
    FA::tranzitie t;
    string l;
    for(unsigned int i = 0; i < nr; i++)
    {
        input>>l;
        t.plecare = nfa.getStareIndexByLitera(l);
        input>>l;
        t.destinatie = nfa.getStareIndexByLitera(l);
        input>>l;
        t.simb = nfa.getSimbolByLitera(l);
        nfa.tranzitii.push_back(t);
    }
    nfa.CitesteTranzitii();
    return input;
}

void NFA::Afiseaza()
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
    cout<<"Starea initiala: (i:"<<this->stare_initiala<<",l:"<<this->stari[stare_initiala].litera<<") ";
    cout<<endl;
    cout<<"Nr stari finale: "<<this->stari_finale.size()<<endl;
    cout<<"Starile finale: ";
    for(unsigned int i = 0; i < this->stari_finale.size(); i++)
    {
        cout<<"(i:"<<this->stari_finale[i]<<",l:"<<this->stari[stari_finale[i]].litera<<") ";
    }
    cout<<endl;
    cout<<"Nr tranzitii: "<<this->tranzitii.size()<<endl;
    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        cout<<"(p:"<<this->tranzitii[i].plecare<<",d:"<<this->tranzitii[i].destinatie<<",l:"<<this->tranzitii[i].simb.litera<<",si:"<<this->tranzitii[i].simb.index<<") ";
    }
    cout<<endl;
    //this->AfiseazaMatrice();
}

DFA2 NFA::ConvertToDFA2()
{
    DFA2 dfa;

    //Copiere simboluri din NFA
    for(unsigned int i = 0; i < simboluri.size(); i++)
    {
        dfa.simboluri.push_back(simboluri[i]);
    }

    //Adaugam starea initiala din NFA in DFA ca multistare cu o singura stare;

    MultiStare ms;
    ms.SetIndex(0);
    ms.Add(stare_initiala, stari[stare_initiala].litera);
    dfa.AddMultiStare(ms);

    //Se proceseaza fiecare multistare cu simbolurile aferente
    //Pe parcurs se vor adauga mai multe multistari la procesa
    //Tabelul este construit in tot acest timp.
    for(int multi_id = 0; multi_id < dfa.GetMultiStariNumber(); multi_id++)//fiecare multistare
    {
        //Prima componenta din vectorul linie tine minte multistarea de la care se pleaca
        vector<int> v;
        v.push_back(multi_id);

        for(unsigned int simbol = 0; simbol < dfa.simboluri.size(); simbol++)//Pentru fiecare simbol
        {
            //Creare multistare goala
            MultiStare ms;
            ms.SetIndex(dfa.GetMultiStariNumber());

            for(int element_multi = 0; element_multi < dfa.multistari[multi_id].GetSize(); element_multi++) //Pentru fiecare element din multistarea de plecare
            {
                int stare = dfa.multistari[multi_id].stari_index[element_multi];

                //Se parcurg toate tranzitiile pentru a se vedea daca exista vreuna cu plecarea din multi_id
                for(unsigned int s = 0; s < tranzitii.size(); s++)//fiecare tranzitie
                {
                    //multi_id == plecare si simbol tranzitie == simbol cautat
                    if(tranzitii[s].plecare == stare && tranzitii[s].simb.index == int(simbol))
                    {
                        //Fara duplicate
                        if(!ms.IsIndexInMultiStare(tranzitii[s].destinatie))
                        {
                            //Adaugam in multistare, starea gasita cu simbolul 'simbol' si multistarea de plecare multi_id
                            ms.Add(tranzitii[s].destinatie, stari[tranzitii[s].destinatie].litera);
                        }
                    }
                }
            }
            if(!ms.IsEmpty()) //Nu s-a gasit nicio tranzitie buna -> multistare goala
            {
                if(dfa.DoesMultiStareExists(ms)) //Daca multistarea generata este egala cu una deja existenta, punem in vector pe cea exsitenta
                {
                    v.push_back(dfa.GetMultiStareIndexLike(ms));
                }
                else
                {
                    dfa.AddMultiStare(ms); //Daca nu exista, o punem pe cea generata
                    v.push_back(ms.GetIndex());
                    for(unsigned int h = 0; h < stari_finale.size(); h++)
                    {
                        if(ms.Contains(stari_finale[h])) //Daca multistarea generata contine cel putin o stare finala din NFA, o adaugam la multistari finale
                        {
                            dfa.multistari_finale_index.push_back(ms.GetIndex());
                        }
                    }
                }
            }
            else v.push_back(-1); //inseamna multistare nula
        }
        dfa.tabel.push_back(v);//Actualizam tabelul cu o noua linie formata din plecare si multistarile generate cu simbolurile aferente
        v.clear();
    }
    return dfa; //returnam noul DFA
}
