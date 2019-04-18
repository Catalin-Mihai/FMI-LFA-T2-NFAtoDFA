#include "DFA.h"

DFA::DFA()
{
    this->matrice = NULL;
}

DFA::~DFA()
{
    cout<<"called destructor DFA"<<endl;
}
    /*if(this->matrice != NULL)
    {
        for(unsigned int i = 0; i < this->stari.size(); i++)
        {
            delete[] matrice[i];
        }
        delete[] matrice;
    }
}

int **&DFA::getMatrice()
{
    return matrice;
}

void DFA::CitesteTranzitii()
{
    //Construire matrice
    this->matrice = new int*[this->stari.size()];
    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        this->matrice[i] = new int[this->simboluri.size()];
    }

    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        for(unsigned int j = 0; j < this->simboluri.size(); j++)
        {
            this->matrice[i][j] = -1;
        }
    }

    //Initializare cu tranzitii
    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        this->matrice[this->tranzitii[i].plecare][this->tranzitii[i].simb.index] = this->tranzitii[i].destinatie;
    }
}


void DFA::AfiseazaMatrice()
{
    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        for(unsigned int j = 0; j < this->simboluri.size(); j++)
        {
            cout<<this->matrice[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool DFA::CheckWord(string word)
{
    if(word.compare("L") == 0) //Lambda
    {
        if(this->isStareFinalaIndex(this->getStareInitialaIndex())) return true;
        else return false;
    }
    int stare = this->getStareInitialaIndex();
    int **matrice = this->getMatrice();
    for(unsigned int i = 0; i < word.length(); i++)
    {
        string s(1, word[i]);
        int simbIndex = this->getSimbolIndexByLitera(s);
        if(simbIndex == -1) return false;
        stare = matrice[stare][simbIndex];
        if(stare == -1) return false;
    }
    if(this->isStareFinalaIndex(stare)) return true;
    else return false;
}*/
