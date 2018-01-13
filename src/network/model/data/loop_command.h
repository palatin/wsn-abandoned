
#ifndef WSN_LOOP_COMMAND_H
#define WSN_LOOP_COMMAND_H

#include "command.h"


/*
 * Child of Command class that tell nodes to execute command every @iterateTime seconds
*/

//TODO stop mechanism
namespace wsn {

    namespace model {

        namespace command {


            class LoopCommand : Command {


            private:
                //time in which node will repeat command (seconds)
                double iterateTime;


            };

        }
    }
}



#endif //WSN_LOOP_COMMAND_H
