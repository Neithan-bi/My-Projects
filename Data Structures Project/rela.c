#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10
#define MAX_NAME_LENGTH 100
#define MAX_CHEFS 3

struct Order {
    int orderId;
    char customerName[MAX_NAME_LENGTH];
    char dishName[MAX_NAME_LENGTH];
    int price;
    time_t orderTime;
    time_t completionTime;
    int chefIndex;
};

struct Chef {
    char name[MAX_NAME_LENGTH];
    int isAvailable;
};

struct OrderQueue {
    int front, rear;
    struct Order orders[MAX_QUEUE_SIZE];
};

int nextChefIndex = 0;  // Tracks round-robin chef assignment

void initializeQueue(struct OrderQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueFull(struct OrderQueue* queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty(struct OrderQueue* queue) {
    return queue->front == -1;
}

void enqueueOrder(struct OrderQueue* queue, struct Order order) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot accept more orders.\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    order.orderTime = time(NULL);
    queue->orders[queue->rear] = order;
    printf("Order %d added to queue.\n", order.orderId);
}

struct Order dequeueOrder(struct OrderQueue* queue) {
    struct Order emptyOrder = {0};
    if (isQueueEmpty(queue)) {
        printf("No orders in the queue.\n");
        return emptyOrder;
    }
    struct Order order = queue->orders[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return order;
}

void initializeChefs(struct Chef chefs[], int numChefs) {
    for (int i = 0; i < numChefs; i++) {
        printf("Enter name of Chef %d: ", i + 1);
        scanf("%s", chefs[i].name);
        chefs[i].isAvailable = 1;
    }
}

void assignChefToOrder(struct Chef chefs[], int numChefs, struct Order* order) {
    int i = nextChefIndex;
    printf("Chef %s is preparing order %d: %s for %s\n",
           chefs[i].name, order->orderId, order->dishName, order->customerName);
    chefs[i].isAvailable = 0;
    order->chefIndex = i;
    nextChefIndex = (nextChefIndex + 1) % numChefs;
}

void printBill(struct Order order) {
    char orderTimeStr[26], completionTimeStr[26];
    strftime(orderTimeStr, sizeof(orderTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&order.orderTime));
    strftime(completionTimeStr, sizeof(completionTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&order.completionTime));

    double duration = difftime(order.completionTime, order.orderTime);

    printf("\n--- BILL ---\n");
    printf("Order ID         : %d\n", order.orderId);
    printf("Customer         : %s\n", order.customerName);
    printf("Dish             : %s\n", order.dishName);
    printf("Price (Rs)       : %d\n", order.price);
    printf("Order Time       : %s\n", orderTimeStr);
    printf("Completion Time  : %s\n", completionTimeStr);
    printf("Time Taken       : %.0f seconds\n", duration);
    printf("------------------\n");
}

void completeOrder(struct Chef chefs[], int numChefs, struct Order* order) {
    int i = order->chefIndex;
    if (i >= 0 && i < numChefs) {
        printf("Chef %s completed order %d\n", chefs[i].name, order->orderId);
        chefs[i].isAvailable = 1;
        order->completionTime = time(NULL);
        printBill(*order);
    } else {
        printf("Error: No chef was assigned to order %d\n", order->orderId);
    }
}

void showQueueStatus(struct OrderQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("No orders pending.\n");
    } else {
        printf("\nOrders in queue:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            struct Order o = queue->orders[i];
            printf("ID: %d | Dish: %s | Customer: %s | Price: Rs %d\n",
                   o.orderId, o.dishName, o.customerName, o.price);
        }
    }
}

int main() {
    struct Chef chefs[MAX_CHEFS];
    struct OrderQueue orderQueue;
    initializeQueue(&orderQueue);

    printf("=== Chef Setup ===\n");
    initializeChefs(chefs, MAX_CHEFS);

    int numOrders;
    printf("\nEnter number of orders (max %d): ", MAX_QUEUE_SIZE);
    scanf("%d", &numOrders);

    if (numOrders > MAX_QUEUE_SIZE)
        numOrders = MAX_QUEUE_SIZE;

    for (int i = 0; i < numOrders; i++) {
        struct Order order;
        order.orderId = i + 1;

        printf("\nOrder %d\n", order.orderId);
        printf("Enter customer name: ");
        scanf("%s", order.customerName);
        printf("Enter dish name: ");
        scanf("%s", order.dishName);
        printf("Enter price (in Rs): ");
        scanf("%d", &order.price);

        enqueueOrder(&orderQueue, order);
    }

    printf("\n=== Processing Orders ===\n");
    while (!isQueueEmpty(&orderQueue)) {
        struct Order current = dequeueOrder(&orderQueue);
        assignChefToOrder(chefs, MAX_CHEFS, &current);
        printf("Press 1 to mark order as completed: ");
        int complete;
        scanf("%d", &complete);
        if (complete == 1)
            completeOrder(chefs, MAX_CHEFS, &current);
    }

    printf("\n=== Final Queue Status ===\n");
    showQueueStatus(&orderQueue);
    printf("All orders completed.\n");

    return 0;
}