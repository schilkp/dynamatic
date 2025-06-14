//===- CreateWrappers.h - Generate Wrapper for SMV circuits -----*- C++ -*-===//
//
// Dynamatic is under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements a generator for wrappers for SMV circuits. It places
// sequence_generators at all the inputs and sinks at all the outputs.
// Additionally, properties and sequence constraints can be created.
//
//===----------------------------------------------------------------------===//

#ifndef DYNAMATIC_EXPERIMENTAL_ELASTIC_MITER_TESTBENCH_H
#define DYNAMATIC_EXPERIMENTAL_ELASTIC_MITER_TESTBENCH_H

#include "Constraints.h"
#include "FabricGeneration.h"
#include "dynamatic/Support/LLVM.h"
#include "experimental/Support/CreateSmvFormalTestbench.h"
#include <cstddef>
#include <filesystem>
#include <string>

using namespace mlir;

namespace dynamatic::experimental {

// Create a wrapper for the provided SMV file.
// includeProperties: If set also creates properties to check if all output
//   tokens are true, the output buffers are empty, and the input buffer have
//   the same number of tokens stored pairwise.
// nrOfTokens: Set the number of tokens
//   generated by the sequence generators. If it is set to 0 a generator
//   capabale of creating an infinite number of tokens will be created.
// exact: determines if the sequence generator create exactly "nrOfTokens"
//   tokens, or can non-determinstically create fewer tokens.

std::string createElasticMiterTestBench(
    MLIRContext &context, const ElasticMiterConfig &config,
    const std::string &modelSmvName, size_t nrOfTokens, bool includeProperties,
    const std::optional<
        SmallVector<dynamatic::experimental::ElasticMiterConstraint *>>
        &sequenceConstraints,
    bool generateExactNrOfTokens = false);

LogicalResult createSmvSequenceLengthTestbench(
    MLIRContext &context, const std::filesystem::path &wrapperPath,
    const ElasticMiterConfig &config, const std::string &modelSmvName,
    size_t nrOfTokens);

} // namespace dynamatic::experimental
#endif // DYNAMATIC_EXPERIMENTAL_ELASTIC_MITERL_TESTBENCH_H