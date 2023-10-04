BASE_DIR=$(abspath $(dir $(lastword $(MAKEFILE_LIST))))

BUILD_DIR=${BASE_DIR}/build/

.PHONY: all debug release clean distclean

all: release
debug release:  %: $(BUILD_DIR)/%/Makefile
	$(MAKE) -C $(shell dirname $<)

$(BUILD_DIR)/%/Makefile:
	$(eval BUILD_TYPE:=$(shell dirname $@ | xargs -n1 basename))
	mkdir -p $(shell dirname $@)
	cd $(shell dirname $@) && cmake  -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=$(BUILD_INFO_$(BUILD_TYPE))  ${BASE_DIR}


clean: ${BUILD_DIR}/linux/${BUILD_TYPE}/Makefile
	$(MAKE) -C $(shell dirname $<) clean

distclean:
	@rm -rf ${BUILD_DIR}/
