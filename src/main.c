#include <stdio.h>
#include "lexer.h"
#include "token.h"

int main(void){
    const char *source =
        "-- Lexer regression: exercises every token type.\n"
        "(* Nested (* block *) comment. *)\n"
        "\n"
        "class Counter inherits Object {\n"
        "    count  : Int;\n"
        "    label  : String;\n"
        "    active : Bool;\n"
        "\n"
        "    init(n : Int, s : String) : Counter {\n"
        "        {\n"
        "            count  <- n;\n"
        "            label  <- s;\n"
        "            active <- true;\n"
        "            self;\n"
        "        }\n"
        "    };\n"
        "\n"
        "    tick()            : Int  { count <- count + 1 };\n"
        "    shrink()          : Int  { count <- count - 1 };\n"
        "    scale(f : Int)    : Int  { count <- count * f };\n"
        "    halve()           : Int  { count <- count / 2 };\n"
        "    negate()          : Int  { ~count };\n"
        "\n"
        "    is_zero()         : Bool { count = 0 };\n"
        "    below(hi : Int)   : Bool { count < hi };\n"
        "    above(lo : Int)   : Bool { count > lo };\n"
        "    at_most(x : Int)  : Bool { count <= x };\n"
        "    at_least(x : Int) : Bool { count >= x };\n"
        "    is_empty()        : Bool { isvoid label };\n"
        "\n"
        "    describe() : String {\n"
        "        let msg : String <- \"line1\\nline2\\t\\\"quoted\\\"\\\\end\" in\n"
        "            msg\n"
        "    };\n"
        "\n"
        "    check() : Int {\n"
        "        if active then count else ~count fi\n"
        "    };\n"
        "\n"
        "    classify() : String {\n"
        "        case count of\n"
        "            x : Int  => \"integer\";\n"
        "            b : Bool => \"boolean\";\n"
        "        esac\n"
        "    };\n"
        "\n"
        "    run() : Object {\n"
        "        while not (count < 10) = false loop\n"
        "            count <- count + 1\n"
        "        pool\n"
        "    };\n"
        "\n"
        "    make() : Counter { new Counter };\n"
        "\n"
        "    combo() : Int {\n"
        "        let a : Int <- 3,\n"
        "            b : Int <- 7 in\n"
        "            a + b\n"
        "    };\n"
        "\n"
        "    static_dispatch() : Counter {\n"
        "        self@Counter.init(0, \"reset\")\n"
        "    };\n"
        "};\n"
        "\n"
        "class Main {\n"
        "    x    : Int;\n"
        "    flag : Bool;\n"
        "\n"
        "    main() : Object {\n"
        "        {\n"
        "            x    <- 42;\n"
        "            flag <- false;\n"
        "            x;\n"
        "        }\n"
        "    };\n"
        "};\n";

    Lexer lexer;
    lexer_init(&lexer, source);

    while(1) {
        Token token = lexer_next_token(&lexer);

        const char* token_type = token_type_name(token.type);

        printf("%s '%.*s'\n",
            token_type,
            token.length,
            token.start);

        if (token.type == TOKEN_EOF){
            return 0;
        }  
    }



    return 0;

    
}