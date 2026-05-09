# COOL Compiler in C — Full Implementation Checklist

## 1. Project Setup
- Create directory structure:
  - `src/`
  - `include/`
  - `tests/`
  - `examples/`
- Create `Makefile`
- Add basic error reporting
- Add CLI:
  - `coolc input.cl`

## 2. Lexer
- Keywords
- Identifiers
- Integers
- Strings
- Comments
- Operators
- Punctuation
- Line tracking
- Column tracking

## 3. Token Tests
- Valid programs
- Malformed strings
- Nested comments
- Illegal characters

## 4. Parser
- COOL grammar
- Operator precedence
- Class declarations
- Methods
- Attributes
- Expressions:
  - `if`
  - `while`
  - `let`
  - `case`
  - dispatch

## 5. AST
- C structs for every node type
- Constructors like:
  - `ast_new_class(...)`
  - `ast_new_method(...)`
  - `ast_new_expr(...)`
- Linked lists or dynamic arrays
- Source locations on every node

## 6. AST Printer
- Print parsed tree
- Compare output against expected test files

## 7. Symbol Table
- Scoped hash map
- `enter_scope`
- `exit_scope`
- `insert`
- `lookup`

## 8. Inheritance Graph
- Collect classes
- Reject duplicate classes
- Reject illegal inheritance
- Detect cycles
- Verify `Main` exists
- Verify `Main.main()` exists

## 9. Type System Basics
- Built-in classes:
  - `Object`
  - `IO`
  - `Int`
  - `Bool`
  - `String`
- Method signatures
- Attribute types
- `SELF_TYPE`

## 10. Semantic Analyzer
- Undefined identifiers
- Assignment type checks
- Method call checks
- Return type checks
- `if` branch join types
- `case` branch checks
- `let` scope rules
- Override rules

## 11. Semantic Test Suite
- One test per error type
- Valid inheritance examples
- Invalid inheritance examples
- Valid dispatch examples
- Invalid dispatch examples

## 12. Intermediate Representation
Choose one:
- Generate C
- Generate LLVM IR
- Generate MIPS-like assembly

Define:
- IR instructions
- Temporaries
- Labels

## 13. Runtime Layout
- Object headers
- Class tags
- Dispatch tables
- Attribute layout
- String constants
- Int constants
- Bool constants

## 14. Code Generation
- Literals
- Arithmetic
- Comparisons
- Assignments
- Object creation
- Dispatch
- Conditionals
- Loops
- `case`
- `let`

## 15. Runtime Support
- Memory allocation
- Basic IO
- String operations
- Abort/error routines
- Optional garbage collection later

## 16. End-to-End Tests
- Compile tiny COOL programs
- Run expected output tests
- Test semantic failures
- Test parser failures

## 17. Debug Tools
- `--tokens`
- `--ast`
- `--types`
- `--ir`
- `--verbose-errors`

## 18. Polish
- Better diagnostics
- Cleaner memory cleanup
- Documentation
- Sample COOL programs
- README with build/run instructions