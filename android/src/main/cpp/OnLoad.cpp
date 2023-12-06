#include <fbjni/fbjni.h>

#include "MarkdownUtils.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    return facebook::jni::initialize(
            vm, [] { markdowntextinput::MarkdownUtils::registerNatives(); });
}