/**
 * @file controller.h
 * @brief Header file for the Windows Multimedia Controller.
 */

#pragma once

#include "common.h"

/**
 * @brief Initializes the multimedia controller.
 *
 * @param DriverObject Pointer to the driver object.
 */
void InitializeController(PDRIVER_OBJECT DriverObject);

/**
 * @brief Cleans up the multimedia controller.
 */
void UninitializeController();
