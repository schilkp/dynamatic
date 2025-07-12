## Setting up Dynamatic

There are currently two ways to setup and use Dynamatic locally.

1. **Build from source (recommended)**. We support building from source on Linux and on Windows (through [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)). See our [simple build instructions](#building-from-source) below, which should work out-of-the-box. Ubuntu 24.04 LTS is officially supported; other apt-based distributions should work as well. Other distribuions may also require cosmetic changes to the dependencies you have to install before running Dynamatic.

2. **Use the provided virtual machine**. We provide an [Ubuntu-based virtual machine](./VMSetup.md) (VM) that already has Dynamatic, Modelsim, and our dataflow circuit visualizer set up. This machine was originally set-up for the [*Dynamatic Reloaded* tutorial given at the FPGA'24 conference](https://www.isfpga.org/workshops-tutorials/#t7) in Monterey, California. You can use it to simply follow the tutorial (available in the [repository's documentation](docs/Tutorials/Introduction/Introduction.md)) or as a starting point to use/modify Dynamatic in general.
