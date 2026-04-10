#include <stdio.h>
#include <string.h>

/* 1. นิยามโครงสร้างข้อมูลของงาน (Task Structure) */
typedef struct {
    char name[20];
    int priority;
    unsigned long stack_pointer; // ที่อยู่ของหน่วยความจำ (Memory Address)
} task_t;

/**
 * validate_and_run_task - ตรวจสอบความปลอดภัยของ Task ก่อนรัน
 * @task: พอยน์เตอร์ที่ชี้ไปยังโครงสร้างงาน
 */
void validate_and_run_task(task_t *task) {
    // [TODO: เขียน Code ตรวจสอบที่นี่]
    
    // 1. เช็คว่า task เป็น NULL หรือไม่ (Defensive Programming)
    
    // 2. ถ้าไม่เป็น NULL ให้เช็คว่า stack_pointer เป็น 0 หรือไม่
    
    // 3. ถ้าทุกอย่างปกติ ให้พิมพ์ชื่อ Task และคำว่า "is Ready to Run"
    // Hint: การเข้าถึงสมาชิกใน struct ผ่าน pointer ให้ใช้ task->name
    //
    if (task == NULL){
	printf("Error: Task pointer is NULL. Acces denied.\n");
	return;
    }else if (task->stack_pointer == 0) {
        printf("Kernel Panic: Invalid Stack Pointer for Task [%s]!\n", task->name);
    } else {
        printf("Task [%s] is Ready to Run (Stack: 0x%lx)\n", task->name, task->stack_pointer);
    }

}

int main() {
    // จำลอง Task ที่ปกติ
    task_t task1 = {"Network_Driver", 90, 0x1234FFFF};
    
    // จำลอง Task ที่พัง (Memory Address เป็น 0)
    task_t task2 = {"Old_Process", 10, 0x0};

    printf("Checking Task 1...\n");
    validate_and_run_task(&task1); // ส่ง Address ของ task1 ไป

    printf("\nChecking Task 2...\n");
    validate_and_run_task(&task2);

    printf("\nChecking Null Pointer...\n");
    validate_and_run_task(NULL); // จำลองกรณี Error รุนแรง

    return 0;
}
