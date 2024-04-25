//
// Created by MichaelBrunner on 25/04/2024.
//

#ifndef SPDLOGWRAPPER_H
#define SPDLOGWRAPPER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

class SpdlogWrapper
{
public:
  ~SpdlogWrapper() = default;

  SpdlogWrapper(const SpdlogWrapper&) = delete;

  SpdlogWrapper& operator=(const SpdlogWrapper&) = delete;

  static SpdlogWrapper& getInstance();

  void init(const std::string& loggerName, const std::string& fileName);

  void setPattern(const std::string& pattern) const;

  void info(const std::string& msg) const;

  void error(const std::string& msg) const;

private:
  std::shared_ptr<spdlog::logger> logger;

  SpdlogWrapper() {}
};

#endif //SPDLOGWRAPPER_H
