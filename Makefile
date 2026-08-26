coolc: src/main.c src/token.c src/lexer.c src/parser.c
	cc -std=c11 -Wall -Wextra -Iinclude src/main.c src/token.c src/lexer.c src/parser.c -o coolc

clean:
	rm -f coolc

test: coolc
	./coolc | diff tests/lexer/counter.expected - 