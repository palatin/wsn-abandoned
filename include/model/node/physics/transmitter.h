
#ifndef WSN_TRANSMITTER_H
#define WSN_TRANSMITTER_H


#include <util/geometry.h>
#include "../node.h"
#include "../../data/data.h"



namespace wsn {

    namespace model {





        class Transmitter {

        public:

            Transmitter() = default;
            ~Transmitter() = default;

            /// Method that calculate energy dissipation for sending data from sender to receiver
            /// and call @method receiveDataByNode
            /// @param data
            /// @param sender
            /// @param receiver
            /// @return true if data can be sent
            virtual bool sendData(const Data &data, Node &sender, const Node &receiver) const = 0;

            /// Method that calculate energy dissipation for receiving data
            /// @param data
            /// @param receiver
            /// @return true if data can be received
            virtual bool receiveData(const Data &data, Node &receiver) const = 0;




        protected:
            bool spendEnergy(Node &node, double energy) const {
                return node.spendEnergy(energy);
            }

        };



    }

}

#endif //WSN_TRANSMITTER_H
