/*
** EPITECH PROJECT, 2024
** name
** File description:
** includes
*/

#ifndef PARSER_HPP_

    #define PARSER_HPP_
    #include "IComponent.hpp"
    #include "ComponentFactory.hpp"
    #include <string>
    #include <vector>
    #include <sstream>
  
namespace nts {
  class Parser {
    private:
      std::vector<std::string> data;
      ComponentFactory *factory;
      std::vector<std::unique_ptr<nts::IComponent>> comps;
    public:
      Parser(const std::string &file);
      ~Parser();
      bool check_filename(const std::string &file);
      void open_file(const std::string &file);
      void check_syntax_line(std::stringstream &_line);
      void find_parts(std::stringstream &_line, int &i, int &y, int x);
      void parse();
      void check_component(std::stringstream &_line, std::string type);
      void parse_chipsets(int start, int end);
      void make_link(std::vector<std::string> fst_arr, std::vector<std::string> snd_arr);
      void check_link(std::stringstream &_line, std::string type);
      void parse_links(int start, int end);
      std::vector<std::unique_ptr<nts::IComponent>> GetComps();
      void checkSameName();
  };
}

std::vector<std::string> string_to_vector(std::string str, char delim);

#endif
