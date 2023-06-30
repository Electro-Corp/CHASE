# Getting Started with CHASE

## Enviorment Setup

To get started, we need to setup our enviorment. Since some details are build system dependent, we'll be going over the general idea. 

You need:
* chase.so or chase.dll (depending on your OS)
* The source code for CHASE

To compile with CHASE, include the proper headers and add chase.dll (or chase.so) to the files you compile.

## Basic program

First, we import `chase.h`.

```
#include <chase.h>
```

Then, inside our main or whatever function you want (here we use main), we call the init function.

```
int main() {
	Chase::init();
}
```
