#ifndef D_D814778C_9666_49EE_B32B_27CC4202C8C8__h
#define D_D814778C_9666_49EE_B32B_27CC4202C8C8__h

// Includes for Exceptions
#include "ActivationException.h"

START_NAMEPSACE__LOK8ER__COMPOSITION
{
    template<typename TService>
    class DefaultInjectedServiceProvider : public IServiceProvider<TService>
    {

        /// <summary>
        /// The singleton instance if life style is "Singleton"
        /// </summary>
        COMPONENT<TService> s_TSingletonInstance;

    public:

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        explicit DefaultInjectedServiceProvider(TService* pInstance)
        {
            if (!pInstance)
                throw LOK8ER__ERRORS::ActivationException("There was an attempt to inject an instance which was NULL.", typeid(TService));

            s_TSingletonInstance.reset(pInstance);
        }

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        explicit DefaultInjectedServiceProvider(COMPONENT<TService>& instance) :
            s_TSingletonInstance(instance)
        {
            
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="DefaultInjectedServiceProvider"/> class.
        /// </summary>
        virtual ~DefaultInjectedServiceProvider() {}

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        virtual COMPONENT<TService> GetInstance() override
        {
            return s_TSingletonInstance;
        }
    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif