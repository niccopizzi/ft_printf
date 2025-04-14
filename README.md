# ft_printf  
Printf project for 42

This project is one of the 3 projects, alongside get_next_line and Born2beRoot, that make the Rank01 of the Common Core and is about recreating your own version of printf.

IMPORTANT CONCEPTS :

- Variadic functions

In C, functions usually have a set number of arguments. For example, the write function takes 3 arguments: the file descriptor where to write (fd), the buffer to write, and the number of bytes to write. All good, but this assumes that we know before running our program the number of arguments we need to pass to the function; sometimes this is not true.

Let's suppose we have a function 

```c
int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}
```

This can compare only 2 numbers at a time, so if we need to compare 3 numbers (a, b, c) instead of 2 we either do some tricks like `max(a, max(b, c))` or create a new function

```c
int max_of_three(int a, int b, int c)
```

which does the job.

But what if we need 4? Or what if we have the user input an unknown number of numbers and we have to return the max between them?  
Here is where variadic functions will save our day.  
To put it as simply as possible: variadic functions are functions with a variable number of arguments, that's it.  
To make a function variadic all we need is:

1) Include the stdarg header -> `#include <stdarg.h>`

2) Declare the function as variadic using the 3 dots notation -> `int max(int args_num, ...)`  
   (keep in mind that to work properly variadic functions should have at least one fixed argument — `int args_num` in this case — before the variable arguments, we'll see later why).

And that's it, the max function is now variadic and can take as many integers as you want.  
But wait, there's no indication on what the type of arguments passed to the function is, only dots! How can the computer understand the type of the arguments? This is where the stdarg library comes into play and that's why we need to include its header. Let's take a look at it.

The library provides the type `va_list` which is the type of the variable that will keep track of the variable arguments. In the implementation of max it would look like

```c
int max(int args_num, ...)
{
    va_list list;
    // ...
}
```

What is `va_list`? `va_list` is a struct with the following implementation

```c
typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} va_list[1];
```

(source: https://raw.githubusercontent.com/wiki/hjl-tools/x86-psABI/x86-64-psABI-1.0.pdf)

And to initialize properly this struct we need to call the `va_start` macro with the `va_list` variable and the first argument of the function:

```c
va_start(list, args_num);
```

Why do we need to pass also the fixed argument to this macro? Simply because all the arguments were put on the stack at the moment we called max, and to retrieve the unknown variadic parameters we need to know where to start looking for them; that's why we pass the first fixed parameter to this macro.

`va_start` will then initialize our `va_list` in this way:

- **reg_save_area**     -> Points to the start of the register save area  
- **overflow_arg_area** -> Initialized with the address of the first argument passed on the stack and then always points to the start of the next argument on the stack.  
- **gp_offset**         -> Offset in bytes from `reg_save_area` to the place where the next available general purpose argument register is saved.  
- **fp_offset**         -> Offset in bytes from `reg_save_area` to the place where the next available floating point argument register is saved.

Adding this to the code of max:

```c
int max(int args_num, ...)
{
    va_list list;

    va_start(list, args_num);
    // ...
}
```

Now that we have properly initialized the list we can start to fetch the arguments by calling the macro `va_arg`. We need to pass to this macro two parameters: the list we are using and the type of the parameter we are fetching. What this macro will do is check how many bytes the parameter occupies and locate the proper registers to fetch it. In assembly code a possible implementation of `va_arg` looks like this:

```
    movl list->gp_offset, %eax
    cmpl $48, %eax          ; Is register available?
    jae stack               ; If not, use stack
    leal 8(%rax), %edx      ; Next available register
    addq list->reg_save_area, %rax   ; Address of saved register
    movl %edx, list->gp_offset       ; Update gp_offset
    jmp fetch
stack:
    movq list->overflow_arg_area, %rax   ; Address of stack slot
    leaq 8(%rax), %rdx                   ; Next available stack slot
    movq %rdx, list->overflow_arg_area   ; Update
fetch:
    movl (%rax), %eax                   ; Load argument
```

Since `va_arg` needs to find the correct register to store the argument, it is crucial to call this function with the correct type. Failing to do so would make this macro store our argument in the wrong register which will most likely corrupt our data.

Once all the arguments were fetched, `va_end` is called to clear things up and tell the computer we are done using the list.  
Putting all together, max function would look like:

```c
int max(int args_num, ...)
{
    va_list list;
    int     fetched_num;
    int     max_num;

    va_start(list, args_num);
    for (int i = 0; i < args_num; i++)
    {   
        fetched_num = va_arg(list, int);
        // Compute the max number
    }
    va_end(list);
    return (max_num);
}
```

Main topics to research:

- How functions are called in assembly  
- How arguments are passed to functions  
- How stack works

Thank you for taking the time to read this!  
If you find any mistakes or typos, don’t hesitate to reach out!
