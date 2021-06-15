#include "Chain.h"

Chain::Chain()
{
    m_current = new Node();
}

Chain::~Chain()
{
    delete m_current;
}

void Chain::MoveBackward(){
    //si le prev n'existe pas, on le crée
    if(m_current->pPrev == nullptr){
        m_current->pPrev = new Node();
        m_current->pPrev->pNext = m_current;
    }
    m_current = m_current->pPrev;
}

void Chain::MoveForward(){
    //si le suivant n'existe pas, on le crée
    if(m_current->pNext == nullptr){
        m_current->pNext = new Node();
        m_current->pNext->pPrev = m_current;
    }
    m_current = m_current->pNext;
}


void Chain::Inc(){
 m_current->m_value++;
}

void Chain::Dec(){
    m_current->m_value--;
}

int Chain::GetValue(){
    return m_current->m_value;
}

Chain::Node::Node():
pPrev(nullptr),
pNext(nullptr)
{
    //ctor
}

Chain::Node::~Node()
{
    //déstruction en cascade
    if(pPrev){
        Node*temp = pPrev;
        temp->pNext = nullptr;
        pPrev = nullptr;
        delete temp;
    }

    if(pNext){
        Node*temp = pNext;
        temp->pPrev = nullptr;
        pNext = nullptr;
        delete temp;
    }}

