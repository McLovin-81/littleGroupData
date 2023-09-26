#include <iostream>
#include <string>

#include "config.h"

int main()
{
    Config config;
    config.readConfig();
    std::cout << config.url << std::endl;

    return 0;
}

