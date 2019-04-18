#include "DFA2.h"

DFA2::DFA2()
{

}

DFA2::~DFA2()
{

}

int DFA2::DoesMultiStareExists(MultiStare ms)
{
    int s = 0;
    for(int i = 0; i < GetMultiStariNumber(); i++)
    {
        if(ms.GetSize() == multistari[i].GetSize())
        {
            s = 1;
            for(int j = 0; j < ms.GetSize(); j++)
            {
                if(ms.stari_index[j] != multistari[i].stari_index[j]) s = 0;
            }
            if(s == 1) return 1;
        }
    }
    return 0;
}

int DFA2::GetMultiStareIndexLike(MultiStare ms)
{
    int s = 0;
    for(int i = 0; i < GetMultiStariNumber(); i++)
    {
        if(ms.GetSize() == multistari[i].GetSize())
        {
            s = 1;
            for(int j = 0; j < ms.GetSize(); j++)
            {
                if(ms.stari_index[j] != multistari[i].stari_index[j]) s = 0;
            }
            if(s == 1) return multistari[i].index;
        }
    }
    return -1;
}

void DFA2::Afisare()
{
    cout<<"Nr_stari: "<<this->GetMultiStariNumber()<<endl;
    cout<<"Stari: ";
    for(int i = 0; i < this->GetMultiStariNumber(); i++)
    {
        cout<<"(i:"<<this->multistari[i].index<<"): ";
        for(unsigned int j = 0; j < this->multistari[i].stari_index.size(); j++)
        {
            //int ms = multistari[i];
            cout<<"(i:"<<multistari[i].stari_index[j]<<" ,l:"<<multistari[i].litere[j]<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Nr simboluri: "<<this->simboluri.size()<<endl;
    cout<<"Simboluri: ";
    for(unsigned int i = 0; i < this->simboluri.size(); i++)
    {
        cout<<"(i:"<<this->simboluri[i].index<<",l:"<<this->simboluri[i].litera<<") ";
    }
    cout<<endl;
    cout<<"Multistarea initiala: (i:"<<this->multistari[multistare_initiala_index].index<<"): ";
    for(unsigned int i = 0; i < this->multistari[multistare_initiala_index].stari_index.size(); i++)
    {
        cout<<"(i:"<<this->multistari[multistare_initiala_index].stari_index[i]<<" ,l:"<<this->multistari[multistare_initiala_index].litere[i]<<") ";
    }
    cout<<endl<<endl;
    cout<<"Nr stari finale: "<<this->multistari_finale_index.size()<<endl;
    cout<<"Starile finale: ";
    for(unsigned int i = 0; i < this->multistari_finale_index.size(); i++)
    {
        cout<<"(i:"<<this->multistari[multistari_finale_index[i]].index<<"): ";
        for(unsigned int j = 0; j < this->multistari[multistari_finale_index[i]].stari_index.size(); j++)
        {
            //int ms = multistari[i];
            cout<<"(i:"<<multistari[multistari_finale_index[i]].stari_index[j]<<" ,l:"<<multistari[multistari_finale_index[i]].litere[j]<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Nr tranzitii: "<<this->tranzitii.size()<<endl;
    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        cout<<"(p:"<<this->tranzitii[i].plecare<<",d:"<<this->tranzitii[i].destinatie<<",l:"<<this->tranzitii[i].simb.litera<<",si:"<<this->tranzitii[i].simb.index<<") ";
    }
    cout<<endl;
    this->AfiseazaMatrice();
}

void DFA2::AfiseazaMatrice()
{
    for(int i = 0; i < this->GetMultiStariNumber(); i++)
    {
        for(unsigned j = 0; j < this->simboluri.size()+1; j++)
        {
            //cout<<this->tabel[i][j]<<" | ";
            if(tabel[i][j] != -1)
            {
                for(unsigned int k = 0; k < multistari[tabel[i][j]].stari_index.size(); k++)
                {
                    cout<<multistari[tabel[i][j]].litere[k]<<" ";
                }
            }
            else cout<<"$ ";
            cout<<"| ";
        }
        cout<<endl<<endl;
    }

    cout<<endl<<endl<<"SAU: "<<endl<<endl;
    for(int i = 0; i < this->GetMultiStariNumber(); i++)
    {
        for(unsigned j = 1; j < this->simboluri.size()+1; j++)
        {
            multistari[tabel[i][0]].Afisare();
            cout<<"  ->  (";
            cout<<simboluri[j-1].litera<<")  ->   ";
            if(tabel[i][j]!=-1)
            {
                multistari[tabel[i][j]].Afisare();
            }
            else cout<<"$";
            cout<<endl;
            //cout<<this->tabel[i][j]<<" | ";
        }
        cout<<endl<<endl;
    }
}

int DFA2::GetMultiStariNumber()
{
    return multistari.size();
}

void DFA2::AddMultiStare(MultiStare multiStare)
{
    multistari.push_back(multiStare);
}

void DFA2::InsertNewTabelEntry(int multistare_plecare_index, int simbol_index, int multistare_noua_index)
{
    tabel[multistare_plecare_index][simbol_index] = multistare_noua_index;
}

vector< vector<int> > DFA2::GetTabel()
{
    return this->tabel;
}
