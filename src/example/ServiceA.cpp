#include "stdafx.h"
#include "ServiceA.h"


ServiceA::ServiceA(INJECTED_COMPONENT<ServiceB> serviceB,
                   INJECTED_COMPONENT<ServiceD> serviceD) :
    _serviceB(serviceB),
    _serviceD(serviceD)
{

}
