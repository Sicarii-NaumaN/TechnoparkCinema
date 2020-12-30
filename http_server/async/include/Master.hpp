#pragma once

#include <memory>
#include <vector>
#include <queue>
#include <map>

#include "socket.hpp"
#include "HTTPClient.hpp"
#include "TaskBuilder.hpp"
#include "TasksController.hpp"
#include "Listener.hpp"
#include "Worker.hpp"

class Master {
 protected:
    Socket socket;

    std::vector<Worker> workers;

    std::map<std::string, int> ports;
    std::vector<Listener> listeners;

    std::queue<HTTPClient> unprocessedClients;
    std::shared_ptr<std::mutex> unprocessedClientsMutex;
    std::vector<Task> haveNoData;
    std::shared_ptr<std::mutex> haveNoDataMutex;
    TaskBuilder builder;

    std::queue<Task> haveData;
    std::shared_ptr<std::mutex> haveDataMutex;
    TasksController controller;

    std::map<int, HTTPClient> pendingDBResponse;
    std::shared_ptr<std::mutex> pendingDBResponseMutex;

    bool stop;

 public:
    explicit Master(std::map<std::string, int>& ports,const  size_t &workersAmount = 1);
    virtual ~Master();

    //  static void SetSocket(std::unique_ptr<Socket> socket);
    virtual void Start();
    virtual void Stop();  // Processes all existing connections
};
