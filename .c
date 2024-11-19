#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structures for Voters and Candidates
typedef struct Voter {
    int id;
    char name[100];
    struct Voter *next;
} Voter;

typedef struct Candidate {
    int id;
    char name[100];
    int votes;
    struct Candidate *next;
} Candidate;

// Define a Hash Table to track votes
#define TABLE_SIZE 100
int voteTable[TABLE_SIZE] = {0}; // Initialize all elements to 0

// Head pointers for the linked lists
Voter *voterHead = NULL;
Candidate *candidateHead = NULL;

// Function prototypes
void registerVoter(int id, const char *name);
void registerCandidate(int id, const char *name);
void castVote(int voterId, int candidateId);
void displayResults();
int hashFunction(int key);
int isVoterRegistered(int id);

int main() {
    int choice, id, candidateId;
    char name[100];

    while (1) {
        printf("Menu:\n");
        printf("1. Register Voter\n");
        printf("2. Register Candidate\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Voter ID: ");
                scanf("%d", &id);
                printf("Enter Voter Name: ");
                scanf("%s", name);
                registerVoter(id, name);
                break;
            case 2:
                printf("Enter Candidate ID: ");
                scanf("%d", &id);
                printf("Enter Candidate Name: ");
                scanf("%s", name);
                registerCandidate(id, name);
                break;
            case 3:
                printf("Enter Voter ID: ");
                scanf("%d", &id);
                printf("Enter Candidate ID to vote for: ");
                scanf("%d", &candidateId);
                castVote(id, candidateId);
                break;
            case 4:
                displayResults();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void registerVoter(int id, const char *name) {
    if (isVoterRegistered(id)) {
        printf("Voter %d is already registered.\n", id);
        return;
    }

    Voter *newVoter = (Voter *)malloc(sizeof(Voter));
    newVoter->id = id;
    strcpy(newVoter->name, name);
    newVoter->next = voterHead;
    voterHead = newVoter;
    printf("Voter %d registered: %s\n", id, name);
}

int isVoterRegistered(int id) {
    Voter *current = voterHead;
    while (current != NULL) {
        if (current->id == id) {
            return 1; // Voter is already registered
        }
        current = current->next;
    }
    return 0; // Voter is not registered
}

void registerCandidate(int id, const char *name) {
    Candidate *newCandidate = (Candidate *)malloc(sizeof(Candidate));
    newCandidate->id = id;
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    newCandidate->next = candidateHead;
    candidateHead = newCandidate;
    printf("Candidate %d registered: %s\n", id, name);
}

void castVote(int voterId, int candidateId) {
    int index = hashFunction(voterId);

    // Check if the voter has already voted
    if (voteTable[index] != 0) {
        printf("Voter %d has already voted.\n", voterId);
        return;
    }

    // Record the vote
    voteTable[index] = candidateId;

    // Find the candidate and increase their vote count
    Candidate *current = candidateHead;
    while (current != NULL) {
        if (current->id == candidateId) {
            current->votes++;
            printf("Voter %d cast vote for Candidate %d.\n", voterId, candidateId);
            return;
        }
        current = current->next;
    }

    // If candidate ID is not found
    printf("Candidate %d not found.\n", candidateId);
}

void displayResults() {
    printf("Election Results:\n");
    Candidate *current = candidateHead;
    while (current != NULL) {
        printf("Candidate %d (%s) received %d votes.\n", current->id, current->name, current->votes);
        current = current->next;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}
