# Load-Store Queues

In order to leverage the power of dataflow circuits generated by Dynamatic, a memory interface is required which would analyze data dependencies, reorder memory accesses and stall in case of data hazards. Such a component is a Load-Store Queue, specifically designed for dataflow circuits. 

The strategy for managing memory accesses is based on the concept of groups. A group is a sequence of memory accesses that cannot be interrupted by a control flow decision. Determining a correct order of accesses within a group can be done easily using static analysis and can be encoded into the LSQ at compile time. The LSQ component has as many load/store ports as there are load/store operations in the program. These ports are clustered by groups, with every port belonging to one group. Whenever a group is "activated", all load/store operations belonging to that group are allocated in the LSQ in the sequence that was determined by static analysis. Once a group has been allocated, the LSQ expects each of the corresponding ports to eventually get an access; dependencies will be resolved based on the order of entries in the LSQ.

The specifics of LSQ implementation are available in [the corresponding documentation folder.](./LSQ/) For more information on the concept itself, [see the original paper.](https://dynamo.ethz.ch/wp-content/uploads/sites/22/2022/06/JosipovicTECS17_AnOutOfOrderLoadStoreQueueForSpatialComputing.pdf)

