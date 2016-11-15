#ifndef D_D3F68715_0EA5_42CC_B052_66238E5D20A1__h
#define D_D3F68715_0EA5_42CC_B052_66238E5D20A1__h

#include "Inject.h"
#include "IServiceProvider.h"
#include "Lifestyle.h"
#include "ServiceProviderCoordinatorAccessor.h"
#include "DefaultConstructorServiceProvider.h"
#include "DefaultInjectedServiceProvider.h"
#include "FactoryDelegateServiceProvider.h"
#include "ActivationException.h"

// Some compilers generate symbols differently resulting in lib files missing the TryInjectInstance<TService> symbol.
// as such we use this to force the TryInjectInstance symbol to be included in the symbol file
#define DEFINE_TRYINJECT_FOR_TYPE(TService) { COMPONENT<TService> (*f)() = &LOK8ER::TryInjectInstance<TService>; (void)f; }

START_NAMEPSACE__LOK8ER__COMPOSITION
{

    class ServiceProviderAdapter
    {
    public:

        /// <summary>
        /// Registers a service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        template<typename TService>
        void RegisterServiceProvider(IServiceProvider<TService>* serviceProvider)
        {
            LOK8ER_LOGGING_DEBUG("Service Provider for %s Registered", typeid(ITService).name());
            GetServiceCoordinator<TService>()->SetProvider(serviceProvider);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

        /// <summary>
        /// De registers the service providers.
        /// This is only used for unit tests. probably not a good idea to call this for any other reason 
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        template<typename TService>
        void DeregisterServiceProviders()
        {
            LOK8ER_LOGGING_DEBUG("Service provider for %s unregistered", typeid(TService).name());
            ResetServiceCoordinator<TService>();
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Registers a named service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        /// <param name="instanceName">Name of the instance.</param>
        template<typename TService>
        void RegisterServiceProvider(std::string instanceName, IServiceProvider<TService>* serviceProvider)
        {
            LOK8ER_LOGGING_DEBUG("Service Provider for %s named \"%s\" Registered", typeid(TService).name(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(serviceProvider, instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Registers a named service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        /// <param name="instanceName">Name of the instance.</param>
        template<typename TService>
        void RegisterServiceProvider(std::wstring instanceName, IServiceProvider<TService>* serviceProvider)
        {
            LOK8ER_LOGGING_DEBUG(L"Service Provider for %s named \"%s\" Registered", LOK8ER__PLATFROMS::tstrings::ToWideString(typeid(ITService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(serviceProvider, instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif

        /// <summary>
        /// Registers a Factory service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        template<typename TService>
        void RegisterFactoryServiceProvider(TService* (*pFactoryDelegate)())
        {
            LOK8ER_LOGGING_DEBUG("Service Provider Factory for %s Registered", typeid(TService).name());
            GetServiceCoordinator<TService>()->SetProvider(new FactoryDelegateServiceProvider<TService>(pFactoryDelegate));
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Registers a named Factory service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        /// <param name="instanceName">Name of the instance.</param>
        template<typename TService>
        void RegisterFactoryServiceProvider(std::string instanceName, TService* (*pFactoryDelegate)())
        {
            LOK8ER_LOGGING_DEBUG("Service Provider Factory for %s named \"%s\" Registered", typeid(TService).name(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new FactoryDelegateServiceProvider<TService>(pFactoryDelegate), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Registers a named Factory service provider.
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        /// <param name="instanceName">Name of the instance.</param>
        template<typename TService>
        void RegisterFactoryServiceProvider(std::wstring instanceName, TService* (*pFactoryDelegate)())
        {
            LOK8ER_LOGGING_DEBUG(L"Service Provider Factory for %s named \"%s\" Registered", LOK8ER__PLATFROMS::tstrings::ToWideString(typeid(TService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new FactoryDelegateServiceProvider<TService>(pFactoryDelegate), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif

        // Registration for Default constructors 

        /// <summary>
        /// Registers a service.
        /// </summary>
        /// <param name="lifestyle">The service lifestyle.</param>
        template<typename TService>
        void RegisterService(Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG("Service for %s Registered", typeid(TService).name());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultConstructorServiceProvider<TService, TService>(lifestyle));
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Registers a named service.
        /// </summary>
        /// <param name="lifestyle">The service lifestyle.</param>
        template<typename TService>
        void RegisterService(std::string instanceName, Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG("Service for %s named \"%s\" Registered", typeid(ITService).name(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultConstructorServiceProvider<TService, TService>(lifestyle), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }
#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Registers a named service.
        /// </summary>
        /// <param name="lifestyle">The service lifestyle.</param>
        template<typename TService>
        void RegisterService(std::wstring instanceName, Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG(L"Service for %s named \"%s\" Registered", tstrings::ToWideString(typeid(TService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultConstructorServiceProvider<TService, TService>(lifestyle), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif

        /// <summary>
        /// Registers a service implementation.
        /// </summary>
        /// <param name="lifestyle">The lifestyle.</param>
        template<typename ITService, typename TServiceImpl>
        void RegisterServiceImplementation(Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG("Service for %s Registered to %s", typeid(ITService).name(), typeid(TServiceImpl).name());
            GetServiceCoordinator<ITService>()->SetProvider(new DefaultConstructorServiceProvider<ITService, TServiceImpl>(lifestyle));
            DEFINE_TRYINJECT_FOR_TYPE(ITService);
        }

#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Registers a named service implementation.
        /// </summary>
        /// <param name="lifestyle">The lifestyle.</param>
        template<typename ITService, typename TServiceImpl>
        void RegisterServiceImplementation(std::string& instanceName, Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG("Service for %s named \"%s\" Registered", typeid(ITService).name(), instanceName.c_str());
            GetServiceCoordinator<ITService>()->SetProvider(new DefaultConstructorServiceProvider<ITService, TServiceImpl>(lifestyle), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(ITService);
        }

#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Registers a named service implementation.
        /// </summary>
        /// <param name="lifestyle">The lifestyle.</param>
        template<typename ITService, typename TServiceImpl>
        void RegisterServiceImplementation(std::wstring& instanceName, Lifestyle lifestyle = Singleton_Lifestyle)
        {
            LOK8ER_LOGGING_DEBUG(L"Service for %s named \"%s\" Registered", LOK8ER__PLATFROMS::tstrings::ToWideString(typeid(ITService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<ITService>()->SetProvider(new DefaultConstructorServiceProvider<ITService, TServiceImpl>(lifestyle), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(ITService);
        }

#endif

        /// <summary>
        /// Registers a instance.
        /// </summary>
        /// <param name="pInstance">The p instance.</param>
        template<typename TService>
        void RegisterInstance(TService* pInstance)
        {
            LOK8ER_LOGGING_DEBUG("Service instance for %s Registered", typeid(TService).name());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(pInstance));
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

        /// <summary>
        /// Registers a named instance.
        /// </summary>
        /// <param name="pInstance">The p instance.</param>
        template<typename TService>
        void RegisterInstance(std::string& instanceName, TService* pInstance)
        {
            LOK8ER_LOGGING_DEBUG("Service instance for %s named \"%s\" Registered", typeid(TService).name(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(pInstance), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

        /// <summary>
        /// Registers a named instance.
        /// </summary>
        /// <param name="pInstance">The p instance.</param>
        template<typename TService>
        void RegisterInstance(std::wstring& instanceName, TService* pInstance)
        {
            LOK8ER_LOGGING_DEBUG(L"Service instance for %s named \"%s\" Registered", tstrings::ToWideString(typeid(TService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(pInstance), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        template<typename TService>
        void RegisterInstance(COMPONENT<TService> instance)
        {
            LOK8ER_LOGGING_DEBUG("Service instance for %s Registered", typeid(TService).name());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(instance));
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Registers a named instance.
        /// </summary>
        /// <param name="pInstance">The p instance.</param>
        template<typename TService>
        void RegisterInstance(std::string& instanceName, COMPONENT<TService> instance)
        {
            LOK8ER_LOGGING_DEBUG("Service instance for %s named \"%s\" Registered", typeid(TService).name(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(instance), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }
#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Registers a named instance.
        /// </summary>
        /// <param name="pInstance">The p instance.</param>
        template<typename TService>
        void RegisterInstance(std::wstring& instanceName, COMPONENT<TService> instance)
        {
            LOK8ER_LOGGING_DEBUG(L"Service instance for %s named \"%s\" Registered", tstrings::ToWideString(typeid(TService).name()).c_str(), instanceName.c_str());
            GetServiceCoordinator<TService>()->SetProvider(new DefaultInjectedServiceProvider<TService>(instance), instanceName);
            DEFINE_TRYINJECT_FOR_TYPE(TService);
        }

#endif


        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <param name="key">Name the object was registered with.</param>
        /// <exception cref="ActivationException">if there is are errors resolving
        /// the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        COMPONENT<TService> GetInstance()
        {
            return GetServiceCoordinator<TService>()->GetInstance();
        }


#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <param name="key">Name the object was registered with.</param>
        /// <exception cref="ActivationException">if there is are errors resolving
        /// the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        COMPONENT<TService> GetInstance(std::string key)
        {
            return GetServiceCoordinator<TService>()->GetInstance(key);
        }

#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <param name="key">Name the object was registered with.</param>
        /// <exception cref="ActivationException">if there is are errors resolving
        /// the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        COMPONENT<TService> GetInstance(std::wstring& key)
        {
            return GetServiceCoordinator<TService>()->GetInstance(key);
        }

#endif

        /// <summary>
        /// Get all instances of the given <paramref name="serviceType"/> currently
        /// registered in the container.
        /// </summary>
        /// <param name="serviceType">Type of object requested.</param>
        /// <exception cref="ActivationException">if there is are errors resolving
        /// the service instance.</exception>
        /// <returns>A sequence of instances of the requested <paramref name="serviceType"/>.</returns>
        template<typename TService>
        COMPONENT_LIST<TService> GetAllInstances()
        {
            return GetServiceCoordinator<TService>()->GetAllInstances();
        }

        /// <summary>
        /// Attempts to resolve specified type from the underlying <see cref="IServiceLocator"/>.
        /// </summary>
        /// <remarks>
        /// This will return null on any <see cref="ActivationException"/>.</remarks>
        /// <param name="locator">Locater to use in resolving.</param>
        /// <param name="type">Type to resolve.</param>
        /// <returns>T or null</returns>
        /// <exception cref="ArgumentNullException">Thrown when <paramref name="locator"/> is <see langword="null"/>.</exception>
        template<typename TService>
        COMPONENT<TService> TryResolve()
        {
            try
            {
                return GetInstance<TService>();
            }
            catch (LOK8ER__ERRORS::ActivationException& aEx)
            {
                (void)aEx; // Used to prevent Warning C4101: e unreferenced local variable when build with our exception messaging
            }
            return COMPONENT<TService>();
        }
    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif
