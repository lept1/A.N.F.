KEPLER_OBJ = kepler.o ode_lib.o
PENDULUM_OBJ = pendulum.o ode_lib.o
POISSON_OBJ = poisson.o ode_lib.o root_lib.o
WAVE_OBJ = wave.o ode_lib.o root_lib.o
QHO_OBJ = qho.o ode_lib.o root_lib.o
MATRIX_OBJ = matrix.o algebra_lib.o
TRIDIAGONAL_OBJ = tridiagonal.o algebra_lib.o
BVP_OBJ = bvp.o algebra_lib.o
ELLIPTIC_OBJ = elliptic.o algebra_lib.o
POISSONCHARGE_OBJ = poissoncharge.o algebra_lib.o
PROJECT_OBJ = project.o ode_lib.o
PROJECT2_OBJ = project2.o ode_lib.o

CXX=g++
CFLAGS=-c
SRC=$(HOME)/Megasync/Alessandro/libs
VPATH=./:$(SRC)
INCLUDE_DIRS= -I. -I$(SRC)
LDFLAGS = -lm

kepler: $(KEPLER_OBJ)
	$(CXX) $(KEPLER_OBJ) $(LDFLAGS) -o $@

pendulum:$(PENDULUM_OBJ)
	$(CXX) $(PENDULUM_OBJ) $(LDFLAGS) -o $@

poisson:$(POISSON_OBJ)
	$(CXX) $(POISSON_OBJ) $(LDFLAGS) -o $@

wave:$(WAVE_OBJ)
	$(CXX) $(WAVE_OBJ) $(LDFLAGS) -o $@

qho:$(QHO_OBJ)
	$(CXX) $(QHO_OBJ) $(LDFLAGS) -o $@

matrix:$(MATRIX_OBJ)
	$(CXX) $(MATRIX_OBJ) $(LDFLAGS) -o $@

tridiagonal:$(TRIDIAGONAL_OBJ)
	$(CXX) $(TRIDIAGONAL_OBJ) $(LDFLAGS) -o $@

bvp:$(BVP_OBJ)
	$(CXX) $(BVP_OBJ) $(LDFLAGS) -o $@

elliptic:$(ELLIPTIC_OBJ)
	$(CXX) $(ELLIPTIC_OBJ) $(LDFLAGS) -o $@

poissoncharge:$(POISSONCHARGE_OBJ)
	$(CXX) $(POISSONCHARGE_OBJ) $(LDFLAGS) -o $@

project:$(PROJECT_OBJ)
	$(CXX) $(PROJECT_OBJ) $(LDFLAGS) -o $@
	
project2:$(PROJECT2_OBJ)
	$(CXX) $(PROJECT2_OBJ) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE_DIRS) $<


