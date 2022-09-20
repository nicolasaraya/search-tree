#ifndef NODE_H
#define NODE_H

class Node{
    public:
        Node(int);
        ~Node();
        Node* getParent();
        Node* getChildLeft();
        Node* getChildRight();
        int getKey();
        int getHeight();
        void setHeight(int);
        void setParent(Node*);
        void setChildLeft(Node*);
        void setChildRight(Node*);
    private:
        int key;
        int height;
        Node* parent;
        Node* childLeft;
        Node* childRight;
};

#endif