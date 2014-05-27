#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void foo(char *input) {
    char buf[15];

    strcpy(buf, input);
    printf("%s", buf);

    return;
}

JNIEXPORT jint JNICALL Java_sqlab_craxdroid_vulnapp2_VulnApp_main
  (JNIEnv *env, jclass class, jstring content) {
    char* buf = (*env)->GetStringUTFChars(env, content, NULL);

    foo(buf);

    return 0;
}

