mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS +=
APPL_LIBS += -lm
APPL_DIRS += \
	$(mkfile_path)app
INCLUDES += \
	-I$(mkfile_path)app
