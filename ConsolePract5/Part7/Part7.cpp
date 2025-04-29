#include <iostream>
#include <vector>
#include <map>

class ExternalAPI {
private:
    std::string name;
    std::string baseUrl;
    std::string authToken;
    std::map<std::string, std::string> endpoints;

public:
    ExternalAPI(std::string name, std::string url, std::string token)
        : name(name), baseUrl(url), authToken(token) {
    }

    void addEndpoint(const std::string& key, const std::string& path) {
        endpoints[key] = path;
    }

    std::string callAPI(const std::string& endpoint, const std::string& params = "") {
        // This is a simplified version - real implementation would use libcurl
        std::string fullUrl = baseUrl + endpoints[endpoint] + "?" + params;
        std::cout << "Calling API: " << fullUrl << "\n";
        // Simulated response
        return "{\"status\":\"success\",\"data\":\"sample response\"}";
    }

    void setAuthToken(const std::string& token) { authToken = token; }
};

class Project {
private:
    std::string id;
    std::string name;
    std::vector<ExternalAPI*> integrations;

public:
    Project(std::string id, std::string name) : id(id), name(name) {}

    void addIntegration(ExternalAPI* api) { integrations.push_back(api); }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
};

class Notification {
private:
    std::string type;
    std::string recipient;
    std::string message;
    time_t timestamp;
    bool sent;

public:
    Notification(std::string type, std::string recip, std::string msg)
        : type(type), recipient(recip), message(msg), sent(false) {
        timestamp = time(0);
    }

    void send() {
        // In real implementation, this would send email/SMS/webhook
        std::cout << "Sending " << type << " notification to " << recipient
            << ": " << message << "\n";
        sent = true;
    }

    // Getters
    std::string getStatus() const {
        return sent ? "Delivered at " + std::string(ctime(&timestamp))
            : "Pending";
    }
};

class ProjectManagementSystem {
private:
    std::vector<Project> projects;
    std::vector<ExternalAPI> apis;
    std::vector<Notification> notifications;

public:
    void addProject(const Project& p) { projects.push_back(p); }
    void addAPI(const ExternalAPI& api) { apis.push_back(api); }

    void addNotification(const Notification& n) {
        notifications.push_back(n);
        notifications.back().send();
    }

    void generateReport(const std::string& projectId) {
        std::cout << "\n=== Project Report ===\n";
        for (auto& proj : projects) {
            if (proj.getId() == projectId) {
                std::cout << "Project: " << proj.getName() << "\n";
                std::cout << "Integrated APIs:\n";
                
                return;
            }
        }
        std::cout << "Project not found\n";
    }
};

int main() {
    ProjectManagementSystem pms;

    // Configure APIs
    ExternalAPI jira("Jira", "https://api.jira.com", "token123");
    jira.addEndpoint("tasks", "/rest/api/2/task");
    pms.addAPI(jira);

    ExternalAPI slack("Slack", "https://slack.com/api", "xoxb-token");
    slack.addEndpoint("message", "/chat.postMessage");
    pms.addAPI(slack);

    // Create project
    Project webApp("P001", "Website Redesign");
    pms.addProject(webApp);

    // Send notification
    pms.addNotification(Notification("email", "team@company.com",
        "New task assigned in project P001"));

    // Generate report
    pms.generateReport("P001");

    return 0;
}