 #include <iostream>
 #include <cstring>

int main (int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if (argc == 1)
    {
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            argv[i][j] = std::toupper(argv[i][j]);
            std::cout << argv[i][j];
            j++;
        }
        std::cout << " ";
        i++;
    }
    std::cout << std::endl;
}