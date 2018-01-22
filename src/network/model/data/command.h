

#ifndef WSN_COMMAND_H
#define WSN_COMMAND_H


#include "data.h"


namespace wsn {

    namespace model {

        //forward declaration
        class Node;


        class Command : public Data {

        public:
            Command(Node *sender, Node *receiver, double dataLength);
            virtual ~Command() = default;

        private:
            //virtual void execute(Node *node) = 0;

        };


    }
}

#endif //WSN_COMMAND_H
