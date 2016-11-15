#pragma once
#include "../Lok8er/Lok8er.h"
#include "ServiceB.h"
#include "ServiceD.h"

class ServiceA
{
    COMPONENT<ServiceB> _serviceB;
    COMPONENT<ServiceD> _serviceD;

public:
    ServiceA(INJECT_COMPONENT(ServiceB, serviceB), 
             INJECT_COMPONENT(ServiceD, serviceD));

};
