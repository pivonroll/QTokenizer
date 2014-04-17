QT += core

TARGET = QTokenizer
TEMPLATE = lib

DEFINES += QTOKENIZER_LIBRARY

HEADERS += \
    tokenizer.h \
    rule.h \
    rules.h \
    rulematcher.h \
    tokenizer_global.h \
    token.h

SOURCES += \
    tokenizer.cpp \
	rule.cpp \
	rules.cpp \
    rulematcher.cpp \
    token.cpp

unix {
	target.path = /usr/lib
	INSTALLS += target
}
