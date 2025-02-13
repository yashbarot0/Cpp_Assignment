#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>   // for EXIT_FAILURE
#include <cstddef>  // for std::size_t

/**
 * @brief Reads n elements of type double from a given filename into array v.
 *
 * @param filename Name of the file to open.
 * @param v An array of doubles where values will be stored.
 * @param n Number of elements expected.
 */
void read_array_from_file(const std::string& filename, double v[], std::size_t n)
{
    std::ifstream fin{filename};
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << filename << "\n";
        std::exit(EXIT_FAILURE); // or handle error more gracefully
    }

    for (std::size_t i = 0; i < n; ++i) {
        if (!(fin >> v[i])) {
            std::cerr << "Error: file " << filename 
                      << " did not have enough double values.\n";
            std::exit(EXIT_FAILURE);
        }
    }

    fin.close();
}

/**
 * @brief Reads n elements of type int from a given filename into array v.
 *
 * @param filename Name of the file to open.
 * @param v An array of ints where values will be stored.
 * @param n Number of elements expected.
 */
void read_array_from_file(const std::string& filename, int v[], std::size_t n)
{
    std::ifstream fin{filename};
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << filename << "\n";
        std::exit(EXIT_FAILURE);
    }

    for (std::size_t i = 0; i < n; ++i) {
        if (!(fin >> v[i])) {
            std::cerr << "Error: file " << filename 
                      << " did not have enough int values.\n";
            std::exit(EXIT_FAILURE);
        }
    }

    fin.close();
}

/**
 * @brief Prints n elements of a double array to the screen in a pretty format.
 *
 * @param v The double array to print (read-only).
 * @param n Number of elements to print.
 */
void pretty_print_vec(const double v[], std::size_t n)
{
    std::cout << "{ ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << v[i];
        if (i + 1 < n) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

/**
 * @brief Prints n elements of an int array to the screen in a pretty format.
 *
 * @param v The int array to print (read-only).
 * @param n Number of elements to print.
 */
void pretty_print_vec(const int v[], std::size_t n)
{
    std::cout << "{ ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << v[i];
        if (i + 1 < n) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

int main()
{
    // We plan to read 10 elements from each file
    // The code snippet in reorganise.cc uses this line:
    std::size_t constexpr nelem{10};

    // Declare arrays
    double x[nelem];
    int y[nelem];

    // Read data from files
    read_array_from_file("x.txt", x, nelem);
    read_array_from_file("y.txt", y, nelem);

    // Print arrays
    std::cout << "Double array (from x.txt): ";
    pretty_print_vec(x, nelem);

    std::cout << "Int array (from y.txt):    ";
    pretty_print_vec(y, nelem);

    // If you do further computations, do them here or in separate functions
    // For example, we could compute the sum of the int array, etc.

    return 0;
}
