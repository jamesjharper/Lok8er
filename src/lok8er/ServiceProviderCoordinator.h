#ifndef D_A9FDE625_A542_462F_9E30_FC311F7135B1__h
#define D_A9FDE625_A542_462F_9E30_FC311F7135B1__h

#include "namespaces.h"

#include <unordered_map>

// Includes for Exceptions
#include "ActivationException.h"

#ifdef SUPPORT_WIDE_CHAR
// Include for help with strings
#include "tstrings.h"
#endif



START_NAMEPSACE__LOK8ER__COMPOSITION
{
    template<typename TService>
    class ServiceProviderCoordinator
    {
#ifdef SUPPORT_WIDE_CHAR
        
        typedef std::wstring name_string_type;

#else
        typedef std::string name_string_type;
#endif
        typedef std::unordered_map<name_string_type, COMPONENT<IServiceProvider<TService>>> LocationProviderDictionary;
        typedef std::vector<COMPONENT<IServiceProvider<TService>>> LocationProviderVector;

        /// <summary>
        /// The instance Location vector
        /// </summary>
        LocationProviderVector m_LocationProviders;

        /// <summary>
        /// The instance Location Dictionary 
        /// </summary>
        LocationProviderDictionary m_NamedLocationProviders;

    public:

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(IServiceProvider<TService>* instance)
        {
            COMPONENT<IServiceProvider<TService>> ITServiceProvider;
            ITServiceProvider.reset(instance);
            SetProvider(ITServiceProvider);
        }

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(COMPONENT<IServiceProvider<TService>> instance)
        {
            m_LocationProviders.push_back(instance);
        }

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(IServiceProvider<TService>* instance, std::string& namedInstance)
        {
            SetProvider(instance, LOK8ER__PLATFROMS::tstrings::ToWideString(namedInstance));
        }

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(COMPONENT<IServiceProvider<TService>> instance, std::string& namedInstance)
        {
            SetProvider(instance, LOK8ER__PLATFROMS::tstrings::ToWideString(namedInstance));
        }

#endif

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(IServiceProvider<TService>* instance, name_string_type namedInstance)
        {
            COMPONENT<IServiceProvider<TService>> ITServiceProvider;
            ITServiceProvider.reset(instance);
            SetProvider(ITServiceProvider, namedInstance);
        }

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        void SetProvider(COMPONENT<IServiceProvider<TService>> serviceProvider, name_string_type namedInstance)
        {
            m_LocationProviders.push_back(serviceProvider);
            m_NamedLocationProviders[namedInstance] = serviceProvider;
        }

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT<TService> GetInstance()
        {
            if (m_LocationProviders.size() == 0)
            {
                throw LOK8ER__ERRORS::ActivationException("A problem occurred when resolving instance of %s from container, no service provider has been registered for this type.", typeid(TService));
            }

            COMPONENT<IServiceProvider<TService>> firstServiceProvider = m_LocationProviders.at(0);
            return firstServiceProvider->GetInstance();
        }


        
#ifdef SUPPORT_WIDE_CHAR
#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT<TService> GetInstance(std::string& namedInstance)
        {
            std::wstring wNamedInstance = LOK8ER__PLATFROMS::tstrings::ToWideString(namedInstance);
            return GetInstance(wNamedInstance);
        }
#endif
#endif

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT<TService> GetInstance(name_string_type& namedInstance)
        {
            auto findResult = m_NamedLocationProviders.find(namedInstance);

            // Validate that the provider exists
            if (findResult == m_NamedLocationProviders.end())
            {
                throw LOK8ER__ERRORS::ActivationException("A problem occurred when resolving named instance \"%s\" of %s from container, no service provider has been registered for this type.", typeid(TService));
            }

            COMPONENT<IServiceProvider<TService>> namedServiceProvider = findResult->second;
            return namedServiceProvider->GetInstance();
        }


        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT_LIST<TService> GetAllInstances()
        {
            COMPONENT_LIST<TService> instancesVector;
            typename COMPONENT_LIST<TService>::iterator it;

            for (it = m_LocationProviders.begin(); it != m_LocationProviders.end(); ++it)
            {
                COMPONENT<IServiceProvider<TService>> serviceProvider = *it;
                instancesVector->push_back(serviceProvider->GetInstance());
            }

            return instancesVector;
        }

        /// <summary>
        /// De registers all the service providers.
        /// This is only used for unit tests. probably not a good idea to call this for any other reason 
        /// </summary>
        /// <param name="serviceProvider">The service provider.</param>
        void DeregisterServiceProviders()
        {
            m_LocationProviders.clear();
            m_NamedLocationProviders.clear();
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="ServiceLocator"/> class.
        /// </summary>
        ~ServiceProviderCoordinator()
        {
        }

    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif
