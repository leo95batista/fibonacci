#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <string>

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long limit;

    try {
        limit = std::stoll(argv[1]);
    } catch (const std::invalid_argument &) {
        fprintf(stderr, "error: the limit is not a valid number\n");
        return EXIT_FAILURE;
    } catch (const std::out_of_range &) {
        fprintf(stderr, "error: the limit is out of range\n");
        return EXIT_FAILURE;
    }

    if (limit < 0) {
        fprintf(stderr, "error: the limit must be equal or greater to 0\n");
        return EXIT_FAILURE;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;

    while (a <= static_cast<unsigned long long>(limit)) {
        const unsigned long long c = a + b;

        fprintf(stdout, "%llu\n", a);

        if (c < b) {
            break;
        }

        a = b;
        b = c;
    }

    return EXIT_SUCCESS;
}
