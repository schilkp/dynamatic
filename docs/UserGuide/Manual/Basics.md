# Basic Usage

Dynamatic consists of many components, but the simplest way to use Dynamatic is using the `dynamatic` binary, which abstracts away most of the details by providing a user-friendly interactive shell. After completing the build process, just run
```
$ bin/dynamatic
```
from the root directory of the cloned Dynamatic repository.

From here, you are offered a shell with a variety of commands that you can see by typing `help`, or by referring to the list below.

## Dynamatic Shell Commands
- `help`: Display list of commands.
- `write-hdl [--hdl <VHDL|Verilog>]`: Convert results from `compile` to a VHDL or Verilog file.
- `set-vivado-path <path>`: Set the path to the installation directory of Vivado.
- `simulate`: Simulates the HDL produced by `write-hdl`. **Requires a ModelSim installation!**
- `set-fp-units-generator <flopoco|vivado>`: Choose which floating point unit generator to use. See [this section](#floating-point-ips) for more information.
- `set-clock-period <clk>`: Sets the target clock period in nanoseconds.
- `set-dynamatic-path <path>`: Set the path of the root (top-level) directory of Dynamatic, so that it can locate various scripts it needs to function. This is not necessary if you run Dynamatic from said directory.
- `set-src <source-path>`: Sets the path of the `.c` file of the kernel that you want to compile. 
- `synthesize`: Synthesizes the HDL result from `write-hdl` using Vivado. **Requires a Vivado installation!**
- `compile [...]`: Compiles the source kernel (chosen by `set-src`) into a dataflow circuit. For more options, run `compile --help`. **Does not require Gurobi by default, [but some options do!](#buffer-placement-strategies)**
- `visualize`: Visualizes the execution of the circuit simulated by `ModelSim`. **Requires Godot Engine and [the visualizer component must be built!](https://github.com/EPFL-LAP/dynamatic/blob/main/docs/AdvancedBuild.md#interactive-dataflow-circuit-visualizer)**
- `set-polygeist-path <path>`: Sets the path to the Polygeist installation directory.
- `exit`: Exits the interactive Dynamatic shell.

An example of a usual sequence of commands is given below:
```
set-src integration-test/fir/fir.c
compile
write-hdl
simulate
```

## Reviewing HLS reports

Each command will inform you about its result (success/failure) via interactive shell output. Detailed reports are saved in a folder named `out` in the same path where the `.c` kernel source was located; i.e. if you used `integration-test/fir/fir.c`, then the reports would be in `integration-test/fir/out`.

- `out/comp`: Contains artifacts produced by the compilation. This includes all intermediate MLIR results, as well as the diagram of the dataflow circuit and the control flow graph (in DOT and PNG formats).
- `out/hdl`: Contains HDL descriptions of all components of the generated dataflow circuit.
- `out/sim`: Contains subfolders with various simulation artifacts, as well as a text file `report.txt` with the entire simulation log.

## Scripting

Running the same set of commands over and over again can get tedious, so Dynamatic has basic scripting support. You can write the sequence of commands to be executed into a file and then run them all at once using
```
$ bin/dynamatic --run=<path-to-script>
```

## Custom Compilation Flows
Sometimes, for advanced usage, features provided by the `dynamatic` shell are not enough. In such case, one should invoke components such as `dynamatic-opt` (also located in the `bin` directory) directly. The default compilation flow is implemented in `tools/dynamatic/scripts/compile.sh`; you can use this as a template that you can adjust to your needs.
