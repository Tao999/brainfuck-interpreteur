#ifndef INTERPRETOR_H
#define INTERPRETOR_H
#include <stack>
#include <iostream>
#include <fstream>

#include "Chain.h"

#define MOVE_FORWARD    '>'
#define MOVE_BACKWORD   '<'
#define INCREMENT       '+'
#define DECREMENT       '-'
#define PRINT           '.'
#define GET_CHAR        ','
#define OPEN_LOOP       '['
#define CLOSE_LOOP       ']'

using namespace std;

class Interpretor
{
    public:
        Interpretor(string path);
        ~Interpretor();

        void Compute();
    protected:

    private:
        fstream m_file;
        stack<streampos> m_stack;
        Chain m_memory;
};

#endif // INTERPRETOR_H
