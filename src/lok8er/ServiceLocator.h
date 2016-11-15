#ifndef D_A4D7B5DF_A14C_4D15_ADF3_BDC6B2AED076__h
#define D_A4D7B5DF_A14C_4D15_ADF3_BDC6B2AED076__h


START_NAMEPSACE__LOK8ER
{
    class ServiceLocator : public ServiceLocatorBase<LOK8ER__COMPOSITION::ServiceProviderAdapter>
    {
    };

    inline extern void Initalize()
    {
        ServiceLocator::SetLocatorProvider(new LOK8ER__COMPOSITION::ServiceProviderAdapter());
    }
}
END_NAMEPSACE__LOK8ER

#endif
