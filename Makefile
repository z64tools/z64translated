include setup.mk

CFLAGS          = -g -Ofast -Wall -DEXTLIB=220 -I src/
SOURCE_C        = $(shell find src/* -type f -name '*.c')
SOURCE_O_LINUX := $(foreach f,$(SOURCE_C:.c=.o),bin/linux/$f)
SOURCE_O_WIN32 := $(foreach f,$(SOURCE_C:.c=.o),bin/win32/$f)

RELEASE_EXECUTABLE_LINUX := z64translated
RELEASE_EXECUTABLE_WIN32 := z64translated.exe

# Make build directories
$(shell mkdir -p bin/ $(foreach dir, \
	$(dir $(SOURCE_O_WIN32)) \
	$(dir $(SOURCE_O_LINUX)) \
	$(dir $(RELEASE_EXECUTABLE_LINUX)) \
	$(dir $(RELEASE_EXECUTABLE_WIN32)) \
	, $(dir)))

.PHONY: default \
		linux \
		win32 \
		clean

default: linux
all: linux win32
linux: $(RELEASE_EXECUTABLE_LINUX)
win32: $(RELEASE_EXECUTABLE_WIN32)

clean:
	rm -rf bin
	rm -f $(RELEASE_EXECUTABLE_LINUX)
	rm -f $(RELEASE_EXECUTABLE_WIN32)

include $(PATH_EXTLIB)ext_lib.mk

# # # # # # # # # # # # # # # # # # # #
# LINUX BUILD                         #
# # # # # # # # # # # # # # # # # # # #

-include $(SOURCE_O_LINUX:.o=.d)

$(RELEASE_EXECUTABLE_LINUX): $(SOURCE_O_LINUX) $(ExtLib_Linux_O)
	@echo "$(PRNT_RSET)[$(PRNT_PRPL)$(notdir $@)$(PRNT_RSET)] [$(PRNT_PRPL)$(notdir $^)$(PRNT_RSET)]"
	@gcc -o $@ $^ $(XFLAGS)

# # # # # # # # # # # # # # # # # # # #
# WIN32 BUILD                         #
# # # # # # # # # # # # # # # # # # # #

-include $(SOURCE_O_WIN32:.o=.d)

$(RELEASE_EXECUTABLE_WIN32): bin/win32/icon.o $(SOURCE_O_WIN32) $(ExtLib_Win32_O)
	@echo "$(PRNT_RSET)[$(PRNT_PRPL)$(notdir $@)$(PRNT_RSET)] [$(PRNT_PRPL)$(notdir $^)$(PRNT_RSET)]"
	@i686-w64-mingw32.static-gcc -o $@ $^ $(XFLAGS) $(CFLAGS) -D_WIN32
