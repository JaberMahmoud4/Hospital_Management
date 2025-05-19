#include <iostream> // For input/output operations
#include <string>   // For using the string data type
#include <ctime>    // For generating random numbers based on time
#include <cstdlib>  // For the random number generation functions
using namespace std;

const int MAX_PATIENTS = 50;  // Maximum number of patients the system can handle
const int MAX_DOCTORS = 8;   // Maximum number of doctors in the system

// Structure to store patient details
struct Patient {
    int id;                     // Unique ID for the patient
    string name;                // Name of the patient
    int age;                    // Age of the patient
    string contact;             // Contact information
    string medicalHistory;      // Patient's medical history
    string password;            // Password for secure access to medical records
    string appointmentReminder; // Reminder message for scheduled appointments
};

// Structure to store doctor details
struct Doctor {
    string name;       // Doctor's name
    string specialty;  // Doctor's area of specialty
};

// Function prototypes define the system's functionality
void createPatient(Patient patients[], int &count);                   // Create a new patient record
void updatePatient(Patient patients[], int count);                    // Update an existing patient record
void displayPatients(const Patient patients[], int count);            // Display all patient records
void scheduleAppointment(Patient patients[], int patientCount,        // Schedule an appointment for a patient
                         Doctor doctors[], int doctorCount);
void accessMedicalHistory(Patient patients[], int count);             // Access a patient's medical history securely
void generateBill();                                                  // Generate a billing invoice
void listTests();                                                     // List available medical tests and their prices
void emergency();                                                     // Handle emergency situations (e.g., location sharing)
bool isValidPatientId(int id, int count);                             // Validate if a given patient ID exists
bool isValidAge(int age);                                             // Validate if the entered age is within an acceptable range
void displayAppointmentReminder(Patient patients[], int count);       // Show appointment reminders to patients

int main() {
    srand(time(0));

    // Pre-populated data
    Patient patients[MAX_PATIENTS] = {
        {1, "John Doe", 45, "123-456-7890", "Diabetes", "password1", "No upcoming appointments."},
        {2, "Jane Smith", 30, "234-567-8901", "Hypertension", "password2", "No upcoming appointments."},
        {3, "Alice Johnson", 25, "345-678-9012", "Asthma", "password3", "No upcoming appointments."},
        {4, "Bob Brown", 60, "456-789-0123", "Arthritis", "password4", "No upcoming appointments."},
        {5, "Charlie Wilson", 50, "567-890-1234", "Heart Disease", "password5", "No upcoming appointments."},
        {6, "Diana Green", 35, "678-901-2345", "Migraines", "password6", "No upcoming appointments."},
        {7, "Ethan White", 40, "789-012-3456", "High Cholesterol", "password7", "No upcoming appointments."},
        {8, "Fiona Black", 55, "890-123-4567", "Thyroid Issues", "password8", "No upcoming appointments."},
        {9, "George Lee", 28, "901-234-5678", "Allergies", "password9", "No upcoming appointments."},
        {10, "Hannah Adams", 33, "012-345-6789", "Back Pain", "password10", "No upcoming appointments."},
        {11, "Ian Carter", 45, "123-456-7891", "Diabetes", "password11", "No upcoming appointments."},
        {12, "Jack Taylor", 65, "234-567-8902", "Hypertension", "password12", "No upcoming appointments."},
        {13, "Karen Miller", 29, "345-678-9013", "Asthma", "password13", "No upcoming appointments."},
        {14, "Laura Hall", 48, "456-789-0124", "Arthritis", "password14", "No upcoming appointments."},
        {15, "Mike Evans", 53, "567-890-1235", "Heart Disease", "password15", "No upcoming appointments."},
        {16, "Nina Brown", 26, "678-901-2346", "Migraines", "password16", "No upcoming appointments."},
        {17, "Oscar Green", 31, "789-012-3457", "High Cholesterol", "password17", "No upcoming appointments."},
        {18, "Paula White", 59, "890-123-4568", "Thyroid Issues", "password18", "No upcoming appointments."},
        {19, "Quinn Black", 44, "901-234-5679", "Allergies", "password19", "No upcoming appointments."},
        {20, "Rachel Lee", 36, "012-345-6780", "Back Pain", "password20", "No upcoming appointments."},
        {21, "Sam Adams", 52, "123-456-7892", "Diabetes", "password21", "No upcoming appointments."},
        {22, "Tina Carter", 27, "234-567-8903", "Hypertension", "password22", "No upcoming appointments."},
        {23, "Uma Taylor", 42, "345-678-9014", "Asthma", "password23", "No upcoming appointments."},
        {24, "Victor Miller", 58, "456-789-0125", "Arthritis", "password24", "No upcoming appointments."},
        {25, "Wendy Hall", 47, "567-890-1236", "Heart Disease", "password25", "No upcoming appointments."},
        {26, "Xander Evans", 39, "678-901-2347", "Migraines", "password26", "No upcoming appointments."},
        {27, "Yara Brown", 34, "789-012-3458", "High Cholesterol", "password27", "No upcoming appointments."},
        {28, "Zack Green", 49, "890-123-4569", "Thyroid Issues", "password28", "No upcoming appointments."},
        {29, "Amber Black", 41, "901-234-5670", "Allergies", "password29", "No upcoming appointments."},
        {30, "Brian Lee", 38, "012-345-6781", "Back Pain", "password30", "No upcoming appointments."},
        {31, "Julia Wood", 60, "101-202-3033", "Cancer", "password31", "No upcoming appointments."},
        {32, "Leo King", 70, "202-303-4044", "Stroke", "password32", "No upcoming appointments."},
        {33, "Mona Ray", 28, "303-404-5055", "Flu", "password33", "No upcoming appointments."},
        {34, "Nancy Hill", 45, "404-505-6066", "Diabetes", "password34", "No upcoming appointments."},
        {35, "Oscar Knight", 60, "505-606-7077", "Hypertension", "password35", "No upcoming appointments."}
    };
    int patientCount = 35;

    Doctor doctors[MAX_DOCTORS] = {
        {"Dr. Smith", "Cardiology"},
        {"Dr. Brown", "Neurology"},
        {"Dr. Lee", "Orthopedics"},
        {"Dr. Wilson", "Dermatology"},
        {"Dr. Green", "Pediatrics"},
        {"Dr. Carter", "Oncology"},
        {"Dr. Adams", "Psychiatry"},
        {"Dr. Taylor", "ENT"}
    };
    int doctorCount = 8;

    // Menu
    int choice;
    do {
        cout << "\n--- EL Samrout Hospital Management System ---\n";
        cout << "1. Create Patient Record\n";
        cout << "2. Update Patient Record\n";
        cout << "3. View Patients\n";
        cout << "4. Schedule Appointment\n";
        cout << "5. Access Medical History\n";
        cout << "6. Generate Bill\n";
        cout << "7. List Tests and Prices\n";
        cout << "8. Emergency\n";
        cout << "9. List of appoitment\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createPatient(patients, patientCount); break;
            case 2: updatePatient(patients, patientCount); break;
            case 3: displayPatients(patients, patientCount); break;
            case 4: scheduleAppointment(patients, patientCount, doctors, doctorCount); break;
            case 5: accessMedicalHistory(patients, patientCount); break;
            case 6: generateBill(); break;
            case 7: listTests(); break;
            case 8: emergency(); break;
            case 9: displayAppointmentReminder(patients, patientCount); break;
            case 10: cout << "Exiting system. Goodbye, Jaber!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
}

// Function to validate if a given patient ID is within the valid range
bool isValidPatientId(int id, int count) {
    return id > 0 && id <= count; // Valid IDs are between 1 and the total count of patients
}

// Function to validate if the entered age is within a reasonable range (1-120)
bool isValidAge(int age) {
    return age > 0 && age < 120; // Valid ages are greater than 0 and less than 120
}

// Function to create a new patient record
void createPatient(Patient patients[], int &count) {
    // Check if the patient list has reached its maximum capacity
    if (count >= MAX_PATIENTS) {
        cout << "Patient list is full!\n"; // Notify the user if no more patients can be added
        return;
    }

    Patient &p = patients[count]; // Reference the next available slot for a new patient
    p.id = count + 1;             // Assign a unique ID to the new patient

    // Input patient details
    cout << "Enter name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, p.name);

    int age;
    do {
        cout << "Enter age (1-120): "; // Prompt user to enter a valid age
        cin >> age;
    } while (!isValidAge(age)); // Repeat until a valid age is entered
    p.age = age;

    cout << "Enter contact: ";
    cin >> p.contact;

    cout << "Enter medical history: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, p.medicalHistory);

    cout << "Enter password: ";
    cin >> p.password;

    cout << "Patient record created successfully.\n"; // Confirmation message
    count++; // Increment the patient count
}

// Function to update an existing patient record
void updatePatient(Patient patients[], int count) {
    int id;
    cout << "Enter patient ID to update: ";
    cin >> id;

    // Validate the entered ID
    if (!isValidPatientId(id, count)) {
        cout << "Invalid ID!\n"; // Notify the user if the ID is invalid
        return;
    }

    Patient &p = patients[id - 1]; // Reference the specific patient by ID

    // Update patient details with new input
    cout << "Enter new name (current: " << p.name << "): ";
    cin.ignore();
    getline(cin, p.name);

    cout << "Enter new contact (current: " << p.contact << "): ";
    cin >> p.contact;

    cout << "Enter new medical history (current: " << p.medicalHistory << "): ";
    cin.ignore();
    getline(cin, p.medicalHistory);

    cout << "Patient record updated successfully.\n"; // Confirmation message
}

// Function to display all patient records
void displayPatients(const Patient patients[], int count) {
    cout << "\nList of Patients:\n"; // Header for the list
    for (int i = 0; i < count; ++i) {
        const Patient &p = patients[i]; // Access each patient's data
        // Display patient details in a formatted manner
        cout << "ID: " << p.id
             << " | Name: " << p.name
             << " | Age: " << p.age
             << " | Contact: " << p.contact
             << " | Medical History: " << p.medicalHistory << "\n";
    }
}

// Function to schedule an appointment for a patient
void scheduleAppointment(Patient patients[], int patientCount, Doctor doctors[], int doctorCount) {
    int patientId;
    cout << "Enter patient ID to schedule appointment: ";
    cin >> patientId;

    // Validate the entered patient ID
    if (!isValidPatientId(patientId, patientCount)) {
        cout << "Invalid patient ID.\n"; // Notify the user if the ID is invalid
        return;
    }

    // Clear the input buffer to avoid issues with getline
    cin.ignore();  // This will ignore the leftover newline character

    // Ask for the reason of the appointment
    string reason;
    cout << "Enter the reason for the appointment (problem): ";
    getline(cin, reason);  // Get the full reason including spaces

    // Randomly select a doctor
    int doctorIndex = rand() % doctorCount;

    // Generate a random appointment time between 8:00 AM and 4:00 PM
    string appointmentTime = to_string(8 + rand() % 9) + ":" + (rand() % 2 == 0 ? "00" : "30");

    // Set the appointment reminder for the patient
    patients[patientId - 1].appointmentReminder = "Appointment with Dr. " + doctors[doctorIndex].name 
                                                + " at " + appointmentTime + " for " + reason + ".";

    cout << "Appointment scheduled successfully!\n";
    cout << "Your appointment is with " << doctors[doctorIndex].name 
         << " at " << appointmentTime << " for " << reason << ".\n";
}


// Function to access a patient's medical history securely
void accessMedicalHistory(Patient patients[], int count) {
    int id;
    cout << "Enter patient ID to access medical history: ";
    cin >> id;

    // Validate the entered patient ID
    if (!isValidPatientId(id, count)) {
        cout << "Invalid ID!\n"; // Notify if ID is invalid
        return;
    }

    Patient &p = patients[id - 1]; // Reference the specific patient by ID
    string password;
    cout << "Enter password: ";
    cin >> password;

    // Check if the entered password matches the stored password
    if (password == p.password) {
        cout << "Medical History: " << p.medicalHistory << "\n"; // Display medical history
    } else {
        cout << "Incorrect password.\n"; // Notify if password is incorrect
    }
}

// Function to generate a bill for services
void generateBill() {
    string service, paymentMethod;
    double price;
    bool isPaid = false;

    // Input details of the service
    cout << "Enter services (e.g., consultation, test, surgery): ";
    cin.ignore(); // Clear any leftover newline characters in the input buffer
    getline(cin, service); // Get the full service description

    cout << "Enter price for the service: ";
    cin >> price; // Get the service price

    // Display the bill
    cout << "Bill generated. Service: " << service << " | Total: $" << price << "\n";

    // Input payment method
    cout << "Select payment method (MasterCard, Visa, Cash): ";
    cin.ignore(); // Clear any leftover newline characters
    getline(cin, paymentMethod);

    // Validate the payment method
    if (paymentMethod == "MasterCard" || paymentMethod == "Visa" || paymentMethod == "Cash") {
        cout << "Payment method: " << paymentMethod << "\n";
        cout << "Enter payment status (1 for paid, 0 for not paid): ";
        cin >> isPaid;
    } else {
        cout << "Invalid payment method. Bill cannot be processed.\n"; // Notify if payment method is invalid
    }

    // Display payment status
    if (isPaid) {
        cout << "The bill has been paid.\n";
    } else {
        cout << "The bill has not been paid.\n";
    }
}

// Function to list available medical tests and their prices
void listTests() {
    cout << "----- List of Available Tests and Prices -----\n";

    // Display general health tests
    cout << "General Health Tests:\n";
    cout << "1. Blood Test: $50\n";
    cout << "2. Urine Test: $30\n";
    cout << "3. Stool Test: $25\n";

    // Display imaging tests
    cout << "\nImaging Tests:\n";
    cout << "4. X-Ray: $100\n";
    cout << "5. MRI: $200\n";
    cout << "6. CT Scan: $250\n";

    // Display infectious disease tests
    cout << "\nInfectious Disease Tests:\n";
    cout << "7. Covid-19 Test: $20\n";
    cout << "8. Malaria Test: $40\n";
    cout << "9. Tuberculosis Test: $45\n";

    // Display specialized tests
    cout << "\nSpecialized Tests:\n";
    cout << "10. ECG (Electrocardiogram): $80\n";
    cout << "11. Cholesterol Test: $60\n";
    cout << "12. Thyroid Function Test: $70\n";

    // Display pregnancy and genetic tests
    cout << "\nPregnancy and Genetic Tests:\n";
    cout << "13. Pregnancy Test: $15\n";
    cout << "14. DNA Test: $300\n";

    cout << "\n-------------------------------------------------\n"; // End of the list
}

// Function to handle emergency situations
void emergency() {
    string location;
    cout << "Enter your location: ";
    cin >> location; // Input the user's location
    cout << "Emergency contact: 112. Ambulance on its way.\n"; // Provide emergency response
}

// Function to display appointment reminders for all patients
void displayAppointmentReminder(Patient patients[], int count) {
    for (int i = 0; i < count; ++i) {
        // Display patient name and their appointment reminder
        cout << "Patient: " << patients[i].name
             << " | Appointment Reminder: " << patients[i].appointmentReminder << endl;
    }
}