#include <iostream>
#include <vector>
#include <queue>

class Microservice {
private:
    std::string name;
    std::string version;
    std::vector<std::string> endpoints;
    bool isHealthy;

public:
    Microservice(std::string name, std::string ver)
        : name(name), version(ver), isHealthy(true) {
    }

    void addEndpoint(const std::string& ep) {
        endpoints.push_back(ep);
    }

    void setHealth(bool health) { isHealthy = health; }

    // Getters
    std::string getName() const { return name; }
    bool healthCheck() const { return isHealthy; }
};

class MessageQueue {
private:
    std::queue<std::string> messages;
    std::string name;

public:
    MessageQueue(std::string name) : name(name) {}

    void push(const std::string& msg) {
        messages.push(msg);
    }

    std::string pop() {
        if (messages.empty()) return "";
        std::string msg = messages.front();
        messages.pop();
        return msg;
    }
};

class LoadBalancer {
private:
    std::vector<Microservice*> instances;
    size_t currentIndex;

public:
    LoadBalancer() : currentIndex(0) {}

    void addInstance(Microservice* instance) {
        instances.push_back(instance);
    }

    Microservice* getNextHealthyInstance() {
        if (instances.empty()) return nullptr;

        for (size_t i = 0; i < instances.size(); ++i) {
            currentIndex = (currentIndex + 1) % instances.size();
            if (instances[currentIndex]->healthCheck()) {
                return instances[currentIndex];
            }
        }
        return nullptr;
    }
};

class MicroserviceSystem {
private:
    std::vector<Microservice> services;
    std::vector<MessageQueue> queues;
    LoadBalancer balancer;

public:
    void deployService(const Microservice& service) {
        services.push_back(service);
        balancer.addInstance(&services.back());
    }

    void processRequests() {
        Microservice* instance = balancer.getNextHealthyInstance();
        if (instance) {
            std::cout << "Routing request to: " << instance->getName() << "\n";
        }
        else {
            std::cout << "No healthy instances available\n";
        }
    }
};