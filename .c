#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for Voters and Candidates
typedef struct Voter {
    int id;
    char name[100];
    char password[50];
    struct Voter *next;
} Voter;

typedef struct Candidate {
    int id;
    char name[100];
    int votes;
    struct Candidate *next;
} Candidate;

// Hash Table for tracking votes
#define TABLE_SIZE 100
int voteTable[TABLE_SIZE] = {0};

// Linked lists for voters and candidates
Voter *voterHead = NULL;
Candidate *candidateHead = NULL;

// Function prototypes
void registerVoter(int id, const char *name, const char *password);
void registerCandidate(int id, const char *name);
void castVote(int voterId, const char *password, int candidateId);
void displayResults();
int hashFunction(int key);
int isVoterRegistered(int id);
Voter *findVoter(int id);

int main() {
    int choice, id, candidateId;
    char name[100], password[50];

    while (1) {
        printf("\nMenu:\n");
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
                printf("Set Voter Password: ");
                scanf("%s", password);
                registerVoter(id, name, password);
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
                printf("Enter Voter Password: ");
                scanf("%s", password);
                printf("Enter Candidate ID to vote for: ");
                scanf("%d", &candidateId);
                castVote(id, password, candidateId);
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

void registerVoter(int id, const char *name, const char *password) {
    if (isVoterRegistered(id)) {
        printf("Voter %d is already registered.\n", id);
        return;
    }

    Voter *newVoter = (Voter *)malloc(sizeof(Voter));
    newVoter->id = id;
    strcpy(newVoter->name, name);
    strcpy(newVoter->password, password);
    newVoter->next = voterHead;
    voterHead = newVoter;
    printf("Voter %d registered: %s\n", id, name);
}

int isVoterRegistered(int id) {
    return findVoter(id) != NULL;
}

Voter *findVoter(int id) {
    Voter *current = voterHead;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void registerCandidate(int id, const char *name) {
    Candidate *current = candidateHead;
    while (current != NULL) {
        if (current->id == id) {
            printf("Candidate %d is already registered.\n", id);
            return;
        }
        current = current->next;
    }

    Candidate *newCandidate = (Candidate *)malloc(sizeof(Candidate));
    newCandidate->id = id;
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    newCandidate->next = candidateHead;
    candidateHead = newCandidate;
    printf("Candidate %d registered: %s\n", id, name);
}

void castVote(int voterId, const char *password, int candidateId) {
    int index = hashFunction(voterId);
    Voter *voter = findVoter(voterId);

    if (voter == NULL) {
        printf("Voter ID %d is not registered.\n", voterId);
        return;
    }

    if (strcmp(voter->password, password) != 0) {
        printf("Incorrect password for Voter ID %d.\n", voterId);
        return;
    }

    if (voteTable[index] != 0) {
        printf("Voter %d has already voted.\n", voterId);
        return;
    }

    voteTable[index] = candidateId;

    Candidate *current = candidateHead;
    while (current != NULL) {
        if (current->id == candidateId) {
            current->votes++;
            printf("Voter %d cast vote for Candidate %d.\n", voterId, candidateId);
            return;
        }
        current = current->next;
    }

    printf("Candidate %d not found.\n", candidateId);
}

void displayResults() {
    printf("Election Results:\n");

    Candidate *current = candidateHead;
    Candidate *winner = NULL;
    int maxVotes = 0;

    // Traverse the candidate list to display results and find the winner
    while (current != NULL) {
        printf("Candidate %d (%s) received %d votes.\n", current->id, current->name, current->votes);

        // Determine the candidate with the highest votes
        if (current->votes > maxVotes) {
            maxVotes = current->votes;
            winner = current;
        } else if (current->votes == maxVotes) {
            winner = NULL; // Tie between candidates
        }

        current = current->next;
    }

    // Announce the winner
    if (winner != NULL) {
        printf("\nWinner: Candidate %d (%s) with %d votes!\n", winner->id, winner->name, maxVotes);
    } else {
        printf("\nThere is a tie between candidates. No single winner.\n");
    }
}


int hashFunction(int key) {
    return key % TABLE_SIZE;
}
