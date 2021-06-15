#ifndef CHAIN_H
#define CHAIN_H


class Chain
{
    public:
        Chain();
        ~Chain();

        void MoveForward();
        void MoveBackward();
        void Inc();
        void Dec();

        int GetValue();

    protected:

    private:
        class Node{
        public:
            Node();
            ~Node();

            int m_value;
            Node*pNext;
            Node*pPrev;
        };

        Node*m_current;

};

#endif // CHAIN_H
