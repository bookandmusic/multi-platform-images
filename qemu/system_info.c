#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <string.h>

// Function to read a specific field from a file
void read_os_release_field(const char *filename, const char *field, char *result, size_t size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, field, strlen(field)) == 0) {
            // Extract the value part
            char *value = strchr(line, '=');
            if (value) {
                value++; // Skip '='
                value[strcspn(value, "\n")] = 0; // Remove newline
                // Remove quotes if present
                if (value[0] == '"') {
                    value++;
                    value[strlen(value) - 1] = '\0';
                }
                strncpy(result, value, size - 1);
                result[size - 1] = '\0'; // Ensure null-terminated string
                break;
            }
        }
    }

    fclose(file);
}

int main() {
    struct utsname sys_info;
    
    if (uname(&sys_info) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    char os_name[256] = "Unknown";
    char os_version[256] = "Unknown";

    // Read OS name and version from /etc/os-release
    read_os_release_field("/etc/os-release", "NAME", os_name, sizeof(os_name));
    read_os_release_field("/etc/os-release", "VERSION", os_version, sizeof(os_version));

    printf("Hostname: %s\n", sys_info.nodename);
    printf("OS: %s\n", sys_info.sysname);
    printf("Platform: %s\n", os_name);
    printf("PlatformVersion: %s\n", os_version);
    printf("KernelVersion: %s\n", sys_info.release);
    printf("Machine: %s\n", sys_info.machine);

    return 0;
}
