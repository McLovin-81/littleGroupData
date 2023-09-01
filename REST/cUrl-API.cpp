#include <iostream>
#include <curl/curl.h>

// Callback function to process received data.
static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) 
{
    size_t totalSize = size * nmemb;
    std::string *output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main()
{
    // A pointer to a cURL handle. This is used to initialize and perform cURL requests.
    CURL *curl;
    // Store the return code of cURL requests.
    CURLcode res;
    // Store the response from the API.
    std::string apiResponse;
    // Initialize cURL.
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize a cURL handle.
    curl = curl_easy_init();

    if (!curl)
    {
        // Handle cURL initialization failure
        std::cerr << "cURL initialization failed." << std::endl;
        return 1;
    }

    // Set the URL to request
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.bitfinex.com/v1/trades/btcusd");
    // Set the callback function for writing received data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    // Set the output string for the callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &apiResponse);

    // Perform the cURL request
    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
    }

    // Clean up cURL resources
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    // Print the API response
    std::cout << apiResponse << std::endl;

    return 0;
}

// Build command
// g++ main.cpp -o main -l curl
