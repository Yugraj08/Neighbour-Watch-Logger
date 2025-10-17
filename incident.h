// incident.h

#ifndef INCIDENT_H
#define INCIDENT_H

// This struct holds all info about one incident
struct Incident {
    char datetime[50];       // Example: "2025-06-06 14:45:02"
    char location[100];      // Example: "Front Gate"
    char description[250];   // Example: "Unknown man was loitering"
};

// Function declarations (blueprint only, real code is in main.c)
void logIncident();
void viewAllIncidents();

#endif
