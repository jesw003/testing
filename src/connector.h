#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "include.h"

class Connector {
    protected:
        char* command[256]; // Holds arguments
        Connector* left;
        Connector* right;
        
        bool execute(char* args[]);
    public:
        Connector();
        Connector(char* argv[]);
        virtual ~Connector();
        virtual bool run();
        void setLeft(Connector* left);
        void setRight(Connector* right);
        Connector* getLeft();
        Connector* getRight();
        bool hasLeft();
        bool hasRight();
        void destroyBranch(Connector* node);
        char** getCmd();
        virtual void identify();
};

class Ampersand : public Connector {
    public:
        Ampersand();
        Ampersand(Connector* l, Connector* r);
        ~Ampersand();
        bool run();
        
        void identify();
};

class DoubleBars : public Connector {
    public:
        DoubleBars();
        DoubleBars(Connector* l, Connector* r);
        ~DoubleBars();        
        bool run();

        void identify();
};

class Semicolon : public Connector {
    public:
        Semicolon();
        Semicolon(Connector* l, Connector* r);
        ~Semicolon();
        bool run();

        void identify();
};

class Hash : public Connector {
    public:
        Hash();
        Hash(Connector* l, Connector* r);
        ~Hash();
        bool run();

        void identify();
};

class ConnectorFactory {
    public:
        Connector* createBranch(list<char**>&, list<char*>&);
        Connector* createConnector(int);
};

#include "helper.h"

#endif
