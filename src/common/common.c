/**
 * @file common.c
 * @brief Implementation of functions shared between Windows and Linux drivers.
 */

#include "common.h"

/**
 * @brief A common function that prints a message to the system log.
 *        The message format depends on the operating system.
 */
void CommonFunction() {
    // Platform-independent code
    #ifdef _WIN32
    	DbgPrint("Common function called on Windows\n");
    #else
    	printk(KERN_INFO "Common function called on Linux\n");
    #endif
}
