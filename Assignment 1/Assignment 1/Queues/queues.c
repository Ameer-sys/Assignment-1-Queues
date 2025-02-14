#include "queues.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // srand

// Faction options
const char *FACTIONS[] = {"Red", "Blue", "Green"};

// Function to initialize the queue
void InitQueue(Queue *q) {
    q->pHead = q->pTail = NULL; // initialize as null since we wait empty
}

// Function to check if the queue is empty
int IsQueueEmpty(Queue *q) {
    return (q->pHead == NULL); // checks and confirm it's empty
}

// Function to enqueue a new user node
void Enqueue(Queue *q, Node *newNode) {
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->next = NULL;
    if (IsQueueEmpty(q)) { // the empty check func call
        q->pHead = q->pTail = newNode;// put the newuser in node having 
                                      // having tail and head since it alone
    } else {
        q->pTail->next = newNode; // else tail will be for next node
        q->pTail = newNode;
    }
}

// Function to dequeue a user node
Node* Dequeue(Queue *q) { // FIFO the queue and returns everything
    if (IsQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty!\n"); // if queue empty, dequeue can't proceed
        return NULL;
    }
    Node *temp = q->pHead; 
    q->pHead = q->pHead->next;
    if (q->pHead == NULL) {
        q->pTail = NULL;
    }
    return temp;
}

// Function to generate a random username
void generateRandomUsername(char *username) {
    for (int i = 0; i < USERNAME_LENGTH; i++) {
        int randomType = rand() % 2;// what this does is generate random number using rand(), 
                                    //% 2) ensures that the result will be either 
                                    // 0 or 1. if 1 - letter, 0 - digit. 
        if (randomType)
            username[i] = 'a' + rand() % 26;  // Random lowercase letter 
                                              //rand() % 26 generates a number between 0 and 25.
                                             //By adding this number to 'a', you get a random 
                                             // lowercase letter from 'a' to 'z'.
        else
            username[i] = '0' + rand() % 10;  // Random digit from 1 to 9
    }
    username[USERNAME_LENGTH] = '\0'; // make sure is null terminated to show end of string after loop finishes
}

// Function to generate a random user
User generateRandomUser() {
    User user;
    generateRandomUsername(user.username); // using to Calls generateRandomUsername() to
                                           //fill user.username with a randomly generated string.
    user.level = 1 + rand() % 60;  // Level between 1 and 60
    user.faction = (char *)FACTIONS[rand() % 3];  // Random faction
                                                  //Picks a random faction from the FACTIONS[] array
                                                  // strictly using 3 factions given.
    return user;
}

// Function to enqueue a number of random users
int enqueueRandomUsers(Queue *q, int count) //creating and enqueuing a specified
                                            //number of random users into the queue.
{
    for (int i = 0; i < count; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (!newNode) {
            fprintf(stderr, "Memory allocation failed!\n");
            return 1;
        }
        newNode->user = generateRandomUser(); //calls and create random user to the newNode
        Enqueue(q, newNode);// add newNode to queue
    }
    return 0;
}
