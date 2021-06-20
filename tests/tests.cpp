#include "tests.hpp"

void ft::print_header(const std::string& name, std::ostream& out)
{
    size_t size = 21;
    size_t fill_length = name.length() >= size ? 0 : size - name.length();
    size_t fill_first = fill_length / 2;
    size_t fill_second = name.length() >= size ? 0 : size - (name.length() + fill_first);

    out << "#########################" << std::endl;
    out << "# ";
    out.width(static_cast<std::streamsize>(fill_first));
    out << "";
    out << name.substr(0, size);
    out.width(static_cast<std::streamsize>(fill_second));
    out << "";
    out << " #" << std::endl;
    out << "#########################" << std::endl;
}
