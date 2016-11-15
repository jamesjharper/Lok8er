#ifndef D_35EC4D04_7E80_44C9_ACF9_CF859EB2A034__h
#define D_35EC4D04_7E80_44C9_ACF9_CF859EB2A034__h

// Includes for Exceptions
#include "ActivationException.h"

START_NAMEPSACE__LOK8ER__COMPOSITION
{
    template<typename TService>
    class FactoryDelegateServiceProvider : public IServiceProvider<TService>
    {

        TService* (*m_pFactoryDelegate)();

    public:


        /// <summary>
        /// Initializes a new instance of the <see cref="FactoryDelegateServiceProvider{TService}"/> class.
        /// </summary>
        /// <param name="pFactoryDelegate">The p factory delegate.</param>
        explicit FactoryDelegateServiceProvider(TService* (*pFactoryDelegate)())
        {
            if (!pFactoryDelegate)
                throw LOK8ER__ERRORS::ActivationException("There was an attempt to inject a factory delegate which was NULL.", typeid(TService));

            m_pFactoryDelegate = pFactoryDelegate;
        }


        /// <summary>
        /// Finalizes an instance of the <see cref="FactoryDelegateServiceProvider"/> class.
        /// </summary>
        virtual ~FactoryDelegateServiceProvider() {}

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        virtual std::shared_ptr<TService> GetInstance() override
        {
            std::shared_ptr<TService> instance;
            instance.reset(m_pFactoryDelegate());
            return instance;
        }
    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif
