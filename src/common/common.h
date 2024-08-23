/**
 * @file common.h
 * @brief Common header file for shared definitions and declarations
 *        between Windows and Linux drivers.
 */

#pragma once

// Shared includes and definitions
#ifdef _WIN32
    #include <ntddk.h>
#else
    #include <linux/kernel.h>
    #include <linux/module.h>
#endif

/**
 * @brief A common function shared by both Windows and Linux drivers.
 */
void CommonFunction();
