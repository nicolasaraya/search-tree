#ifndef NODE_H
#define NODE_H
#define RED 1
#define BLACK 0

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
        bool getColor();
        void setColor(bool);
        
    private:
        int key;
        int height;
        bool color;
        Node* parent;
        Node* childLeft;
        Node* childRight;
        
};

#endif