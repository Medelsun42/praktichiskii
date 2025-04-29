#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Venue {
private:
    std::string id;
    std::string name;
    std::string address;
    int capacity;
    std::vector<std::string> amenities;

public:
    Venue(std::string id, std::string name, std::string addr, int cap)
        : id(id), name(name), address(addr), capacity(cap) {
    }

    void addAmenity(const std::string& amenity) {
        amenities.push_back(amenity);
    }

    bool canHost(int attendees) const {
        return attendees <= capacity;
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

    void display() const {
        std::cout << name << " (" << address << ")\n";
        std::cout << "Capacity: " << capacity << "\nAmenities: ";
        for (const auto& a : amenities) std::cout << a << ", ";
        std::cout << "\n";
    }
};

class Participant {
private:
    std::string id;
    std::string name;
    std::string email;
    std::string ticketId;

public:
    Participant(std::string id, std::string name, std::string email)
        : id(id), name(name), email(email) {
    }

    void assignTicket(const std::string& ticket) { ticketId = ticket; }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getTicketId() const { return ticketId; }
};

class Ticket {
private:
    std::string id;
    std::string eventId;
    std::string type;
    double price;
    bool sold;

public:
    Ticket(std::string id, std::string eid, std::string type, double price)
        : id(id), eventId(eid), type(type), price(price), sold(false) {
    }

    void sellTicket() { sold = true; }

    // Getters
    std::string getId() const { return id; }
    std::string getEventId() const { return eventId; }
    std::string getType() const { return type; }
    double getPrice() const { return price; }
    bool isSold() const { return sold; }
};

class Event {
private:
    std::string id;
    std::string name;
    std::string description;
    std::string date;
    Venue* venue;
    std::vector<Ticket> tickets;
    std::vector<std::string> participantIds;

public:
    Event(std::string id, std::string name, std::string desc, std::string date, Venue* venue)
        : id(id), name(name), description(desc), date(date), venue(venue) {
    }

    bool registerParticipant(Participant* p, const std::string& ticketType) {
        auto it = std::find_if(tickets.begin(), tickets.end(),
            [&ticketType](const Ticket& t) {
                return t.getType() == ticketType && !t.isSold();
            });

        if (it != tickets.end()) {
            it->sellTicket();
            p->assignTicket(it->getId());
            participantIds.push_back(p->getId());
            return true;
        }
        return false;
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    Venue* getVenue() const { return venue; }

    void display() const {
        std::cout << "\n=== " << name << " ===\n";
        std::cout << description << "\n";
        std::cout << "Date: " << date << "\n";
        std::cout << "Venue: "; venue->display();
        std::cout << "Tickets:\n";
        for (const auto& t : tickets) {
            std::cout << "- " << t.getType() << ": $" << t.getPrice()
                << " (" << (t.isSold() ? "Sold" : "Available") << ")\n";
        }
    }
};

class EventManagementSystem {
private:
    std::vector<Event> events;
    std::vector<Venue> venues;
    std::vector<Participant> participants;

public:
    void addVenue(const Venue& v) { venues.push_back(v); }
    void addEvent(const Event& e) { events.push_back(e); }
    void addParticipant(const Participant& p) { participants.push_back(p); }

    Venue* findVenue(const std::string& id) {
        for (auto& v : venues) if (v.getId() == id) return &v;
        return nullptr;
    }

    Event* findEvent(const std::string& id) {
        for (auto& e : events) if (e.getId() == id) return &e;
        return nullptr;
    }

    Participant* findParticipant(const std::string& id) {
        for (auto& p : participants) if (p.getId() == id) return &p;
        return nullptr;
    }

    void displayAllEvents() const {
        std::cout << "\n=== All Events ===\n";
        for (const auto& e : events) e.display();
    }
};

int main() {
    EventManagementSystem ems;

    // Add venues
    Venue v1("V001", "Grand Ballroom", "123 Main St", 500);
    v1.addAmenity("Projector");
    v1.addAmenity("Stage");
    ems.addVenue(v1);

    // Create event
    Event conf("E001", "Tech Conference 2023", "Annual technology conference", "2023-05-20", &v1);
    ems.addEvent(conf);

    // Register participants
    Participant p1("P001", "Alice Smith", "alice@example.com");
    Participant p2("P002", "Bob Johnson", "bob@example.com");
    ems.addParticipant(p1);
    ems.addParticipant(p2);

    // Sell tickets
    ems.findEvent("E001")->registerParticipant(ems.findParticipant("P001"), "General Admission");
    ems.findEvent("E001")->registerParticipant(ems.findParticipant("P002"), "VIP");

    // Display events
    ems.displayAllEvents();

    return 0;
}