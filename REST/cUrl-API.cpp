#include <iostream>
#include <curl/curl.h>

// This callback function will be used to process the received data
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) 
{
    size_t totalSize = size * nmemb;
    std::string *output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main()
{
    CURL *curl;
    CURLcode res;
    std::string apiResponse;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.bitfinex.com/v1/trades/btcusd");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &apiResponse);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    // Print the API response
    std::cout << apiResponse << std::endl;

    return 0;
}

// Build command
// g++ main.cpp -o main -lcurl
