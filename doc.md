## Project Goals:

The primary objectives of this project are as follows:

  1. **Efficient Data Flow Integration:** Establish a seamless and efficient data flow mechanism between multiple trading platforms.

  2. **Data Forwarding:** Develop a program capable of forwarding data streams from these trading platforms.

  3. **Data Consolidation:** Implement a data consolidation process to merge and organize incoming data streams.

  4. **Data Parsing:** Standardize and parse the consolidated data into a uniform format.

  5. **Multi-Client Data Distribution:** Transmit the formatted data simultaneously to multiple clients or recipients.

By achieving these goals, our project aims to streamline data communication in a complex trading environment, ensuring data consistency and accessibility across various platforms.


## Utilized Technologies

The Data Flow Project leverages a range of technologies to achieve its objectives effectively. These technologies include:

  1. **Visual Studio Code (VSCode):** We chose VSCode as our integrated development environment (IDE) for its versatility and robust feature set.

  2. **C++ Programming Language:** C++ serves as the core programming language for this project. It allows us to create high-performance, low-latency applications, which are crucial for real-time data flow in the trading environment.

  3. **Bash Scripting:** We employ Bash scripting to automate various tasks within the project. This includes tasks such as compiling and running components, simplifying routine processes, and enhancing overall project efficiency.

  4. **Open-Source C++ Libraries:** Our project harnesses the capabilities of multiple open-source C++ libraries to expedite development and enhance functionality. These libraries provide ready-made solutions for WebSocket communication and other key components, reducing development time and ensuring reliability.
  
  5. **Git**
  
  6. **GitHub**

By combining these technologies, we create a robust and efficient ecosystem for managing WebSocket data flow, forwarding, consolidation, parsing, and multi-client distribution. This technology stack empowers our project to meet its goals effectively and deliver a seamless real-time data experience in the trading industry.



**22.08.2023**
- First session with Tim.
  - Mock-up about the data flow.
  - Ideas about data flow.
  - Potential problems.

**23.08.2023**
- Second session with Tim.
  - Introduction of https://www.piesocket.com/websocket-tester -> WebSocket client
  - Research about possible trading platforms with open websockets

  **Learning**
  - How can I code a WebSocket using C++.
  - First steps trying from scratch.
  - Try "asio" library.
  - Try "WebSocketpp" library.
  - I figured out that the `-l pthread` flag is needed to compile with the WebSocketpp library.

**29.08.2023**
- Code review with Ansgar.
- Pair programming with Ansgar.

**30.08.2023**
- Code refactoring.
- Pair programming with Tim.

**Session about REST API with Tim**
- `curl -v https://api.bitfinex.com/v1/symbols_details or `curl -v https://api.bitfinex.com/v1/trades/btcusd
- Every list has a trade id. Filter if a trade id was already given.
- After filtering, push the new data to the main file (list).
- Try bash script.
- GET WEBSOCKET USING PYTHON -> USING PROTOBUFF SEND THE DATA TO A C++ CODE?
- Learn how git branches work and apply.

**31.08.2023**
- One more try to run the cURL library.
- Using ChatGPT to get the first data!
- Learning about bash scripts.
- Made a bash script to compile, link the `-lcurl` library, and delete the executable file.

**05.09.2023**
- Research on working with JSON in C++.
- Investigate efficient C++ libraries for creating JSON objects.
- Begin learning about the simdjson library.
- Explore how to parse a std::string into JSON.
- Explore how to parse JSON into a std::string.

**14.09.2023**
- Realize that parsing std::string to JSON may not be necessary.
- Discover that using a JSON-like format is sufficient, achievable through raw (R) strings.
- Implement raw strings in the code, making it work.

**15.09.2023**
- Encounter an issue: the program works on a private MacBook but not on the business laptop.
- Exclude potential causes.
  - Investigate differences in OS, WebSocket++ library version, and DBAG VPN.

**18.09.2023**
- Troubleshooting steps taken:
  - Download WebSocket++ 0.8.2 on the business laptop.
  - Attempt using a new linker.
  - Collaborate with Moritz Sundarp from the Cloud department.
    - Investigate the proxy configuration.
    - Debug WebSocket++ classes and dependencies.
    - No solution found

**19.09.2023**
- Pair programming with Valery Tsarou
  - Investigated the proxy configuration
  - Debugged WebSocket++ classes about proxy
  - Found the void set_proxy() function in the WebSocket++ GitHub repository
- Learned how to implement set_proxy() in my code
- Added the websocketpp/transport/asio/connection.hpp header file to my code
- Implemented the proxy in my code
  - Prgramm works!

**20.09.2023**
- Very unhappy with the WebSocket++ library.
  -The last release was on 19 April 2020.
  -It has 358 issues.
- Looking around for alternatives like the [IXWebSocket](https://github.com/machinezone/IXWebSocket) library.

**21.09.2023**
- The IXWebSocket-library has no possibility to connect over a proxy server.
- No other (better) library found.

- Refactoring
  - Code Structure and Readability
    - In the refactored code, the use of type aliases (`typedef`) makes the code more readable by providing meaningful names for commonly used types.
  - Simplification and Clarity
    - The refactored code simplifies the structure by consolidating functions and removing unnecessary comments, improving overall code clarity.
  - Message Sending and Receiving
    - In the old code, message sending and receiving logic was in separate functions (`on_open` and `on_message`). In the refactored code, these functionalities are moved to `sendMessageOnOpen` and `getMessageOnOpen`, respectively, making it clearer where these operations occur.
  - Proxy Configuration
    - Proxy configuration was done directly in the `set_url` function in the old code. In the refactored code, proxy configuration is moved to a separate variable (`proxy`) for better organization and readability.
  - Logging Configuration
    - In the old code, logging configuration was done in the `turn_off_logging` function. In the refactored code, the same functionality is achieved by explicitly clearing access and error channels.
  - Main Function Structure
    - The structure of the `main` function in the refactored code is simplified. It follows a logical flow: client initialization, configuration, connection establishment, and event loop execution.
  - Initialization Handling
    - TLS initialization handling is improved in the refactored code. The `on_tls_init` function provides a clear context for SSL/TLS setup.
  - Variable Organization
    - Variables like `msg`, `url`, and `proxy` are explicitly defined and initialized before their usage in the refactored code, enhancing code readability.
  - Error Handling
    - Error handling (e.g., checking error codes) is more explicitly handled in the refactored code, which can help diagnose issues more effectively.
  
  - Overall, the refactored code maintains the same functionality but many superfluous functions have been deleted.

**22.09.2023**
- Problem!
  - The code only runs on the business laptop in the DBAG network environment, nowhere else...
  - The proxy server variable is hardcoded and assumed for the connection.

- How can I use the proxy server only when needed?
  - Checking the websocketpp::lib::error_code errorCode.
    - How can I catch an error and react with the proxy information.
    - Debugged WebSocket++ classes about error codes and error return.
    - errorCode.value(), errorCode.message() did not help because the return of these functions does not change after the connection attempt.

**25.09.2023**
- After a pull request (M.L.) I am now using getenv("HTTPS_PROXY") and getenv("HTTP_PROXY").
- Proxy gets from environment variable.
  - "One way to do this is to use environment variables. We can set the proxy to http_proxy or            https_proxy. The solution assumes that the operating system on which the code is running has already set up a proxy".
  - The proxy variable is now set "automatically".
  - std::string https_proxy = getenv("HTTPS_PROXY") will crash with a segmentation fault error if there is no proxy to set.
  - Workaround
    - First check that the return value of getenv() is not NULL.
    - Only if this is true, store the return of getenv() in https_proxy.
    - If there is anything stored in https_proxy or http_proxy, store it in proxy.
    - If the proxy variable is not empty, connect through the proxy. 
- Code works properly on business laptop and home laptop.
- Code presented to Tim Rumrich.

**26.09.2023**
- Stragling to parse the json format subscriptionMessage to std::string- Starting with command line parameter
  - Using a flag at compile time, the code should take certain configuration to connect to a specific site.
- Create a directory -> configuration/ -> config.h config.json
  - config.h
    - Structure
      - URL
      - subscription message
      - readConfig() -> Read configuration information from config.json 
        Using the simdjson library.
  - config.json
    - Easily change the configuration in json format
- Create a directory -> parser/ -> simdjson.cpp simdjson.h
  - The simdjson library files.

**27.09.2023**
- Stragling to parse the json format subscriptionMessage to std::string.
- Using the simdjson::to_string instead of std::to_string to parse json
  to string.
- Program works properly

The project will be on hold for a few weeks.