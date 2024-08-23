# Makefile for building Windows and Linux drivers with shared common code.
#
# Targets:
#   - make windows: Builds the Windows driver.
#   - make linux: Builds the Linux driver.
#   - make test_windows: Runs tests for the Windows driver.
#   - make test_linux: Runs tests for the Linux driver.
#   - make clean: Cleans up build artifacts.

# Define targets
WINDOWS_TARGET = MultimediaControllerDriver
LINUX_TARGET = multimedia_controller_driver

# Define EWDK installation path
EWDK_ROOT_PATH = C:\path\to\ewdk

# EWDK paths for Windows build
EWDK_ROOT = $(EWDK_ROOT_PATH)
WINDOWS_CC = $(EWDK_ROOT)\bin\x64\cl.exe
WINDOWS_LINK = $(EWDK_ROOT)\bin\x64\link.exe

# Linux compiler settings
LINUX_CC = gcc
LINUX_LFLAGS = -o

# Common source and object files
COMMON_SRCS = common/common.c
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

# Windows source and object files
WINDOWS_SRCS = windows/driver.c windows/controller.c $(COMMON_SRCS)
WINDOWS_OBJS = $(WINDOWS_SRCS:.c=.obj)

# Linux source and object files
LINUX_SRCS = linux/driver.c linux/controller.c $(COMMON_SRCS)
LINUX_OBJS = $(LINUX_SRCS:.c=.o)

# Compiler flags for Windows
WINDOWS_CFLAGS = /nologo /Zi /W3 /WX /Gm- /EHsc /D WIN32 /D _WINDOWS /D _UNICODE /D UNICODE /D _DRIVER
WINDOWS_CFLAGS += /D NDEBUG /GS /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Gd /TC

# Compiler flags for Linux
LINUX_CFLAGS = -Wall -Werror -D LINUX

# Default rule (build both drivers)
all: windows linux

# Windows build rule
windows: $(WINDOWS_TARGET).sys

$(WINDOWS_TARGET).sys: $(WINDOWS_OBJS)
	$(WINDOWS_LINK) $(WINDOWS_LFLAGS) /OUT:$@ $(WINDOWS_OBJS)

# Linux build rule
linux: $(LINUX_TARGET).ko

$(LINUX_TARGET).ko: $(LINUX_OBJS)
	$(LINUX_CC) $(LINUX_LFLAGS) $@ $(LINUX_OBJS)

# Compile source files to object files (Windows)
%.obj: %.c
	$(WINDOWS_CC) $(WINDOWS_CFLAGS) /Fo$@ $<

# Compile source files to object files (Linux)
%.o: %.c
	$(LINUX_CC) $(LINUX_CFLAGS) -o $@ -c $<

# Test rules for Windows
test_windows: $(WINDOWS_TARGET).sys
	# Add Windows-specific test commands here
	@echo "Running Windows tests..."

# Test rules for Linux
test_linux: $(LINUX_TARGET).ko
	# Add Linux-specific test commands here
	@echo "Running Linux tests..."

# Clean up build artifacts
clean:
	del /Q $(WINDOWS_OBJS) $(WINDOWS_TARGET).sys
	rm -f $(LINUX_OBJS) $(LINUX_TARGET).ko
	rm -f $(COMMON_OBJS)
