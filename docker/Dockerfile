FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive
WORKDIR /root

# preinstall for gtest
RUN apt-get update && \
	apt-get install -y build-essential \
	curl \
	cmake

# gtest install & build
RUN curl -LO https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz && \
	tar -xzf release-1.11.0.tar.gz && \
	rm -rf release-1.11.0.tar.gz && \
	cd googletest-release-1.11.0 && \
	mkdir build && \
	cd build && \
	cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr .. && \
	make && \
	make install