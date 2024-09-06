TEMPLATE = subdirs

SUBDIRS = src

contains(CONFIG, BUILD_EXAMPLES) {
    SUBDIRS += examples
    examples.depends += src
}
