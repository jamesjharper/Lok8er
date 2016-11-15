#pragma once
#include "../Lok8er/Lok8er.h"
#include "ServiceC.h"

class ServiceB
{

    COMPONENT<ServiceC> _serviceC;

public:
    ServiceB(INJECT_COMPONENT(ServiceC, serviceC));

};
