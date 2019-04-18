#ifndef DFA_H
#define DFA_H

#include "FA.h"

class DFA: public FA
{
    public:
        DFA();
        ~DFA();
        bool CheckWord(string word);
        int **&getMatrice();
        void CitesteTranzitii();
        void AfiseazaMatrice();
    protected:

    private:
        int **matrice;
};

#endif // DFA_H
