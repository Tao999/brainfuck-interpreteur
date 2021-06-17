#include "Interpretor.h"

Interpretor::Interpretor(string path)
{
    m_file.open(path, ios::in|ios::binary);

    if(!m_file.is_open()){
        cerr << "fichier \"" << path << "\" non trouvé" << endl;
        exit(0);
    }
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
            else
                m_stack.push(m_file.tellg());
            break;

        case CLOSE_LOOP:
            //si la val acctuelle !=0, on reviens au '[' correspondant
            if(m_memory.GetValue())
                m_file.seekg(m_stack.top());
            else{//sinon on pop le '[' du stack pour ne pas y revenir
                if(!m_stack.size()){
                    cerr << endl << "instruction ']' non valide au caractère " << m_file.tellg()
                        << ", '[' manquant"<< endl;
                    exit(0);
                }
                m_stack.pop();
            }
            break;

        case PRINT:
            cout << (char)m_memory.GetValue();
            break;

        case GET_CHAR:
            char temp;
            cin >> temp;
            cin.ignore();
            m_memory.SetValue(temp);
            break;
        default:
        break;
        }
    }

}
