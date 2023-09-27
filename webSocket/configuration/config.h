#ifndef CONFIG_H
#define CONFIG_H

#include "../parser/simdjson.h"
#include "../parser/simdjson.cpp"


struct Config
{
    std::string url;
    std::string subscriptionMessage;

    Config(std::string config_path)
    {
        simdjson::dom::parser parser;
        simdjson::dom::element configFile = parser.load(config_path);

        url = configFile["url"];
        subscriptionMessage = simdjson::to_string(configFile["subscriptionMessage"]);
    }
};

#endif // CONFIG_H
