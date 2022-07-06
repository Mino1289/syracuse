CC = gcc
CFLAGS = -Wall -Werror -Wextra -fpic -pedantic
LIBSDIR = -L.
INCLUDEDIR = -I.

LIBCORENAME = syracuse

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb -DDEBUG 
endif

ifeq ($(OS), Windows_NT)
	EXPORT = export.bat
	LIBTARGET :=$(LIBCORENAME:=.dll)
	CLEANCMD = @del /q *.o *.dll *.exe *.so syracuse.py
else
	EXPORT = sh export.sh
	LIBTARGET :=lib$(LIBCORENAME:=.so)
	LIBSDIR += -L/usr/lib
	INCLUDEDIR += -I/usr/include
	CLEANCMD = rm -rf *.o *.so *.exe *.dll syracuse.py
endif

LIBSOURCE = syracuse 
LIBSOURCECFILE = $(LIBSOURCE:=.c)
LIBSOURCEOFILE = $(LIBSOURCE:=.o)

EXESOURCE = main
TARGET = $(EXESOURCE:=.exe)
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

all: $(TARGET)

run: $(TARGET)
	$(EXPORT) $(TARGET)

$(TARGET): $(EXESOURCEOFILE) $(LIBTARGET) 
	$(CC) $(EXESOURCEOFILE) -l$(LIBCORENAME) $(LIBSDIR) -o $(TARGET) -lm

$(LIBTARGET): $(LIBSOURCEOFILE) 
	$(CC) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o $(LIBTARGET)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

clean: 
	$(CLEANCMD)
	@echo CLEAN