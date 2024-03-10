# Define package properties
AESD_ASSIGNMENTS_VERSION = 1.0
AESD_ASSIGNMENTS_SITE = $(TOPDIR)/../path/to/your/aesd-assignments
AESD_ASSIGNMENTS_SITE_METHOD = local

# Define build and install commands
define AESD_ASSIGNMENTS_BUILD_CMDS
    $(MAKE) -C $(@D)
endef

define AESD_ASSIGNMENTS_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/finder-test.sh $(TARGET_DIR)/usr/bin/finder-test.sh
endef

# Register the package in Buildroot
$(eval $(generic-package))
