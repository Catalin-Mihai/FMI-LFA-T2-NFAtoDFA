#ifndef MULTISTARE_H
#define MULTISTARE_H

#include <string>
#include <vector>
#include <algorithm>
#include "FA.h"

using namespace std;

class MultiStare
{
    public:
        MultiStare();
        MultiStare(int index);
        ~MultiStare();
        void Add(int stare_index, string l = "$");
        int GetIndex() const;
        void SetIndex(int i);
        void Afisare();
        int GetSize();
        int IsIndexInMultiStare(int n);
        int IsEmpty();
        int Contains(int i);
        //void SetLitera(string l);
        //string GetLitera() const;
        vector<int> stari_index;
        int index;
        vector<string> litere;

    protected:

    private:

};

#endif // MULTISTARE_H
