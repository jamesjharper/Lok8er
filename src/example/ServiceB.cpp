#include "stdafx.h"
#include "ServiceB.h"

ServiceB::ServiceB(INJECTED_COMPONENT<ServiceC> serviceC) :
    _serviceC(serviceC)
{

}
