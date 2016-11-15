#ifndef D_9FEFA131_13DC_4AAF_8244_A03831DC7D0D__h
#define D_9FEFA131_13DC_4AAF_8244_A03831DC7D0D__h

START_NAMEPSACE__LOK8ER
{        

    template<typename IServiceLocatorAdapter>
    class ServiceLocatorBase
    {

    public:

        /// <summary>
        /// Get an instance of the given type <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <exception cref="ActivationException">if there is are errors resolving the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        static COMPONENT<TService> GetInstance()
        {
            return GetCurrent()->template GetInstance<TService>();
        }


#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <param name="key">Name the object was registered with.</param>
        /// <exception cref="ActivationException">if there is are errors resolving the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        static COMPONENT<TService> GetInstance(std::string& key)
        {
            return GetCurrent()->template GetInstance<TService>(key);
        }

#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <param name="key">Name the object was registered with.</param>
        /// <exception cref="ActivationException">if there is are errors resolving the service instance.</exception>
        /// <returns>The requested service instance.</returns>
        template<typename TService>
        static COMPONENT<TService> GetInstance(std::wstring& key)
        {
            return GetCurrent()->template GetInstance<TService>(key);
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
        static COMPONENT_LIST<TService> GetAllInstances()
        {
            return GetCurrent()->template GetAllInstances<TService>();
        }

        /// <summary>
        /// The current ambient container.
        /// </summary>
        static COMPONENT<IServiceLocatorAdapter> GetCurrent()
        {
            return  *Ptr();
        }


        /// <summary>
        /// Sets the current ambient container
        /// </summary>
        static void SetLocatorProvider(IServiceLocatorAdapter* newProvider)
        {
            (*Ptr()).reset(newProvider);
        }


        /// <summary>
        /// Sets the current ambient container
        /// </summary>
        static void SetLocatorProvider(COMPONENT<IServiceLocatorAdapter> newProvider)
        {
            
            swap(*Ptr(), newProvider);
        }

        /// <summary>
        /// The current ambient container.
        /// </summary>
        static COMPONENT<IServiceLocatorAdapter>* Ptr()
        {
            // This is a little hack to get around that fact that we only
            // want header files in th source.
            static COMPONENT<IServiceLocatorAdapter> s_serviceLocator;
            return  &s_serviceLocator;
        }
    };

   
}
END_NAMEPSACE__LOK8ER

#endif
