AM_CFLAGS=-g -mbig-endian
AM_CCASFLAGS=-mbig-endian
AM_LDFLAGS=-nostdlib -T $(srcdir)/linker_script -n --entry main
AM_LDFLAGS+=-Wl,-EB

if HAVE_ARM_COMPILER

noinst_PROGRAMS=example1 example2 example3 example4 example5 example6 example7 insertion_sort


all-am: $(PROGS)
endif

example1_SOURCES=example1.s
example2_SOURCES=example2.s
example3_SOURCES=example3.s
example4_SOURCES=example4.s
example5_SOURCES=example5.s
example6_SOURCES=example6.s
example7_SOURCES=example7.s
insertion_sort_SOURCES=insertion_sort.c

EXTRA_DIST=linker_script

clean-local:
	$(RM) $(PROGS)
