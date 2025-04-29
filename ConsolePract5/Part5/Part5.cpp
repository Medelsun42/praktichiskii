#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class UserStory {
private:
    std::string id;
    std::string description;
    int storyPoints;
    std::string status; // "To Do", "In Progress", "Done"

public:
    UserStory(std::string id, std::string desc, int points)
        : id(id), description(desc), storyPoints(points), status("To Do") {
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }

    // Getters
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    int getStoryPoints() const { return storyPoints; }
    std::string getStatus() const { return status; }
};

class Task {
private:
    std::string id;
    std::string description;
    std::string userStoryId;
    std::string assignee;
    std::string status;

public:
    Task(std::string id, std::string desc, std::string storyId)
        : id(id), description(desc), userStoryId(storyId), status("To Do") {
    }

    void assignTo(const std::string& teamMember) {
        assignee = teamMember;
        status = "Assigned";
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }

    // Getters
    std::string getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getUserStoryId() const { return userStoryId; }
    std::string getAssignee() const { return assignee; }
    std::string getStatus() const { return status; }
};

class TeamMember {
private:
    std::string id;
    std::string name;
    std::string role;

public:
    TeamMember(std::string id, std::string name, std::string role)
        : id(id), name(name), role(role) {
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getRole() const { return role; }
};

class Sprint {
private:
    std::string id;
    std::string name;
    std::string startDate;
    std::string endDate;
    std::vector<std::string> userStories;

public:
    Sprint(std::string id, std::string name, std::string start, std::string end)
        : id(id), name(name), startDate(start), endDate(end) {
    }

    void addUserStory(const std::string& storyId) {
        userStories.push_back(storyId);
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getStartDate() const { return startDate; }
    std::string getEndDate() const { return endDate; }
    const std::vector<std::string>& getUserStories() const { return userStories; }
};

class Backlog {
private:
    std::vector<UserStory> userStories;
    std::vector<Task> tasks;

public:
    void addUserStory(const UserStory& story) {
        userStories.push_back(story);
    }

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    // Other backlog management methods...
};

class BurndownChart {
private:
    std::string sprintId;
    std::map<std::string, int> remainingWork; // date -> remaining story points

public:
    BurndownChart(std::string sprintId) : sprintId(sprintId) {}

    void updateChart(const std::string& date, int remainingPoints) {
        remainingWork[date] = remainingPoints;
    }

    void display() const {
        std::cout << "Burndown Chart for Sprint " << sprintId << ":\n";
        for (const auto& entry : remainingWork) {
            std::cout << entry.first << ": " << entry.second << " points remaining\n";
        }
    }
};

class AgileProject {
private:
    Backlog backlog;
    std::vector<Sprint> sprints;
    std::vector<TeamMember> team;

public:
    void planSprint(const Sprint& sprint) {
        sprints.push_back(sprint);
    }

    void addTeamMember(const TeamMember& member) {
        team.push_back(member);
    }

    // Other project management methods...
};

int main() {
    AgileProject project;

    // Create team
    project.addTeamMember(TeamMember("001", "Alice", "Developer"));
    project.addTeamMember(TeamMember("002", "Bob", "Scrum Master"));

    // Create backlog
    Backlog backlog;
    backlog.addUserStory(UserStory("US1", "Implement user login", 5));
    backlog.addUserStory(UserStory("US2", "Create dashboard", 8));

    // Plan sprint
    Sprint sprint("S1", "Sprint 1", "2023-01-01", "2023-01-14");
    sprint.addUserStory("US1");

    // Create tasks
    Task task1("T1", "Design login page", "US1");
    Task task2("T2", "Implement authentication", "US1");

    // Assign tasks
    task1.assignTo("001");
    task2.assignTo("001");

    // Update status
    task1.updateStatus("In Progress");

    // Burndown chart
    BurndownChart chart("S1");
    chart.updateChart("2023-01-01", 5);
    chart.updateChart("2023-01-07", 3);
    chart.updateChart("2023-01-14", 0);
    chart.display();

    return 0;
}