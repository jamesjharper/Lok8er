#ifndef D_2777FE98_6C9C_4CE0_ABF3_1282BD1CF105__h
#define D_2777FE98_6C9C_4CE0_ABF3_1282BD1CF105__h

START_NAMEPSACE__LOK8ER__COMPOSITION
{
    template<typename TService>
    class IServiceProvider
    {
    public:

        /// <summary>
        /// Get an instance of the given named <typeparamref name="TService"/>.
        /// </summary>
        /// <typeparam name="TService">Type of object requested.</typeparam>
        /// <returns>The requested service instance.</returns>
        virtual COMPONENT<TService> GetInstance() = 0;

        /// <summary>
        /// Finalizes an instance of the <see cref="IServiceProvider"/> class.
        /// </summary>
        virtual ~IServiceProvider() {}

    };
}
END_NAMEPSACE__LOK8ER__COMPOSITION

#endif