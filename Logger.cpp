//
// Created by MichaelBrunner on 12/04/2024.
//

#include "Logger.h"

#include <utility>

std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm buf{};
    localtime_s(&buf, &in_time_t);
    std::stringstream ss;
    ss << std::put_time(&buf, "%Y-%m-%d %X");
    return ss.str();
}

class Logger : public LoggerInterface {
public:
    explicit Logger(std::string fileName, std::ios_base::openmode mode)
            : fileName(std::move(fileName)), mode(mode) {
    }

    Logger(const Logger &other) = delete;

    Logger &operator=(const Logger &other) = delete;

    Logger(Logger &&other) = delete;

    Logger &operator=(Logger &&other) = delete;

    explicit operator bool() const { return file.is_open(); }

    ~Logger() override {
        if (file.is_open()) { file.close(); }
    }

private:
    std::ofstream file;
    std::string fileName;
    std::ios_base::openmode mode;

    void do_log(const std::string &message) override {
        file.open(fileName, mode);
        file << getCurrentTime() << ": " << message << "\n";
        file.close();
    }
};

LoggerInterface *instance = nullptr;

LoggerInterface *getLogger(std::string const &aFileName) {
    static auto init = [fileName = aFileName]() {
        if (!instance)
            instance = new Logger(fileName, std::ios::out | std::ios::app);
        return true;
    }();
    return instance;
}