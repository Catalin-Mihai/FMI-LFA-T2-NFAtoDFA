#ifndef FA_H
#define FA_H

#include <string>
#include <istream>
#include <iostream>
#include <vector>

using namespace std;

class FA{

public:

    struct simbol
    {
        string litera;
        int index;
    };

    struct tranzitie
    {
        simbol simb;
        int plecare;
        int destinatie;
    };

    struct stare
    {
        string litera;
        int index;
    };

    FA();
    ~FA();

protected:

};



#endif // FA_H
