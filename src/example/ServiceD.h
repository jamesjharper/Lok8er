#pragma once
#include "../Lok8er/Lok8er.h"
#include "ServiceC.h"

class ServiceD
{

    COMPONENT<ServiceC> _serviceC;

public:
    ServiceD(INJECT_COMPONENT(ServiceC, serviceC));

};
