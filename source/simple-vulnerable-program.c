void bar(char *input) {
        char buf[10];

        strcpy(buf, input);
        return;
}

void foo(char *input) {
    bar(input);
    return;
}

int main(int argc, char **argv) {
    foo(argv[1]);
    return 0;
}
