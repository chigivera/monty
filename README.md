# Monty ByteCode Interpreter

This is a simple interpreter for Monty ByteCode files, written in C. The interpreter reads Monty byte code files and executes the commands within them.

## Description

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (similar to Python). It relies on a unique stack with specific instructions to manipulate it. This project is an interpreter for Monty ByteCode files.

## Getting Started

### Prerequisites
- Ubuntu 20.04 LTS
- gcc compiler
- git

### Installation
```bash
git clone https://github.com/yourusername/monty.git
cd monty
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### Usage
```bash
./monty file
```
Where `file` is the path to the file containing Monty byte code.

## Available Operations

The interpreter supports the following operations:

| Opcode | Description |
|--------|-------------|
| push   | Pushes an element onto the stack |
| pall   | Prints all elements in the stack |
| pint   | Prints the value at the top of the stack |
| pop    | Removes the top element of the stack |
| swap   | Swaps the top two elements of the stack |
| add    | Adds the top two elements of the stack |
| nop    | Does nothing |

## Examples

Example Monty byte code file:
```
push 1
push 2
push 3
pall
```

Output:
```
3
2
1
```

## Error Handling

The interpreter handles various error cases including:
- Invalid instructions
- Stack underflow
- Memory allocation failures
- File open/read errors

## Authors
- Ayman Benchamkha

## License
This project is part of the ALX Software Engineering curriculum.Get started by customizing your environment (defined in the .idx/dev.nix file) with the tools and IDE extensions you'll need for your project!

Learn more at https://developers.google.com/idx/guides/customize-idx-env