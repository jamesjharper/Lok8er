#ifndef D_20A28638_ADD7_498B_AB8C_5CF2CE01C1E7__h
#define D_20A28638_ADD7_498B_AB8C_5CF2CE01C1E7__h

#include "ActivationException.h"

/// <summary>
/// The backbone macro used to constructor inject.
/// </summary>
#define INJECT_COMPONENT(TService, instanceName) INJECTED_COMPONENT<TService> instanceName = LOK8ER::TryInjectInstance<TService>()

START_NAMEPSACE__LOK8ER
{

    /// <summary>
    /// Try to resolves an instance from the container
    /// </summary>
    /// <param name="instance">The instance.</param>
    template<typename TService>
    extern COMPONENT<TService> TryInjectInstance()
    {
        try
        {
            return ServiceLocator::GetInstance<TService>();
        }
        catch (LOK8ER__ERRORS::ActivationException& aEx)
        {
            (void)aEx; // Used to prevent Warning C4101: eaEx unreferenced local variable 
            LOK8ER_LOGGING_ERROR("Failed to resolve injected dependency, %s", aEx.what());
            throw;
        }
    }

}
END_NAMEPSACE__LOK8ER

#endif