Project Goals:

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
    - I figured out that the `-lpthread` flag is needed to compile with the WebSocketpp library.

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


