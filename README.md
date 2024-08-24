# Driver Boilerplate

A code template for kick-starting the development cross platform (Windows and Linux) Driver.

## Development

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

Following are the minimum requirements for the development of this project.

- A Windows Machine ( Windows 10, version 1809 or higher ) with [Enterprise WDK](https://learn.microsoft.com/en-us/legal/windows/hardware/enterprise-wdk-license-2017) (2017 or higher) installed
- Have the `DebugView` tool from SysInternals on the Test Machine
- On the test machine, turn off Integrity checks and turn on test signing. This can be done by running the following commands from an Admin prompt and then rebooting the system:

```shell
bcdedit.exe -set loadoptions DISABLE_INTEGRITY_CHECKS
bcdedit.exe -set TESTSIGNING ON
```

### Build

To build the driver, simply run:

```shell
make build
```

### Testing

To build the tests, just run:

```shell
make test
```

## Changelog

All the notable changes to this project will be documented in [CHANGELOG](CHANGELOG.md) file.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for more information.

## Authors

The following people are contributing to this project.

- [@musthafasm](https://github.com/musthafasm)
