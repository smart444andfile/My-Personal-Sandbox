#include <stdio.h>

/* 1. นิยามสถานะตามมาตรฐาน Kernel Style (All Caps สำหรับ Enum) */
typedef enum {
    STATE_IDLE    = 0,
    STATE_BUSY    = 1,
    STATE_ERROR   = 2
} system_state_t;

typedef enum {
    ACTION_ACCEPT,
    ACTION_WAIT,
    ACTION_REJECT
} kernel_action_t;

/**
 * evaluate_system_task - ตัดสินใจการจัดการงานตามสถานะปัจจุบันของฮาร์ดแวร์
 * @current_state: สถานะที่รับมาจาก Hardware
 * @memory_kb: หน่วยความจำที่ว่างอยู่ (KB)
 * @priority: ลำดับความสำคัญของงาน (0-100)
 */
kernel_action_t evaluate_system_task(system_state_t current_state, int memory_kb, int priority) {
    kernel_action_t decision;

    /* * TODO: เขียน logic โดยใช้ switch-case ตรวจสอบ current_state 
     * 1. ในกรณี STATE_IDLE -> ให้ผลลัพธ์เป็น ACTION_ACCEPT
     * 2. ในกรณี STATE_BUSY -> เช็ค memory_kb > 1024 และ priority > 80
     * ถ้าผ่านให้ ACTION_ACCEPT ถ้าไม่ผ่านให้ ACTION_WAIT
     * 3. ในกรณี STATE_ERROR หรือสถานะอื่นๆ -> ให้ ACTION_REJECT
     */
    
    // เริ่มเขียน Code ของคุณที่นี่
    switch(current_state) {
	    case STATE_IDLE :
		    decision = ACTION_ACCEPT;
		    break;
	case STATE_BUSY :
		    if ((priority > 80) && (memory_kb > 1024))
		    	{
			    decision = ACTION_ACCEPT;
		    	}
		    else decision = ACTION_WAIT;
		    break;
	case STATE_ERROR :
		    decision = ACTION_REJECT;
		    break;
	default: decision = ACTION_REJECT;
    }
    
    return decision;
}

int main() {
    // จำลองค่าที่ได้รับจาก Hardware Register และ System Metrics
    system_state_t hw_status = STATE_BUSY;
    int available_mem = 2000;
    int task_priority = 90;

    // เรียกใช้ API ที่เราสร้างขึ้น
    kernel_action_t result = evaluate_system_task(hw_status, available_mem, task_priority);

    // แสดงผลการตัดสินใจของ Kernel
    printf("Hardware Status: %d\n", hw_status);
    printf("Kernel Decision: %s\n", 
           (result == ACTION_ACCEPT) ? "ACCEPT" : 
           (result == ACTION_WAIT)   ? "WAIT"   : "REJECT");

    return 0;
}
