
#ifndef WSN_DATA_H
#define WSN_DATA_H


#include <cstddef>

//TODO copy dynamic array
namespace wsn {

    namespace model {

        //forward decr
        class Node;

        class Data {

        public:
            /*
            //Data class will not obtain and manage memory of data array
            Data(Node *sender, Node *receiver, const unsigned char *const data, size_t dataLength);
            Data(const Data &data);
             */
            Data(const Node *sender, const Node *receiver, double dataLength);
            virtual ~Data() = default;

            double getDataLength() const;
            const Node* getSender() const;
            const Node* getReceiver() const;


        private:
            const Node *sender;
            const Node *receiver;
            double length = 0;


        };



    }

}

#endif //WSN_DATA_H
