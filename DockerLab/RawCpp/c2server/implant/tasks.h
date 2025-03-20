
struct PingTask {
  
};

struct

using Task = std::variant<PingTask, ConfigureTask, ExecuteTask, ListThreadsTask>;
