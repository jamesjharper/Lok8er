#ifndef D_FDE00C8F_C382_4893_BC87_CEA9A8555B9E__h
#define D_FDE00C8F_C382_4893_BC87_CEA9A8555B9E__h

#define SUPPORT_NARROW_CHAR

// Add to enable wide instance names
//#define SUPPORT_WIDE_CHAR


#ifndef  NULL_PTR
#define NULL_PTR  0
#endif


#ifndef  COMPONENT
#include <memory>
#define COMPONENT  std::shared_ptr
#endif


#ifndef  WEAK_COMPONENT
#include <memory>
#define WEAK_COMPONENT  std::weak_ptr
#endif

#ifndef  COMPONENT_LIST_TYPE
#include <vector>
#define COMPONENT_LIST_TYPE  std::vector
#endif

START_NAMEPSACE__LOK8ER
{
    template <typename T> using component_ptr = COMPONENT<T>;
    template <typename T> using injected_component_ptr = const component_ptr<T>&;
    template <typename T> using weak_component_ptr = WEAK_COMPONENT<T>;
    template <typename T> using component_list = COMPONENT_LIST_TYPE<COMPONENT<T>>;

}
END_NAMEPSACE__LOK8ER

#ifndef  INJECTED_COMPONENT
#define INJECTED_COMPONENT  LOK8ER::injected_component_ptr
#endif


#ifndef  COMPONENT_LIST
#include <vector>
#define COMPONENT_LIST  LOK8ER::component_list
#endif

// Logging
// By default don't log anything. This can be used
// as an extensibility point for the integrator 

#ifndef  LOK8ER_LOGGING_DEBUG
#define LOK8ER_LOGGING_DEBUG(msg,...)
#endif

#ifndef  LOK8ER_LOGGING_WARN
#define LOK8ER_LOGGING_WARN(msg,...)
#endif

#ifndef  LOK8ER_LOGGING_ERROR
#define LOK8ER_LOGGING_ERROR(msg,...)
#endif

#endif