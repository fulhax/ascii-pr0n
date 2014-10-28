BASE_DIR=$(abspath $(dir $(lastword $(MAKEFILE_LIST))))

BUILD_DIR=${BASE_DIR}/build/

BUILD_TYPE=debug
BUILD_INFO=Debug
ifdef RELEASE_DBG_INFO
	BUILD_TYPE=release_dbg_info
	BUILD_INFO=RelWithDebInfo
	export RELEASE_DBG_INFO=1
endif
ifdef RELEASE
	BUILD_TYPE=release
	BUILD_INFO=Release
	export RELEASE=1
endif
PLATFORM_LIST=default
ifdef PLATFORM
	PLATFORM_LIST=${PLATFORM}
endif

.PHONY: all linux cleanAll clean

all: linux

linux: ${BUILD_DIR}/linux/${BUILD_TYPE}/Makefile
	$(MAKE) -C $(shell dirname $<)


${BUILD_DIR}/linux/${BUILD_TYPE}/Makefile: CMakeLists.txt
	@mkdir -p $(shell dirname $@)
	cd $(shell dirname $@) && CC=$(shell which clang) CXX=$(shell which clang++) cmake -DCMAKE_BUILD_TYPE=${BUILD_INFO} -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ${BASE_DIR}


clean: ${BUILD_DIR}/linux/${BUILD_TYPE}/Makefile
	$(MAKE) -C $(shell dirname $<) clean

distclean:
	@rm -rf ${BUILD_DIR}/

