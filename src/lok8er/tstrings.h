#ifndef D_76F5F243_DFE5_4794_97AD_CCD9B49F5487__h
#define D_76F5F243_DFE5_4794_97AD_CCD9B49F5487__h

#include <string>

#ifdef SUPPORT_WIDE_CHAR
#include <xstring>
#endif

START_NAMEPSACE__LOK8ER__PLATFROMS
{

    class tstrings
    {

    public:


// If we are supporting both
#ifdef SUPPORT_NARROW_CHAR

        /// <summary>
        /// Converts a wide string to a narrow string
        /// </summary>
        /// <param name="wide">The wide.</param>
        /// <returns>a narrow string</returns>
        static std::string ToNarrowString(const std::wstring& wide)
        {
            size_t numberOfChars = wide.length() + 1;
            size_t bufferSize = numberOfChars * sizeof(char);
            char*  pCharBuffer = new char[numberOfChars];

            wcstombs_s(NULL_PTR, pCharBuffer, bufferSize, wide.c_str(), _TRUNCATE);
            std::string narrowString = std::string(pCharBuffer);
            delete[] pCharBuffer;
            return narrowString;
        }


#endif

#ifdef SUPPORT_WIDE_CHAR

        /// <summary>
        /// Converts a wide string to a wide string
        /// </summary>
        /// <param name="wide">The wide.</param>
        /// <returns>a narrow string</returns>
        static std::wstring ToWideString(const std::string& narrowString)
        {
            size_t numberOfChars = narrowString.length() + 1;
            wchar_t * pCharBuffer = new wchar_t[numberOfChars];

            mbstowcs_s(NULL_PTR, pCharBuffer, numberOfChars, narrowString.c_str(), _TRUNCATE);
            std::wstring wideString = std::wstring(pCharBuffer);
            delete[] pCharBuffer;
            return wideString;
        }


#endif

    };
}
END_NAMEPSACE__LOK8ER__PLATFROMS

#endif