#include <iostream>

#include "configuration/config.h"

const std::string CONFIG_FILEPATH = "configuration/config.json";

int main()
{
    Config config;
    config.readConfig(CONFIG_FILEPATH);
    std::cout << config.url << std::endl;

    return 0;
}

