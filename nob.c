#define NOB_IMPLEMENTATION
// make nob.h act as a c file, not a header
#include "./nob.h"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    // make a cmd that will build the project
    nob_cmd_append(&cmd, "cc");
    nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb");
    nob_cmd_append(&cmd, "-I./raylib/");
    nob_cmd_append(&cmd, "-o", "binc");
    nob_cmd_append(&cmd, "main.c");
    nob_cmd_append(&cmd, "-L./raylib/");
    nob_cmd_append(&cmd, "-lraylib", "-lm");
    if (!nob_cmd_run_sync(cmd)) return 1;
    return 0;
}
