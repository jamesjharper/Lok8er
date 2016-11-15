#include "stdafx.h"
#include "../Lok8er/Lok8er.h"
#include "ServiceA.h"

int main()
{
    lok8er::Initalize();

    auto serviceLocator = lok8er::ServiceLocator::GetCurrent();

    serviceLocator->RegisterService<ServiceA>(lok8er::Singleton_Lifestyle);
    serviceLocator->RegisterService<ServiceB>(lok8er::Transient_Lifestyle);
    serviceLocator->RegisterInstance(new ServiceC());
    serviceLocator->RegisterService<ServiceD>();


    auto serviceA = serviceLocator->GetInstance<ServiceA>();

}

