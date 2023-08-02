# 0x19. C - Stacks, Queues - LIFO, FIFO
![CFYYWy6UEAE9Ow-](https://github.com/elyse502/monty/assets/125453474/e57576cd-8997-4bbb-b8b8-f8a58141a5d0)
## RESOURCES 📚
### Read or watch:
* [Google](https://www.google.com/search?q=stack+and+queue&source=hp&ei=eXGRZN6qAe6ikdUPgtWboA8&iflsig=AOEireoAAAAAZJF_iSTpnU5ZtJY3Pd6K9B6mp61Yvc3h&ved=0ahUKEwiey9PNxNH_AhVuUaQEHYLqBvQQ4dUDCAk&uact=5&oq=stack+and+queue&gs_lcp=Cgdnd3Mtd2l6EANQAFgAYABoAHAAeACAAQCIAQCSAQCYAQA&sclient=gws-wiz)
* [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
* [Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
* [Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)
* [Queue operations](https://www.edureka.co/blog/queue-in-c/)

### GitHub
__There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.__

# More Info
#### Data structures
Please use the following data structures for this project. Don’t forget to include them in your header file.
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
# Compilation & Output📤
* Your code will be compiled this way:
````
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
````
* Any output must be printed on `stdout`
* Any error message must be printed on `stderr`
  * [Here is a link to a GitHub repository](https://github.com/sickill/stderred) that could help you making sure your errors are printed on `stderr`

## Tests
We strongly encourage you to work all together on a set of tests

# Monty interpreter🧩
![monty](https://github.com/elyse502/monty/assets/125453474/218a07c2-f636-4fd8-a283-d04574f61c70)

# The Monty language🗣️🔊🔉
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
#### Monty byte code files🗃️

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
# The monty program🖥️

* Usage: `monty file`
  * where `file` is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
where `<file>` is the name of the file
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  * where is the line number where the instruction appears.
  * Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
  * it executed properly every line of the file
  * it finds an error in the file
  * an error occured
* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
* You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

# Tasks 📃
## 0. push, pall: [monty](https://github.com/elyse502/monty/tree/master)
Implement the `push` and `pall` opcodes.

### The push opcode
The opcode `push` pushes an element to the stack.
* Usage: `push <int>`
  * where `<int>` is an integer
* if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
  * where is the line number in the file
* You won’t have to deal with overflows. Use the `atoi` function
### The pall opcode
The opcode ``pall`` prints all the values on the stack, starting from the top of the stack.
* Usage `pall`
* Format: see example
* If the stack is empty, don’t print anything
````
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
````
## 1. pint: [monty](https://github.com/elyse502/monty/tree/master)
Implement the `pint` opcode.
### The pint opcode
The opcode `pint` prints the value at the top of the stack, followed by a new line.
* Usage: `pint`
* If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`
```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```



## AUTHOR📝
*__NIYIBIZI Elysée__ | [Linkedin](https://www.linkedin.com/in/niyibizi-elys%C3%A9e/).*

![239912022-2d08e450-0f63-4979-89cc-1c377d48c32a](https://github.com/elyse502/RSA-Factoring-Challenge/assets/125453474/fb0fa029-506d-4534-968f-707eaa4fdd83)
