#ifndef D_610DA326_6DB0_4833_9DCF_DBFB1FDB76A3__h
#define D_610DA326_6DB0_4833_9DCF_DBFB1FDB76A3__h

#include "ServiceProviderCoordinator.h"

START_NAMEPSACE__LOK8ER__COMPOSITION
{

    template<typename TService>
    class ServiceProviderCoordinatorAccessor
    {

        /// <summary>
        /// The contain instance of the ServiceProviderCoordinator of type TService
        /// </summary>
        static COMPONENT<ServiceProviderCoordinator<TService>> m_instance;

    public:

        /// <summary>
        /// Gets the GetCoordinator instance.
        /// </summary>
        static ServiceProviderCoordinator<TService>* GetCoordinator()
        {
            if (m_instance)
                return m_instance.get();

            m_instance.reset(new ServiceProviderCoordinator<TService>());
            return m_instance.get();
        }

        /// <summary>
        /// Resets the GetCoordinator instance.
        /// </summary>
        static void ResetCoordinator()
        {
            m_instance.reset();
        }
    };

    template <typename TService> COMPONENT<ServiceProviderCoordinator<TService>> ServiceProviderCoordinatorAccessor<TService>::m_instance;

    /// <summary>
    /// Gets the GetCoordinator instance.
    /// </summary>
    template<typename TService>
    extern ServiceProviderCoordinator<TService>* GetServiceCoordinator()
    {
        return ServiceProviderCoordinatorAccessor<TService>::GetCoordinator();
    }

    /// <summary>
    /// Gets the GetCoordinator instance.
    /// </summary>
    template<typename TService>
    extern void ResetServiceCoordinator()
    {
        return ServiceProviderCoordinatorAccessor<TService>::ResetCoordinator();
    }
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif
