//
// Created by MichaelBrunner on 25/04/2024.
//

#include "SpdlogWrapper.h"
SpdlogWrapper& SpdlogWrapper::getInstance()
{
  static SpdlogWrapper instance;
  return instance;
}
void SpdlogWrapper::init(const std::string& loggerName, const std::string& fileName)
{
  logger = spdlog::basic_logger_mt(loggerName, fileName);
  spdlog::set_default_logger(logger);
}
void SpdlogWrapper::setPattern(const std::string& pattern) const
{
  logger->set_pattern(pattern);
}
void SpdlogWrapper::info(const std::string& msg) const
{
  SPDLOG_LOGGER_CALL(logger.get(), spdlog::level::info, msg);
}
void SpdlogWrapper::error(const std::string& msg) const
{
  SPDLOG_LOGGER_CALL(logger.get(), spdlog::level::err, msg);
}