#include <iostream>
#include <string.h>
#include "Links/links.hpp"



int main(int argc, char* argv[]){
    Links links(argv[1]);
    std::cout << "Opened " << argv[1] << std::endl;
    
    const char *exit = "exit";
    const char *newlink = "nl";
    const char *numtolink = "ntl";
    const char *getlink = "gl";
    const char *linkcount = "lc";
    const char *mem = "mem";
    const char *hlp = "help";


    while(1) {
        char* answer;
        std::cin >> answer;
        if(strncmp(newlink, answer, sizeof(newlink)) == 0) {
            link_t Source = 0, Target = 0;
            std::cin >> Source >> Target;
            Link* link = links.Create(Source, Target);
            std::cout << "Link Created: (" << Source << "," << Target << ") Index: " << links.GetIndexByLink(link) << std::endl;
        }
        else if(strncmp(hlp, answer, sizeof(hlp)) == 0) {
            printf("\t\t    nl (Source index) (Target Index)\n\
                    Creates new link.\n\
                    gl (Link Index)\n\
                    Prints Link Source, Target\n\
                    lc\n\
                    Prints Link Count\n\
                    mem\n\
                    Prints Mapped Memory used/size\n");
        }
        else if(strncmp(mem, answer, sizeof(mem)) == 0) {
            std::cout << "Memory used: " << links.GetMemoryMapSize() << "/" << links.GetMemoryUse() << std::endl;
        }
        else if(strncmp(getlink, answer, sizeof(getlink)) == 0) {
            link_t index;
            std::cin >> index;
            Link *link = links.GetLinkByIndex(index);
            std::cout << index << ": " << link->Source << " " << link->Target << std::endl;
        }
        else if(strncmp(linkcount, answer, sizeof(linkcount)) == 0) {
            std::cout << "Link count: " << links.GetLinkCount() << std::endl;
        }
        else if(strncmp(numtolink, answer, sizeof(numtolink)) == 0) {
            int num;
            std::cin >> num;
            Link* link = links.NumberToLink(num);
            std::cout << "Link index: " << links.GetIndexByLink(link) << std::endl;
        }
        else if(strncmp(exit, answer, sizeof(exit)) == 0) {
            break;
        }
    }

    links.Close();
    return 0;
}
