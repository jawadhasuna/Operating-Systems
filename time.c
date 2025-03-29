void log_history(int argc, char* argv[]) {
    FILE* file = fopen("history.log", "a");
    if (!file) return;

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    fprintf(file, "%02d-%02d-%d:%02d:%02d:%02d ",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec);

    for (int i = 0; i < argc; i++)
        fprintf(file, "%s ", argv[i]);

    fprintf(file, "\n");
    fclose(file);
}
log_history(argc, argv);
