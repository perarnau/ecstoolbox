all: mpi-exec

mpi-exec: mpi_exec.c
	mpicc -o $@ $^

mpi-coords: mpi_coords.c
	mpifccpx -o $@ $^
