A Toolbox for Experimental Computer Science
===========================================

This repository contains small codes that can be useful when developing
codes and designing experiments.

## Codes

Here are the various programs it contains :

### mpi-coords

Source: mpi_coords.c

	mpirun -n N ./mpi-coords

Specific to the Kei Computer MPI implementation.
Provides the 6D coordinates of each MPI process it is executed on.

### mpi-exec

Source mpi_exec.c

	mpirun -n N ./mpi-exec $1

Fork and Exec $1 in every MPI process, passing `comm_rank` and `comm_size`
(in MPI_COMM_WORLD) as arguments.

## Wishlist

- a tool to list the files used to create a binary
- a tool to hash a list of files, and generate a .h C header for it
- a tool to execute a command through MPI, string substitution style
