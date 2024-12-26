//4. Hospital Resource Allocation
//A hospital management system needs to sort incoming patients in the emergency department based on triage priority,
//severity of condition, and arrival time. The sorted list determines the order in which patients are seen by medical professionals.
//Additionally, during peak times, the system must dynamically adjust the sorting as new patients arrive, ensuring that life-threatening 
//cases are prioritized while maintaining fairness.
#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Patient structure to represent each patient
class Patient {
public:
    std::string name;         // Name of the patient
    int triage_priority;      // Triage priority (lower number means more critical)
    int severity;             // Severity of the condition (1 = most severe, higher numbers = less severe)
    int arrival_time;         // Arrival time (used to maintain fairness)

    // Constructor to initialize patient data
    Patient(std::string n, int tp, int sev, int arrival)
        : name(n), triage_priority(tp), severity(sev), arrival_time(arrival) {}

    // Method to print patient details
    void print() const {
        std::cout << "Name: " << name
                  << ", Triage Priority: " << triage_priority
                  << ", Severity: " << severity
                  << ", Arrival Time: " << arrival_time << std::endl;
    }
};

// Comparator for priority queue to prioritize based on triage and severity
class PatientComparator {
public:
    bool operator()(const Patient& p1, const Patient& p2) {
        // Compare based on triage priority first (lower is higher priority)
        if (p1.triage_priority != p2.triage_priority)
            return p1.triage_priority > p2.triage_priority;

        // If triage priority is the same, compare severity (lower is more severe)
        if (p1.severity != p2.severity)
            return p1.severity > p2.severity;

        // If both triage and severity are the same, compare arrival time (earlier is better)
        return p1.arrival_time > p2.arrival_time;
    }
};

// Function to display the list of patients in order of priority
void displayPatients(std::priority_queue<Patient, std::vector<Patient>, PatientComparator>& pq) {
    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> temp = pq;  // Make a copy for display
    
    std::cout << "Patient List (Sorted by Triage Priority, Severity, Arrival Time):\n";
    while (!temp.empty()) {
        temp.top().print();
        temp.pop();
    }
}

int main() {
    // Priority queue to manage patients based on triage priority and severity
    std::priority_queue<Patient, std::vector<Patient>, PatientComparator> pq;

    // Add some sample patients
    pq.push(Patient("John Doe", 1, 5, 3));  // Most critical, severe condition
    pq.push(Patient("Alice Smith", 3, 2, 1));  // Less critical but severe condition
    pq.push(Patient("Bob Johnson", 2, 3, 2));  // Medium critical, moderate severity
    pq.push(Patient("Carol White", 1, 2, 4));  // Most critical, moderate severity
    pq.push(Patient("David Brown", 4, 1, 5));  // Less critical, least severe

    // Display initial list of patients
    displayPatients(pq);

    // New patient arrives
    std::cout << "\nNew patient arrives:\n";
    pq.push(Patient("Eve Black", 1, 3, 6));  // Critical priority, moderate severity, arrived at time 6

    // Display updated list of patients
    displayPatients(pq);

    return 0;
}

