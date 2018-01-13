

#ifndef WSN_COMMAND_H
#define WSN_COMMAND_H


#include "data.h"
#include "../node/node.h"

namespace wsn {

    namespace model {

        namespace command {

            class Command : Data {

                virtual void execute(Node *node) = 0;

            };

        }

    }
}

#endif //WSN_COMMAND_H
