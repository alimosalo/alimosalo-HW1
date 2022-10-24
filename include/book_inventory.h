struct Book
{
    std::string title;
    std::string author;
    float cost ;
    std::string isbn;
    std::string language_code ;
    int num_pages;
    std::string publisher ;
    int count ;
};
using Books=std::vector<Book>;
Books read_database(std::string file_path);