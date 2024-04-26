#include "cwapi3d_spdlog_wrapper.h"

std::unordered_map<std::string, std::shared_ptr<SpdlogWrapper>> SpdlogWrapper::instances;
std::mutex SpdlogWrapper::mtx;

std::shared_ptr<SpdlogWrapper> SpdlogWrapper::createInstance()
{
  return std::shared_ptr<SpdlogWrapper>(new SpdlogWrapper());
}

SpdlogWrapper& SpdlogWrapper::getInstance(const std::string& loggerName, const std::string& fileName)
{
  std::lock_guard<std::mutex> lock(mtx);
  auto it = instances.find(loggerName);
  if (it == instances.end())
  {
    std::tie(it, std::ignore) = instances.emplace(loggerName, createInstance());
  }
  it->second->init(loggerName, fileName);

  return *(it->second);
}

void SpdlogWrapper::init(const std::string& loggerName, const std::string& fileName)
{
  logger = spdlog::basic_logger_mt(loggerName, fileName);
  logger->set_level(spdlog::level::trace);
}

void SpdlogWrapper::setPattern(const std::string& pattern) const
{
  logger->set_pattern(pattern);
}

void SpdlogWrapper::info(const std::string& msg) const
{
  logger->info(msg);
}

void SpdlogWrapper::error(const std::string& msg) const
{
  logger->error(msg);
}