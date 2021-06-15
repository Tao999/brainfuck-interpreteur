#include <iostream>
#include "Interpretor.h"

using namespace std;

int main(int argc, char**argv)
{
    Interpretor*i = new Interpretor(argv[1]);
    i->Compute();
    delete i;
    return 0;
}
