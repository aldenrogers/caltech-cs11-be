#!/bin/sh
gcc -o hello_world hello_world.c
objdump -D hello_world > hello_world.dump
