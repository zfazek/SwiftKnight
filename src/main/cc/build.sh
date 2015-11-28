#!/bin/sh

g++ -std=c++11 \
    response.cc \
    table.cc \
    -lcgicc \
    -o response.cgi && \
    sudo cp response.cgi /usr/lib/cgi-bin/response.cgi
