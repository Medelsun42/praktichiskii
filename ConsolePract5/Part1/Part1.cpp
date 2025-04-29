// Part1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <ctime>

using namespace std;

// Класс Permission (разрешение)
class Permission {
private:
    string name;
    string description;
public:
    Permission(const string& n, const string& d) : name(n), description(d) {}
    string getName() const { return name; }
    string getDescription() const { return description; }
};

// Класс Role (роль)
class Role {
private:
    string name;
    set<Permission*> permissions;
public:
    Role(const string& n) : name(n) {}

    void addPermission(Permission* perm) {
        permissions.insert(perm);
    }

    bool hasPermission(const string& permName) const {
        for (const auto& perm : permissions) {
            if (perm->getName() == permName) {
                return true;
            }
        }
        return false;
    }

    string getName() const { return name; }
};

// Класс User (пользователь)
class User {
private:
    string username;
    string email;
    Role* role;
public:
    User(const string& uname, const string& em, Role* r)
        : username(uname), email(em), role(r) {
    }

    bool hasPermission(const string& permName) const {
        return role->hasPermission(permName);
    }

    string getUsername() const { return username; }
    string getEmail() const { return email; }
    Role* getRole() const { return role; }
};

// Класс Comment (комментарий)
class Comment {
private:
    User* author;
    string content;
    time_t timestamp;
public:
    Comment(User* a, const string& c)
        : author(a), content(c), timestamp(time(nullptr)) {
    }

    User* getAuthor() const { return author; }
    string getContent() const { return content; }
    time_t getTimestamp() const { return timestamp; }
};

// Класс Task (задача)
class Task {
private:
    string title;
    string description;
    User* assignee;
    vector<Comment*> comments;
    bool completed;
public:
    Task(const string& t, const string& d, User* a)
        : title(t), description(d), assignee(a), completed(false) {
    }

    void addComment(Comment* comment) {
        comments.push_back(comment);
    }

    void complete() { completed = true; }

    string getTitle() const { return title; }
    string getDescription() const { return description; }
    User* getAssignee() const { return assignee; }
    const vector<Comment*>& getComments() const { return comments; }
    bool isCompleted() const { return completed; }
};

// Класс Project (проект)
class Project {
private:
    string name;
    string description;
    User* manager;
    vector<Task*> tasks;
    vector<User*> members;
    vector<Comment*> comments;
public:
    Project(const string& n, const string& d, User* m)
        : name(n), description(d), manager(m) {
    }

    void addTask(Task* task) {
        tasks.push_back(task);
    }

    void addMember(User* user) {
        members.push_back(user);
    }

    void addComment(Comment* comment) {
        comments.push_back(comment);
    }

    string getName() const { return name; }
    string getDescription() const { return description; }
    User* getManager() const { return manager; }
    const vector<Task*>& getTasks() const { return tasks; }
    const vector<User*>& getMembers() const { return members; }
    const vector<Comment*>& getComments() const { return comments; }
};

// Класс NotificationService (сервис уведомлений)
class NotificationService {
private:
    map<User*, vector<string>> notifications;
public:
    void notify(User* user, const string& message) {
        notifications[user].push_back(message);
    }

    vector<string> getNotifications(User* user) const {
        auto it = notifications.find(user);
        if (it != notifications.end()) {
            return it->second;
        }
        return {};
    }
};

int main() {
    // Создаем разрешения
    Permission* createTask = new Permission("create_task", "Create new tasks");
    Permission* editTask = new Permission("edit_task", "Edit existing tasks");
    Permission* deleteTask = new Permission("delete_task", "Delete tasks");
    Permission* manageProject = new Permission("manage_project", "Manage project settings");

    // Создаем роли
    Role* adminRole = new Role("Administrator");
    adminRole->addPermission(createTask);
    adminRole->addPermission(editTask);
    adminRole->addPermission(deleteTask);
    adminRole->addPermission(manageProject);

    Role* managerRole = new Role("Manager");
    managerRole->addPermission(createTask);
    managerRole->addPermission(editTask);
    managerRole->addPermission(manageProject);

    Role* developerRole = new Role("Developer");
    developerRole->addPermission(editTask);

    // Создаем пользователей
    User* admin = new User("admin", "admin@company.com", adminRole);
    User* manager = new User("manager", "manager@company.com", managerRole);
    User* developer = new User("dev", "dev@company.com", developerRole);

    // Создаем проект
    Project* project = new Project("New Website", "Development of company website", manager);
    project->addMember(admin);
    project->addMember(manager);
    project->addMember(developer);

    // Создаем задачу
    Task* task = new Task("Design homepage", "Create homepage layout", developer);
    project->addTask(task);

    // Добавляем комментарии
    Comment* comment1 = new Comment(manager, "Please prioritize this task");
    task->addComment(comment1);

    Comment* comment2 = new Comment(developer, "Working on it");
    task->addComment(comment2);

    // Сервис уведомлений
    NotificationService notifications;
    notifications.notify(developer, "New comment on task 'Design homepage'");
    notifications.notify(manager, "Your comment was replied to");

    // Проверка прав доступа
    cout << "Can manager delete tasks? "
        << (manager->hasPermission("delete_task") ? "Yes" : "No") << endl;
    cout << "Can developer manage project? "
        << (developer->hasPermission("manage_project") ? "Yes" : "No") << endl;

    // Очистка памяти (в реальном приложении лучше использовать умные указатели)
    delete createTask;
    delete editTask;
    delete deleteTask;
    delete manageProject;
    delete adminRole;
    delete managerRole;
    delete developerRole;
    delete admin;
    delete manager;
    delete developer;
    delete project;
    delete task;
    delete comment1;
    delete comment2;

    return 0;
}