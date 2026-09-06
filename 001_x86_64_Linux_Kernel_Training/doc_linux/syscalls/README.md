# `man syscalls`


```
syscalls(2)                                                      System Calls Manual                                                      syscalls(2)

NAME
       syscalls - Linux system calls

SYNOPSIS
       Linux system calls.

DESCRIPTION
       The system call is the fundamental interface between an application and the Linux kernel.

   System calls and library wrapper functions
       System  calls  are  generally not invoked directly, but rather via wrapper functions in glibc (or perhaps some other library).  For details of
       direct invocation of a system call, see intro(2).  Often, but not always, the name of the wrapper function is the same as the name of the sys‐
       tem call that it invokes.  For example, glibc contains a function chdir() which invokes the underlying "chdir" system call.

       Often the glibc wrapper function is quite thin, doing little work other than copying arguments to the right registers before invoking the sys‐
       tem call, and then setting errno appropriately after the system call  has  returned.   (These  are  the  same  steps  that  are  performed  by
       syscall(2), which can be used to invoke system calls for which no wrapper function is provided.)  Note: system calls indicate a failure by re‐
       turning  a negative error number to the caller on architectures without a separate error register/flag, as noted in syscall(2); when this hap‐
       pens, the wrapper function negates the returned error number (to make it positive), copies it to errno, and returns -1 to the  caller  of  the
       wrapper.

       Sometimes,  however,  the wrapper function does some extra work before invoking the system call.  For example, nowadays there are (for reasons
       described below) two related system calls, truncate(2) and truncate64(2), and the glibc truncate() wrapper function checks which of those sys‐
       tem calls are provided by the kernel and determines which should be employed.
```
