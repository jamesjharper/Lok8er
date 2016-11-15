#ifndef D_DCC79B25_C763_4EEA_BF4E_877EC12E2BF6__h
#define D_DCC79B25_C763_4EEA_BF4E_877EC12E2BF6__h

#include <typeinfo>

START_NAMEPSACE__LOK8ER__ERRORS
{

    class ActivationException : public std::exception
    {

        /// <summary>
        /// The type which caused the exception
        /// </summary>
        const type_info& _activationType;

    public:

        /// <summary>
        /// Initializes a new instance of the <see cref="ActivationException"/> class.
        /// </summary>
        /// <param name="Params">The parameters of the base exception type .</param>
        /// <param name="ExceptionType">The throwing type of the Exception".</param>
        explicit ActivationException(const char *const message, const type_info& activationType) : 
            exception(message),
            _activationType(activationType)
        {
            
        }

        const type_info& ActivationType()
        {
            return _activationType;
        }
    };
}
END_NAMEPSACE__LOK8ER__ERRORS
#endif
