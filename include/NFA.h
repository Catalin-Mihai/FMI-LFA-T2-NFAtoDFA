#ifndef NFA_H
#define NFA_H

#include "FA.h"
#include "DFA2.h"

class NFA: public FA
{
    public:

        NFA();
        ~NFA();
        //virtual bool CheckWord(string word);
        void CitesteTranzitii();
        DFA2 ConvertToDFA2();
        //stare GetMultiStareByIndex(int index);
        int getStareIndexByLitera(string l);
        int GetMultiStareIndexByLitera(string litera) const;
        void AfiseazaMatrice();
        friend istream &operator>>(istream &input, NFA &nfa);
        void AddMultiStare(MultiStare multiStare);
        int GetMultiStariNumber() const;
        void Afiseaza();
        simbol getSimbolByLitera(string l);
        void MergeDestinations(int plecare_id);

    private:
        vector< vector< int > > tabel;
        //virtual bool check(NFA &nfa, int stare_index, string word, unsigned int position);
        int multistare_initiala_index;
        int stare_initiala;
        vector<int> stari_finale;
        vector<stare> stari;
        vector<simbol> simboluri;
        vector<MultiStare> multistari;
        vector<int> multistari_finale_index;
        vector<tranzitie> tranzitii;


};

#endif // NFA_H
