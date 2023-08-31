#include <iostream>
#include <curl/curl.h>

// Callback function to process received data
    size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
    {
        size_t totalSize = size * nmemb;
        // Append received data to the output string
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

int main() {
    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();
    if (!curl) {
        // Handle cURL initialization failure
        std::cerr << "cURL initialization failed." << std::endl;
        return 1;
    }

    std::string apiResponse;
    // Set the URL to request
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.bitfinex.com/v1/trades/btcusd");
    // Set the callback function for writing received data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    // Set the output string for the callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &apiResponse);

    // Perform the cURL request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        // Handle cURL request failure
        std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
    }

    // Clean up cURL resources
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    // Print the API response
    std::cout << apiResponse << std::endl;
    return 0;
}
