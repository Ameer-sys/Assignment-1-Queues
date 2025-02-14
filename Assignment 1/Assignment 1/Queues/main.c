#include "queues.h"
#include <stdio.h>
#include <stdlib.h>

// set command line as 5 players
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    int numUsers = atoi(argv[1]);//atoi() function is used to convert a
                                 //numeric string into an integer value.
    if (numUsers <= 0) {
        fprintf(stderr, "Please enter a positive number of users.\n");
        return 1;
    } // this in only applicable if numof user is = 0 but we have 5 assigned already.

    srand(time(NULL));  // Seed random number generator
    // used too generate different outputs every time it runs
    Queue q;
    InitQueue(&q);  // Initialize the queue // sets q head and tail to NULL ready to store

    // Enqueue random users
    if (enqueueRandomUsers(&q, numUsers) != 0) {
        fprintf(stderr, "Error enqueuing users\n");

        while (!IsQueueEmpty(&q)) // to remove all node in each loop
        {
            Node *node = Dequeue(&q); // start removing node 1 from queue
            free(node);  // Free remaining nodes
        }
        return 1;
    }

    // Display dequeued users
    printf("\nDequeuing users:\n");
    printf("\n");
    while (IsQueueEmpty(&q) == 0) // using a while loop to run until the queue is empty.
    {
        Node *node = Dequeue(&q); //same function as the prev 
        if (node) // if all the queuewing and dqueue were succeffuly we print the result 
                  // like poping dequeued data.
        {
            printf("Username: %s | Level: %d | Faction: %s\n",
                   node->user.username, node->user.level, node->user.faction);
            printf("---------------------------------------------------\n");
            free(node);  // Free memory
        }
    }
    printf("\n");

	return 0;
}