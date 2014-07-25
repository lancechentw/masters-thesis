/* reading rc file, handling missing options */
int getConfig(char settings[MAX_SETTINGS][MAX_LEN])
{
    char home[MAX_LEN];
    FILE *fp;
    int numSet = 0;

    strcpy(home, getenv("HOME"));
    strcat(home, "/.aeonrc");
    fp = fopen(home, "r");
    if (fp == NULL) return -1;
    while (fgets(settings[numSet], MAX_LEN-1, fp) && (numSet < MAX_SETTINGS)) numSet++;
    fclose(fp);

    return numSet;
}
