# C Experiments

These are stand alone files that demonstrate some concept I'm not sure about.

## heap.c
How far can we go without using malloc? Can you allocate something on the stack in a subroutine, return the pointer to the caller, and still have access to it?

In this case, it's a little surprising: You'll get a segfault, rather than UB or something. 

## introspect.c
This file attempts to empirically answer the question of what stack structure looks like. Is there metadata mapping names to locations on the stack or are these resolved at compile time? This turns out to be a lot harder to verify.

Compile introspect and run it with an integer argument to see stack addresses. The first stack address is the location of the 'main' pointer reference, and all the rest are locations of subroutine calls named 'subr'. See the file for more details, although admittedly there's a lot of stray comments in there as of now.

## mutate.c

If there is a function that takes a struct alloc'd on the heap (or otherwise in the stack of the calling function), there is no need to return anything beyond success/failure. In Python, if something fails an exception is raised, a notable distinction between it and C: C doesn't have exceptions. The reason I mention this is that one convenient use for functions like these are return values that signify if the mutation succeeded.

## noice.c
Schedulers nowadays do not modify nice values. Nice values determine priorities in the scheduler. This does not mean that their priorities also remain static (and thus their execution allotments), but as far as I can tell they are.

If you're running a POSIX compliant OS that is running something like an MLFQ that does modify nice values, this'll let you know what modifications it makes at what nanoseconds, relative to the start of the program, if it spins constantly and uses the entirety of a processor quantum.

## null.c
Who's on null? The world may never know.


## segfault.c
Decrement a pointer, printing it out until the OS sends us sigsegv. This is a bad thing™ 

## simple.c
Does no IO or has any header files, simply here to illustrate base elements of an obj file for disassembly.
