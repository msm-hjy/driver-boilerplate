/**
 * @file driver.c
 * @brief Main entry point for the Linux Multimedia Controller Driver.
 */

#include "controller.h"
#include "common.h"

/**
 * @brief driver_init - Module initialization function.
 *
 * @return int Returns 0 on success, negative error code on failure.
 */
static int __init driver_init(void)
{
    printk(KERN_INFO "Linux Multimedia Controller Driver Init\n");

    // Initialize and configure the multimedia controller
    InitializeController();

    // Call a common function
    CommonFunction();

    return 0;
}

/**
 * @brief driver_exit - Module exit function.
 */
static void __exit driver_exit(void)
{
    printk(KERN_INFO "Linux Multimedia Controller Driver Exit\n");

    // Clean up the multimedia controller
    UninitializeController();
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Multimedia Controller Driver");
