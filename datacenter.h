#ifndef __DATACENTER_H
#define __DATACENTER_H

#include "model/member.h"
#include "model/entity.h"
//Provides an abstraction layer for access to the various lists and other things under tristan's purview

class datacenter {
    bool hasEntity(entity e);
    bool isMember(entity e);
    bool isSuspended(entity e);
};

#endif
