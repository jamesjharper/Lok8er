
#ifndef D_24C63B62_9AE7_4823_8093_29A2F159732E__h
#define D_24C63B62_9AE7_4823_8093_29A2F159732E__h

/*

Description:
IServiceProvider for creating objects which support constructor
injection. 

For a instance to be created by this service provider
it must have a default constructor.

Examples:

* Classes with no dependencies are simple

new ServiceT(void)  - Is ok!

* Classes with dependencies are almost simple

Dependency injection format:
- is OK! this is good
new DependentService(InjectParam(TService, instanceName))

Expanded macro dependency injection format:
- Do not use this because its very verbose, but it will still work
new DependentService(container_ptr<TService> instanceName = TryInjectInstance<TService>())

Default constructor values format:
- This will work, but do not see any reason to do this
new DependentService(container_ptr<TService> something = NULL)

No default constructor format:
- This will not work and will create a compiler error
new DependentService(container_ptr<TService> somethingNotDefault)

Limitations:

This is a very basic dependency injection implementation. That said I haven't
really found many problems with it.

Note: this service provider WILL NOT detect circular dependencies.

A circular dependency will at runtime result in the process exploding
from a stack overflow or other such epic failings. Its recommended that
you avoid this.


*/

START_NAMEPSACE__LOK8ER__COMPOSITION
{
    template<typename ITService, typename TServiceImpl>
    class DefaultConstructorServiceProvider : public IServiceProvider<ITService>
    {

        /// <summary>
        /// The singleton instance used when life style is "Singleton"
        /// </summary>
        WEAK_COMPONENT<ITService> s_TSingletonInstance;

        /// <summary>
        /// The instance lifestyle
        /// </summary>
        Lifestyle s_lifestyle;

    public:

        /// <summary>
        /// Sets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        explicit DefaultConstructorServiceProvider(Lifestyle lifestyle = Singleton_Lifestyle)
        {
            s_lifestyle = lifestyle;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="DefaultConstructorServiceProvider"/> class.
        /// </summary>
        virtual ~DefaultConstructorServiceProvider() {}

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        virtual COMPONENT<ITService> GetInstance() override
        {
            if (s_lifestyle == Singleton_Lifestyle)
                return GetSingletonInstance();

            if (s_lifestyle == Transient_Lifestyle)
                return GetTransientInstance();

            // Return a Singleton instance if something is very wrong
            LOK8ER_LOGGING_WARN("Warning instance lifestyle used for creating a instance of %s, was not recognized, returning a singleton instance.", typeid(ITService).name());
            return GetSingletonInstance();
        }

    private:

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT<ITService> GetSingletonInstance()
        {
            // Check that the current weak pointer is still active or not
            COMPONENT<ITService> currentInstance = s_TSingletonInstance.lock();

            // If we already have the singleton instance then return it
            if (currentInstance) 
                return currentInstance;

            // Create the instance 
            currentInstance = FactoryInstance();
            s_TSingletonInstance = currentInstance;
            return currentInstance;
        }

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <param name="instance">The instance.</param>
        COMPONENT<ITService> GetTransientInstance()
        {
            return FactoryInstance();
        }

        /// <summary>
        /// Factories the instance.
        /// </summary>
        /// <returns></returns>
        COMPONENT<ITService> FactoryInstance()
        {
            COMPONENT<ITService> instance;
            instance.reset(new TServiceImpl());
            return instance;
        }
    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION
#endif