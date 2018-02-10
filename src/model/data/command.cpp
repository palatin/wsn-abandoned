

#include "model/data/command.h"



wsn::model::Command::Command(wsn::model::Node *sender, wsn::model::Node *receiver,
                             double dataLength) : Data(sender, receiver, dataLength) {

}
