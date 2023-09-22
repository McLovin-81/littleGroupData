FROM ubuntu:18.04

ARG ARG_HTTP_PROXY
ARG ARG_HTTPS_PROXY
ARG ARG_NO_PROXY

ENV HTTP_PROXY  ${ARG_HTTP_PROXY}
ENV HTTPS_PROXY ${ARG_HTTPS_PROXY}
ENV NO_PROXY    ${ARG_NO_PROXY}
ENV http_proxy  ${ARG_HTTP_PROXY}
ENV https_proxy ${ARG_HTTPS_PROXY}
ENV no_proxy    ${ARG_NO_PROXY}

RUN touch /etc/apt/apt.conf.d/proxy.conf                    && \
    echo "Acquire::http::Proxy \"${ARG_HTTP_PROXY}\";"          \
        >> /etc/apt/apt.conf.d/proxy.conf                   && \
    echo "Acquire::https::Proxy \"${ARG_HTTPS_PROXY}\";"        \
        >> /etc/apt/apt.conf.d/proxy.conf

# Update the package manager and install essential tools
RUN apt-get update              && \
    apt-get install -y             \
        build-essential            \
        cmake                      \
        curl                       \
        libboost-all-dev           \
        libssl-dev              && \
    apt-get clean all           && \
    rm -rf /var/lib/apt/lists/*


# Install websocketpp library
WORKDIR /var/tmp/websocketpp
ENV WEBSOCKETPP_VERSION 0.8.2
RUN curl -LO https://github.com/zaphoyd/websocketpp/\
archive/refs/tags/${WEBSOCKETPP_VERSION}.tar.gz         && \
    tar -xf ${WEBSOCKETPP_VERSION}.tar.gz               && \
    cmake websocketpp-${WEBSOCKETPP_VERSION}            && \
    make -j 16 install 


WORKDIR /app
COPY webSocketClient.cpp .
COPY Makefile .

RUN make build
CMD ["./webSocketClient"]