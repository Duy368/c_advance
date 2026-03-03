#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- (Singly Linked List) --- */
typedef struct TaskNode {
    char task_description[50];
    struct TaskNode* next;
} TaskNode_t;

TaskNode_t *queue_head = NULL;
TaskNode_t *queue_tail = NULL;

void queue_add_task(const char* description) {
    TaskNode_t* newNode = (TaskNodeo_t*)malloc(sizef(TaskNode_t));
    if (!newNode) return;
    
    strncpy(newNode->task_description, description, 49);
    newNode->next = NULL;

    if (queue_tail == NULL) {
        queue_head = queue_tail = newNode;
    } else {
        queue_tail->next = newNode;
        queue_tail = newNode;
    }
    printf("[Queue] Add: '%s' | Node addr: %p\n", description, (void*)newNode);
}

TaskNode_t* queue_get_next_task(void) {
    if (queue_head == NULL) return NULL;
    TaskNode_t* temp = queue_head;
    queue_head = queue_head->next;
    if (queue_head == NULL) queue_tail = NULL;
    return temp;
}

/*--- (Doubly Linked List) --- */
typedef struct HistoryNode {
    char log_entry[50];
    struct HistoryNode* next;
    struct HistoryNode* prev;
} HistoryNode_t;

HistoryNode_t* history_head = NULL;

void history_log_activity(const char* entry) {
    HistoryNode_t* newNode = (HistoryNode_t*)malloc(sizeof(HistoryNode_t));
    if (!newNode) return;

    strncpy(newNode->log_entry, entry, 49);
    newNode->next = history_head;
    newNode->prev = NULL;

    if (history_head != NULL) {
        history_head->prev = newNode;
    }
    history_head = newNode;
    printf("[Log] Recorded: '%s' | Node addr: %p\n", entry, (void*)newNode);
}

void history_navigate(void) {
    if (!history_head) {
        printf("Nhật ký trống!\n");
        return;
    }
    HistoryNode_t* current = history_head;
    char cmd;
    printf("\n--- NAVIGATE LOG (n: next, p: prev, q: quit) ---\n");
    while (1) {
        printf("\nLOG: %s\nAddr: %p | P: %p | N: %p\nCMD: ", 
               current->log_entry, (void*)current, (void*)current->prev, (void*)current->next);
        scanf(" %c", &cmd);
        if (cmd == 'n') {
            if (current->next) current = current->next;
            else printf(">> Cuối danh sách!\n");
        } else if (cmd == 'p') {
            if (current->prev) current = current->prev;
            else printf(">> Đầu danh sách!\n");
        } else if (cmd == 'q') break;
    }
}
int main() {
    char cmd[20], desc[50];
    printf("Embedded Task Manager Initialized.\n");
    
    while (1) {
        printf("\n> Command (add, run, history, list, exit): ");
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf(" %[^\n]", desc);
            queue_add_task(desc);
        } else if (strcmp(cmd, "run") == 0) {
            TaskNode_t* task = queue_get_next_task();
            if (task) {
                printf("Executing: %s (Freeing %p)\n", task->task_description, (void*)task);
                history_log_activity(task->task_description);
                free(task);
            } else printf("Queue empty!\n");
        } else if (strcmp(cmd, "history") == 0) {
            history_navigate();
        } else if (strcmp(cmd, "exit") == 0) break;
    }
    return 0;
}