#pragma once

#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

#include <iostream>
#include <iomanip>

class LoggerInterface {
public:
    virtual ~LoggerInterface() = default;

    void log(const std::string &message) {
        do_log(message);
    }

private:
    virtual void do_log(const std::string &message) = 0;
};

extern LoggerInterface *instance;

LoggerInterface *getLogger(std::string const &aFileName = "log.txt");