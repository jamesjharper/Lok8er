#ifndef D_FCD6B545_767E_48CA_A381_E59876EECE99__h
#define D_FCD6B545_767E_48CA_A381_E59876EECE99__h

// Allow integrators to override namespaces 
#ifndef LOK8ER_NAMESPACES
#define LOK8ER_NAMESPACES

// lok8er
#define LOK8ER                                  lok8er
#define USING_NAMEPSACE__LOK8ER                 using namespace lok8er;
#define START_NAMEPSACE__LOK8ER                 namespace lok8er
#define END_NAMEPSACE__LOK8ER


// lok8er -> Composition
#define LOK8ER__COMPOSITION                     lok8er::Composition
#define USING_NAMEPSACE__LOK8ER__COMPOSITION    using namespace lok8er::Composition;
#define START_NAMEPSACE__LOK8ER__COMPOSITION    namespace lok8er { namespace Composition
#define END_NAMEPSACE__LOK8ER__COMPOSITION      }


// lok8er -> Platforms
#define LOK8ER__PLATFROMS                       lok8er::Platforms
#define USING_NAMEPSACE__LOK8ER__PLATFROMS      using namespace lok8er::Platforms;
#define START_NAMEPSACE__LOK8ER__PLATFROMS      namespace lok8er { namespace Platforms
#define END_NAMEPSACE__LOK8ER__PLATFROMS        }


// lok8er -> Errors
#define LOK8ER__ERRORS                          lok8er::Errors
#define USING_NAMEPSACE__LOK8ER__ERRORS         using namespace lok8er::Errors;
#define START_NAMEPSACE__LOK8ER__ERRORS         namespace lok8er { namespace Errors
#define END_NAMEPSACE__LOK8ER__ERRORS           }

#endif
#endif