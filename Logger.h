//
// Created by MichaelBrunner on 12/04/2024.
//


#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>

class LoggerInterface {
public:
    virtual ~LoggerInterface() = default;

    void log(const std::string &message) {
        do_log(message);
    }

private:
    virtual void do_log(const std::string &message) = 0;

};

//template<typename... Args>
//void log(Args... args) {
//    file << getCurrentTime() << ": ";
//    ((file << args << " "), ...);
//    file << "\n";
//}


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
    explicit Logger(const std::string &fileName, std::ios_base::openmode mode) {
        file.open(fileName, mode); // std::ios::app | std::ios::out
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

    void do_log(const std::string &message) override {
        file << getCurrentTime() << ": " << message << "\n";
    }
};

LoggerInterface *instance = nullptr;

LoggerInterface *getLogger() {
    static auto init = []() {
        if (!instance)
            instance = new Logger("log.txt", std::ios::out | std::ios::trunc);
        return true;
    }();
    return instance;
}