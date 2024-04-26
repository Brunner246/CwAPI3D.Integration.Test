#ifndef SPDLOGWRAPPER_H
#define SPDLOGWRAPPER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <unordered_map>
#include <mutex>

class SpdlogWrapper
{
public:
  ~SpdlogWrapper() = default;

  SpdlogWrapper(const SpdlogWrapper&) = delete;
  SpdlogWrapper& operator=(const SpdlogWrapper&) = delete;

  static SpdlogWrapper& getInstance(const std::string& loggerName, const std::string& fileName);

  void setPattern(const std::string& pattern) const;

  void setLogLevel(spdlog::level::level_enum level) const;

  void info(const std::string& msg) const;

  void error(const std::string& msg) const;

private:
  std::shared_ptr<spdlog::logger> logger;
  static std::unordered_map<std::string, std::shared_ptr<SpdlogWrapper>> instances;
  static std::mutex mtx;

  SpdlogWrapper() {}
  static std::shared_ptr<SpdlogWrapper> createInstance();
  void init(const std::string& loggerName, const std::string& fileName);
};

#endif //SPDLOGWRAPPER_H