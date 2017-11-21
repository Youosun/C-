INC_DIR := ./
SRC_DIR := ./
SRCS:=$(wildcard ./*.cc)
OBJS:=$(patsubst ./%.cc, %.o, %(wildcard ./*.cc))
LIBS:=-lpthread

CXX:=g++

CXXFLAGS:= -w -g -std=c++0x $(addprefix -I, $(INC_DIR)) $(LIBS) -Wno-deprecated

EXE:=./server

$(EXE):$(SRCS)
	$(CXX) -o $(EXE) $(SRCS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)

