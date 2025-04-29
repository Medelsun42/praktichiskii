#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>

class Patient {
private:
    std::string id;
    std::string name;
    std::string dob;
    std::string bloodType;
    std::vector<std::string> allergies;

public:
    Patient(std::string id, std::string name, std::string dob, std::string bloodType)
        : id(id), name(name), dob(dob), bloodType(bloodType) {
    }

    void addAllergy(const std::string& allergy) {
        allergies.push_back(allergy);
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getMedicalInfo() const {
        std::string info = "Blood Type: " + bloodType + "\nAllergies: ";
        for (const auto& a : allergies) info += a + ", ";
        return info;
    }

    void display() const {
        std::cout << "Patient: " << name << " (ID: " << id << ")\n";
        std::cout << getMedicalInfo() << "\n";
    }
};

class Doctor {
private:
    std::string id;
    std::string name;
    std::string specialization;
    std::string licenseNumber;

public:
    Doctor(std::string id, std::string name, std::string spec, std::string license)
        : id(id), name(name), specialization(spec), licenseNumber(license) {
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }

    void display() const {
        std::cout << "Dr. " << name << " (" << specialization
            << "), License: " << licenseNumber << "\n";
    }
};

class Appointment {
private:
    std::string id;
    Patient* patient;
    Doctor* doctor;
    std::string dateTime;
    std::string purpose;
    bool completed;

public:
    Appointment(std::string id, Patient* p, Doctor* d, std::string dt, std::string purpose)
        : id(id), patient(p), doctor(d), dateTime(dt), purpose(purpose), completed(false) {
    }

    void completeAppointment() { completed = true; }

    // Getters
    std::string getId() const { return id; }
    Patient* getPatient() const { return patient; }
    Doctor* getDoctor() const { return doctor; }
    std::string getDateTime() const { return dateTime; }
    bool isCompleted() const { return completed; }

    void display() const {
        std::cout << "Appointment ID: " << id << "\n";
        std::cout << "Patient: " << patient->getName() << "\n";
        std::cout << "Doctor: "; doctor->display();
        std::cout << "Time: " << dateTime << "\n";
        std::cout << "Purpose: " << purpose << "\n";
        std::cout << "Status: " << (completed ? "Completed" : "Scheduled") << "\n";
    }
};

class MedicalRecord {
private:
    std::string id;
    Patient* patient;
    Doctor* doctor;
    std::string diagnosis;
    std::string treatment;
    std::string date;

public:
    MedicalRecord(std::string id, Patient* p, Doctor* d, std::string diag, std::string treat, std::string date)
        : id(id), patient(p), doctor(d), diagnosis(diag), treatment(treat), date(date) {
    }

    // Getters
    std::string getDiagnosis() const { return diagnosis; }
    std::string getTreatment() const { return treatment; }

    void display() const {
        std::cout << "Medical Record ID: " << id << " (" << date << ")\n";
        patient->display();
        std::cout << "Diagnosis: " << diagnosis << "\n";
        std::cout << "Treatment: " << treatment << "\n";
    }
};

class Prescription {
private:
    std::string id;
    Patient* patient;
    Doctor* doctor;
    std::vector<std::pair<std::string, std::string>> medications; // name, instructions
    std::string date;
    bool filled;

public:
    Prescription(std::string id, Patient* p, Doctor* d, std::string date)
        : id(id), patient(p), doctor(d), date(date), filled(false) {
    }

    void addMedication(const std::string& med, const std::string& instructions) {
        medications.emplace_back(med, instructions);
    }

    void markAsFilled() { filled = true; }

    void display() const {
        std::cout << "Prescription ID: " << id << " (" << date << ")\n";
        patient->display();
        std::cout << "Medications:\n";
        for (const auto& med : medications) {
            std::cout << "- " << med.first << ": " << med.second << "\n";
        }
        std::cout << "Status: " << (filled ? "Filled" : "Pending") << "\n";
    }
};

class Billing {
private:
    std::string id;
    Patient* patient;
    double amount;
    std::string service;
    std::string date;
    bool paid;

public:
    Billing(std::string id, Patient* p, double amt, std::string svc, std::string date)
        : id(id), patient(p), amount(amt), service(svc), date(date), paid(false) {
    }

    void processPayment() { paid = true; }

    void display() const {
        std::cout << "Bill ID: " << id << " (" << date << ")\n";
        std::cout << "Patient: " << patient->getName() << "\n";
        std::cout << "Service: " << service << "\n";
        std::cout << "Amount: $" << std::fixed << std::setprecision(2) << amount << "\n";
        std::cout << "Status: " << (paid ? "Paid" : "Unpaid") << "\n";
    }
};

class HospitalSystem {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;
    std::vector<MedicalRecord> records;
    std::vector<Prescription> prescriptions;
    std::vector<Billing> bills;

public:
    // Patient management
    void addPatient(const Patient& p) { patients.push_back(p); }
    Patient* findPatient(const std::string& id) {
        for (auto& p : patients) if (p.getId() == id) return &p;
        return nullptr;
    }

    // Doctor management
    void addDoctor(const Doctor& d) { doctors.push_back(d); }
    Doctor* findDoctor(const std::string& id) {
        for (auto& d : doctors) if (d.getId() == id) return &d;
        return nullptr;
    }

    // Appointment scheduling
    bool scheduleAppointment(const std::string& pid, const std::string& did,
        const std::string& dt, const std::string& purpose) {
        Patient* p = findPatient(pid);
        Doctor* d = findDoctor(did);
        if (!p || !d) return false;

        std::string apptId = "APP-" + (appointments.size() + 1);
        appointments.emplace_back(apptId, p, d, dt, purpose);
        return true;
    }

    // Medical records
    void addMedicalRecord(const std::string& pid, const std::string& did,
        const std::string& diag, const std::string& treat, const std::string& date) {
        Patient* p = findPatient(pid);
        Doctor* d = findDoctor(did);
        if (!p || !d) return;

        std::string recId = "REC-" + (records.size() + 1);
        records.emplace_back(recId, p, d, diag, treat, date);
    }

    // Display functions
    void displayPatientHistory(const std::string& pid) {
        Patient* p = findPatient(pid);
        if (!p) return;

        std::cout << "\n=== Medical History for " << p->getName() << " ===\n";

        // Appointments
        std::cout << "\nAppointments:\n";
        for (const auto& app : appointments) {
            if (app.getPatient() == p) app.display();
        }
    }
};

int main() {
    HospitalSystem hospital;

    // Add sample data
    hospital.addPatient(Patient("P001", "John Smith", "1980-05-15", "O+"));
    hospital.addPatient(Patient("P002", "Emily Johnson", "1992-11-22", "A-"));

    hospital.addDoctor(Doctor("D001", "Sarah Williams", "Cardiology", "MD12345"));
    hospital.addDoctor(Doctor("D002", "Michael Brown", "Neurology", "MD67890"));

    // Schedule appointments
    hospital.scheduleAppointment("P001", "D001", "2023-04-15 10:00", "Annual checkup");
    hospital.scheduleAppointment("P002", "D002", "2023-04-16 14:30", "Headache consultation");

    // Add medical records
    hospital.addMedicalRecord("P001", "D001", "Hypertension", "Lisinopril 10mg daily", "2023-04-15");

    // Display patient history
    hospital.displayPatientHistory("P001");

    return 0;
}