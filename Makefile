coolc: src/main.c src/token.c src/lexer.c
	cc -std=c11 -Wall -Wextra -Iinclude src/main.c src/token.c src/lexer.c -o coolc

clean:
	rm -f coolc