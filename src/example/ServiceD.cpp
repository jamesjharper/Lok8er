#include "stdafx.h"
#include "ServiceD.h"

ServiceD::ServiceD(INJECTED_COMPONENT<ServiceC> serviceC) :
    _serviceC(serviceC)
{

}
