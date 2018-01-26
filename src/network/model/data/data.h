
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
            ///
            /// @param sender - data sender node
            /// @param receiver -data receiver node
            /// @param dataLength - data length in bits
            Data(const Node *sender, const Node *receiver, unsigned long dataLength);
            virtual ~Data() = default;


            double getDataLength() const;
            const Node* getSender() const;
            const Node* getReceiver() const;


        private:
            const Node *sender;
            const Node *receiver;
            ///data length in bits
            unsigned long length = 0;


        };



    }

}

#endif //WSN_DATA_H
