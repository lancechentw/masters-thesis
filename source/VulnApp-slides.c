void foo(char *input) {
    char buf[15];
    strcpy(buf, input);
    printf("%s", buf);
}

JNIEXPORT jint JNICALL Java_sqlab_craxdroid_vulnapp_VulnApp_main
  (JNIEnv *env, jclass class) {
    file = open("/data/local/tmp/input", O_RDONLY);
    char *buf = (char*) malloc(buffer.st_size);
    if (buf != NULL) {
        if ((n = read(file, buf, buffer.st_size)) > 0) {
            foo(buf);
        }
        free(buf);
    }
    close(file);
}
