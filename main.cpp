#include <iostream>
#include <fstream>

#include "FA.h"
#include "NFA.h"
#include "DFA2.h"


using namespace std;

int main()
{
    ifstream f("input.txt");
    NFA nfa;
    f>>nfa;
    int nr_cuv;
    f>>nr_cuv;
    //nfa.Afiseaza();
    DFA2 dfa = nfa.ConvertToDFA2();
    dfa.Afisare();
    return 0;
}
