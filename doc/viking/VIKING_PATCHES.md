# Viking DGD Patches

This document describes the patches and modifications made to the official DGD driver for VikingMud. These patches are maintained on top of the upstream DGD codebase.

## Overview

The Viking DGD fork includes several custom modifications that enhance the driver for VikingMud's specific needs. The main areas of modification are:

1. **VIKING Define** - Enables Viking-specific kernel functions
2. **SLASHSLASH Define** - Enables C++ style // comments in LPC code
3. **LARGENUM Define** - Enables support for larger numeric types (64-bit integers)
4. **Build System** - Modifications to support macOS compilation

## Detailed Patch Descriptions

### 1. VIKING Define

**Purpose**: Enables Viking-specific kernel functions that are not part of standard DGD.

**Files Modified**:
- `src/Makefile` - Adds `-DVIKING` to DEBUG flags
- `src/kfun/viking.cpp` - New file containing Viking-specific kernel functions
- `src/kfun/table.cpp` - Includes viking.cpp in the kernel function table

**Implementation**:
Currently implements one Viking-specific kernel function:

#### rusage()
- **Function**: `int *rusage()`
- **Purpose**: Reports on resource utilization of the DGD process
- **Returns**: Array of 14 integers containing:
  - [0] User CPU time (milliseconds)
  - [1] System CPU time (milliseconds)
  - [2] Maximum resident set size
  - [3] Integral shared memory size
  - [4] Page reclaims (minor faults)
  - [5] Page faults (major faults)
  - [6] Swaps
  - [7] Block input operations
  - [8] Block output operations
  - [9] Messages sent
  - [10] Messages received
  - [11] Signals received
  - [12] Voluntary context switches
  - [13] Involuntary context switches

### 2. SLASHSLASH Define

**Purpose**: Enables support for C++ style single-line comments (`//`) in LPC code.

**Files Modified**:
- `src/Makefile` - Adds `-DSLASHSLASH` to DEFINES
- `src/lex/token.cpp` - Implements tokenizer support for // comments

**Implementation**:
When SLASHSLASH is defined, the lexical analyzer recognizes `//` as the start of a single-line comment that extends to the end of the line. This allows LPC code to use both traditional C-style comments (`/* */`) and modern C++ style comments (`//`).

### 3. LARGENUM Define

**Purpose**: Enables support for 64-bit integers in LPC, expanding the numeric range from 32-bit to 64-bit values.

**Files Modified**:
- `src/Makefile` - Adds `-DLARGENUM` to DEFINES
- `src/config.h` - Modifies UINDEX_TYPE to use uint32_t when LARGENUM is defined

**Implementation**:
When LARGENUM is defined:
- `UINDEX_TYPE` is changed from `unsigned short` to `uint32_t`
- `UINDEX_MAX` is changed from `USHRT_MAX` to `UINT32_MAX`
- This allows for a much larger number of objects in the system (from 65,535 to 4,294,967,295)
- LPC integers (`LPCint`) become 64-bit values, supporting a range of -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

**Note**: The LARGENUM implementation in config.h indicates this is specifically for object indexing. The full LARGENUM support throughout the codebase (in files like data.cpp, interpret.cpp, etc.) is part of the upstream DGD code and not a Viking-specific modification.

### 4. Darwin/macOS Build Support

**Purpose**: Fixes C++11 compatibility issues on macOS where the default Apple Clang compiler uses C++98.

**Files Modified**:
- `src/Makefile` - Adds conditional C++11 flag for Darwin

**Implementation**:
```makefile
ifeq ($(HOST),DARWIN)
  CXX+=-std=c++11
endif
```

This ensures that on macOS (Darwin), the compiler uses C++11 standard, which is required for aggregate initialization syntax used in the upstream DGD code (e.g., `summand = { 0, 0 };` in data.cpp).

### 5. Documentation Updates

**Files Modified**:
- `README.md` - Updated to indicate this is VikingMud's modified DGD driver

## Summary of Changes

| Define | Purpose | Impact |
|--------|---------|--------|
| VIKING | Viking-specific kernel functions | Adds rusage() for resource monitoring |
| SLASHSLASH | C++ style comments | Allows // comments in LPC code |
| LARGENUM | 64-bit integer support | Larger object counts and numeric range |
| -std=c++11 | macOS compatibility | Fixes build issues on Darwin |

## Total Changed Files

According to git statistics:
- 7 files changed
- 90 insertions
- 12 deletions

The changes are minimal and focused, making it easier to maintain compatibility with upstream DGD while providing VikingMud-specific functionality.

## Maintenance Notes

When pulling updates from upstream DGD:
1. Most conflicts will likely occur in `src/Makefile` due to the DEFINES changes
2. The viking.cpp file is completely separate and shouldn't conflict
3. The config.h LARGENUM modification may need attention if upstream changes the UINDEX_TYPE definitions
4. The Darwin C++11 flag should be preserved unless upstream adds their own C++11 support