#pragma once

#define USERNAME_LENGTH 10

// User structure
typedef struct {
    char username[USERNAME_LENGTH + 1];
    int level;
    char *faction;
} User;

// Queue node structure
typedef struct Node {
    User user;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *pHead;
    Node *pTail;
} Queue;

// Function declarations
void InitQueue(Queue* q);
int IsQueueEmpty(Queue *q);
void Enqueue(Queue *q, Node *newNode);
Node* Dequeue(Queue *q);
void generateRandomUsername(char *username);
User generateRandomUser();
int enqueueRandomUsers(Queue *q, int count);
