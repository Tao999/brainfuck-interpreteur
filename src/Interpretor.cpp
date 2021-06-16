#include <iostream>
#include "Interpretor.h"

Interpretor::Interpretor(string path)
{
    m_file.open(path, ios::in|ios::binary);
}

Interpretor::~Interpretor()
{
    m_file.close();
}

void Interpretor::Compute()
{
    char c;
    while (m_file.get(c)) {
        switch (c){
        case MOVE_FORWARD:
            m_memory.MoveForward();
            break;

        case MOVE_BACKWORD:
            m_memory.MoveBackward();
            break;

        case INCREMENT:
            m_memory.Inc();
            break;

        case DECREMENT:
            m_memory.Dec();
            break;

        case OPEN_LOOP:
        //si valeure acctuelle != 0 -> on cherche la fin de la boucle
            if(!m_memory.GetValue()){
                int nbopen=0;
                do{
                    if(c == OPEN_LOOP)
                        nbopen++;
                    else if(c == CLOSE_LOOP)
                        nbopen--;
                     m_file.get(c);
                }while(nbopen || m_file.eof());
                m_file.seekg(-1, ios_base::cur);
            }
            break;

        case CLOSE_LOOP:
        //si valeure acctuelle != 0 -> on cherche le début de la boucle
            if(m_memory.GetValue())
            {
                int nbopen=0;
                do{
                    if(c == OPEN_LOOP)
                        nbopen++;
                    else if(c == CLOSE_LOOP)
                        nbopen--;
                    m_file.seekg(-2, ios_base::cur);
                    m_file.get(c);
                    m_file.seekg(0, ios_base::cur);

                }while(nbopen);
                m_file.seekg(1, ios_base::cur);
                //cout << "end" <<endl;
            }
            break;

        case PRINT:
            cout << (char)m_memory.GetValue();
            break;

        case GET_CHAR:
            m_memory.SetValue(getchar());
            break;
        default:
        break;
        }
    }

}
