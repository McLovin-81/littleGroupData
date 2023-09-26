#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config
{
    std::string url;
    std::string subscribeMsg;
}

#endif // CONFIG_H



/*
INCLUDE GUARDS ensure that compiler will process this file only once,
no matter how many times it is INCLUDED.
Included guards are just series of preprocessor directives that
guarantees file will only be included one.

Preprocessors used:

    #ifndef:    If not defined, determines if provided macros does not exist.
    #define:    Defines the macros.
    
    ...
    
    #endif:     Close off #ifndef directive.

The block of statements between #ifndef and #endif will be
executed only if the macro or the identifier with #ifndef is NOT
defined.*/