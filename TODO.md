# COOL Compiler in C - Learning-Oriented Checklist

This checklist is ordered for understanding, not speed. Each stage should teach one idea before moving to the next.

## 0. Ground Rules
- Build this in C.
- Prefer small, working programs over large unfinished systems.
- Do not add a feature until you can explain what problem it solves.
- Keep notes on what each compiler phase receives as input and produces as output.

## 1. Project Basics
Learning goal: understand how a C project is organized and compiled.

- Create directory structure:
  - `src/`
  - `include/`
  - `tests/`
  - `examples/`
- Create the smallest possible `Makefile`.
- Learn what each Makefile line does:
  - compiler variable
  - compiler flags
  - target
  - dependency
  - recipe
  - `clean`
- Create a tiny `main.c` that only proves the build works.

Checkpoint:
- You can run `make`.
- You can explain how `src/main.c` becomes an executable.
- You can run the executable from the terminal.

## 2. Basic Diagnostics
Learning goal: understand how compilers report errors.

- Create a `SourceLocation` type:
  - filename
  - line
  - column
- Create a function that prints an error message to `stderr`.
- Use one consistent format:
  - `file.cl:line:column: error: message`
- Call the error function manually from `main.c` to test it.

Checkpoint:
- You can explain why compiler errors need source locations.
- You can explain the difference between `stdout` and `stderr`.
- You can print one error without involving the lexer yet.

## 3. Lexer Experiment With a Hardcoded String
Learning goal: understand what tokenization is before dealing with files.

- Put a COOL source string directly in C:
  - `class Main { };`
- Scan the string one character at a time.
- Recognize a very small set of tokens:
  - `class`
  - type identifiers like `Main`
  - `{`
  - `}`
  - `;`
  - end of file
- Print each token.

Checkpoint:
- You can explain the difference between characters and tokens.
- You can explain why whitespace is usually skipped.
- You can tokenize `class Main { };`.

## 4. Token Data Structures
Learning goal: represent lexer output cleanly in C.

- Create a `TokenType` enum.
- Create a `Token` struct:
  - token type
  - lexeme/start pointer or copied text
  - source location
- Write a function that converts token types to readable names.

Checkpoint:
- You can explain why an enum is better than using raw integers.
- You can print tokens in a readable format.

## 5. Expand the Lexer Slowly
Learning goal: handle real COOL syntax piece by piece.

- Add identifiers.
- Add integer literals.
- Add string literals.
- Add keywords.
- Add punctuation.
- Add operators.
- Add line and column tracking.
- Add comments.
- Add nested comments.
- Add malformed string errors.
- Add illegal character errors.

Checkpoint:
- You can explain how the lexer decides what kind of token starts at the current character.
- You can explain how line and column tracking works.
- You can produce useful lexer errors.

## 6. Lexer Tests
Learning goal: make small behavior checkable.

- Add example input files in `tests/lexer/`.
- Test valid programs.
- Test malformed strings.
- Test nested comments.
- Test illegal characters.
- Compare actual token output with expected output.

Checkpoint:
- You can change the lexer and quickly know whether you broke something.

## 7. File Input and Simple CLI
Learning goal: connect the lexer to real source files.

- Read a `.cl` file into memory.
- Pass the file contents to the lexer.
- Add a minimal CLI:
  - `coolc input.cl`
- Add a debug flag later:
  - `coolc --tokens input.cl`

Checkpoint:
- You can run your lexer on files from `examples/`.
- You understand `argc` and `argv`.

## 8. Parser Basics
Learning goal: understand how tokens become structure.

- Parse the smallest valid COOL class:
  - `class Main { };`
- Start with simple recursive descent functions.
- Report parser errors using source locations.

Checkpoint:
- You can explain the difference between lexer errors and parser errors.
- You can explain what grammar rule your parser is implementing.

## 9. AST Basics
Learning goal: store parsed program structure in memory.

- Create C structs for:
  - program
  - class
  - feature
  - method
  - attribute
  - expression
- Add source locations to AST nodes.
- Write constructors only when they make code clearer.

Checkpoint:
- You can explain why the parser should build an AST instead of just printing as it parses.

## 10. AST Printer
Learning goal: inspect parser output.

- Print the AST in a stable readable format.
- Add an `--ast` debug flag eventually.
- Compare AST output against expected files.

Checkpoint:
- You can look at a COOL program and its AST output and see how they correspond.

## 11. Parser Growth
Learning goal: implement the grammar in manageable pieces.

- Add class declarations.
- Add methods.
- Add attributes.
- Add basic expressions.
- Add operator precedence.
- Add:
  - `if`
  - `while`
  - `let`
  - `case`
  - dispatch

Checkpoint:
- You can parse meaningful COOL programs.
- You can explain where precedence is handled.

## 12. Symbol Table
Learning goal: understand scopes and name lookup.

- Create a scoped symbol table.
- Support:
  - enter scope
  - exit scope
  - insert name
  - lookup name
- Start with a simple linked-list implementation before optimizing.

Checkpoint:
- You can explain why `let x` inside one scope should not affect another scope.

## 13. Inheritance Graph
Learning goal: understand class relationships.

- Collect all class names.
- Reject duplicate classes.
- Reject illegal inheritance.
- Detect inheritance cycles.
- Verify `Main` exists.
- Verify `Main.main()` exists.

Checkpoint:
- You can draw the inheritance graph for a small program.

## 14. Type System Basics
Learning goal: understand how COOL decides expression types.

- Add built-in classes:
  - `Object`
  - `IO`
  - `Int`
  - `Bool`
  - `String`
- Store method signatures.
- Store attribute types.
- Learn how `SELF_TYPE` works before implementing all cases.

Checkpoint:
- You can explain the type of simple expressions.

## 15. Semantic Analysis
Learning goal: catch meaning-level errors after parsing succeeds.

- Undefined identifiers.
- Assignment type checks.
- Method call checks.
- Return type checks.
- `if` branch join types.
- `case` branch checks.
- `let` scope rules.
- Override rules.

Checkpoint:
- You can explain why a syntactically valid program can still be semantically invalid.

## 16. Semantic Tests
Learning goal: test each rule independently.

- One test per semantic error type.
- Valid inheritance examples.
- Invalid inheritance examples.
- Valid dispatch examples.
- Invalid dispatch examples.

Checkpoint:
- You can intentionally break one semantic rule and see one clear test fail.

## 17. Choose a Backend Strategy
Learning goal: decide what your compiler emits.

Choose one:
- Generate C.
- Generate LLVM IR.
- Generate MIPS-like assembly.

For learning, generating C may be the most approachable first backend.

Checkpoint:
- You can explain what your compiler's output language is and why you chose it.

## 18. Intermediate Representation
Learning goal: avoid generating final code directly from the AST.

- Define simple IR instructions.
- Define temporaries.
- Define labels.
- Convert AST expressions into IR.

Checkpoint:
- You can explain why IR can make code generation easier.

## 19. Runtime Layout
Learning goal: understand how objects exist at runtime.

- Object headers.
- Class tags.
- Dispatch tables.
- Attribute layout.
- String constants.
- Int constants.
- Bool constants.

Checkpoint:
- You can draw what one object looks like in memory.

## 20. Code Generation
Learning goal: turn checked programs into executable behavior.

- Literals.
- Arithmetic.
- Comparisons.
- Assignments.
- Object creation.
- Dispatch.
- Conditionals.
- Loops.
- `case`.
- `let`.

Checkpoint:
- You can compile and run a tiny COOL program.

## 21. Runtime Support
Learning goal: provide the functions generated code depends on.

- Memory allocation.
- Basic IO.
- String operations.
- Abort/error routines.
- Optional garbage collection later.

Checkpoint:
- Generated programs can call basic runtime functions.

## 22. End-to-End Tests
Learning goal: test the whole compiler pipeline.

- Compile tiny COOL programs.
- Run expected output tests.
- Test semantic failures.
- Test parser failures.
- Test lexer failures.

Checkpoint:
- You trust the compiler on small programs.

## 23. Debug Tools
Learning goal: make the compiler easier to inspect.

- `--tokens`
- `--ast`
- `--types`
- `--ir`
- `--verbose-errors`

Checkpoint:
- You can inspect each major compiler phase independently.

## 24. Polish
Learning goal: improve the project without changing its core design.

- Better diagnostics.
- Cleaner memory cleanup.
- Documentation.
- Sample COOL programs.
- README with build/run instructions.
