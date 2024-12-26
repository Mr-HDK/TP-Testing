# Ceedling
plugin :gcov
plugin :cppcheck 

# test/support/rules.mk
test/test_controller.o: test/test_controller.c
        $(CC) $(CFLAGS) $(INCLUDES) -DTEST -DGNU_COMPILER -g -fprofile-arcs -ftest-coverage -c $< -o $@ -MMD -MF $(depfile) 
