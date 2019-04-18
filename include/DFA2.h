#ifndef DFA2_H
#define DFA2_H

#include "MultiStare.h"

class DFA2: public FA
{
    public:
        DFA2();
        ~DFA2();
        vector< vector<int> > tabel;
        int multistare_initiala_index;
        vector<simbol> simboluri;
        vector<MultiStare> multistari;
        vector<int> multistari_finale_index;
        vector<tranzitie> tranzitii;
        vector< vector<int> > GetTabel();
        void Afisare();
        void InsertNewTabelEntry(int multistare_plecare_index, int simbol_index, int multistare_noua_index);
        void AddMultiStare(MultiStare multiStare);
        int GetMultiStariNumber();
        void AfiseazaMatrice();
        int DoesMultiStareExists(MultiStare ms);
        int GetMultiStareIndexLike(MultiStare ms);

    protected:
};

#endif // DFA2_H
