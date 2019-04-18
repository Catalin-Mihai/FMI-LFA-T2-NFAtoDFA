#include "MultiStare.h"

MultiStare::MultiStare()
{
    index = 0;
}

MultiStare::MultiStare(int index)
{
    this->index = index;
}

MultiStare::~MultiStare()
{
    //dtor
}

/*void MultiStare::SetLitera(string l)
{
    litera = l;
}*/

/*string MultiStare::GetLitera() const
{
    return litera;
}*/

int MultiStare::Contains(int index)
{
    for(int i = 0; i < stari_index.size(); i++)
    {
        if(stari_index[i] == index) return 1;
    }
    return 0;
}

void MultiStare::Afisare()
{
    /*for(int i = 0; i < stari_index.size(); i++)
    {
        cout<<stari_index[i]<<" ";
    }
    cout<<endl;*/
    for(int i = 0; i < litere.size(); i++)
    {
        cout<<litere[i]<<" ";
    }
}

int MultiStare::GetIndex() const
{
    return index;
}

void MultiStare::SetIndex(int i)
{
    index = i;
}

int MultiStare::GetSize()
{
    return stari_index.size();
}

int MultiStare::IsIndexInMultiStare(int n)
{
    for(int i = 0; i < this->GetSize(); i++)
    {
        if(stari_index[i] == n) return 1;
    }
    return 0;
}

int MultiStare::IsEmpty()
{
    if(this->GetSize() == 0) return 1;
    return 0;
}

void MultiStare::Add(int s, string l)
{
    this->stari_index.push_back(s);
    this->litere.push_back(l);
    for(int i = 0; i < stari_index.size(); i++)
    {
        for(int j = 0; j < stari_index.size(); j++)
        {
            if(stari_index[i] < stari_index[j])
            {
                int aux;
                string aux2(litere[i]);
                aux = stari_index[i];
                stari_index[i] = stari_index[j];
                stari_index[j] = aux;
                litere[i] = litere[j];
                litere[j] = aux2;
            }
        }
    }
    //sort(this->stari_index.begin(), this->stari_index.end());
}
