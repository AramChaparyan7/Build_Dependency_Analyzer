CXX = g++
CXXFLAGS = -std=c++20 -Iincludes

SRCDIR = source
OBJDIR = obj
TARGET = a.out

SRC = $(SRCDIR)/MiniBuild.cpp $(SRCDIR)/graph.cpp
OBJ = $(OBJDIR)/MiniBuild.o $(OBJDIR)/graph.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET) input.txt
