/**
 * @file driver.c
 * @brief Main entry point for the Windows Multimedia Controller Driver.
 */

#include "controller.h"
#include "common.h"

/**
 * @brief DriverEntry - Entry point for the driver.
 *
 * @param DriverObject Pointer to the driver object.
 * @param RegistryPath Pointer to the registry path.
 *
 * @return NTSTATUS Status code indicating success or failure.
 */
extern "C" NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT   DriverObject,
    _In_ PUNICODE_STRING  RegistryPath
)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = UnloadDriver;

    // Initialize and configure the multimedia controller
    InitializeController(DriverObject);

    // Call a common function
    CommonFunction();

    return STATUS_SUCCESS;
}

/**
 * @brief UnloadDriver - Unloads the driver.
 *
 * @param DriverObject Pointer to the driver object.
 */
extern "C" VOID
UnloadDriver(
    _In_ PDRIVER_OBJECT DriverObject
)
{
    UNREFERENCED_PARAMETER(DriverObject);

    // Clean up the multimedia controller
    UninitializeController();
}
