#include <getopt.h>
#include <iostream>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {

////     Retrieve the (non-option) argument:
//    if ( (argc <= 1) || (argv[argc-1] == NULL) || (argv[argc-1][0] == '-') ) {  // there is NO input...
//        cerr << "No argument provided!" << endl;
//        //return 1;
//    }
//    else {  // there is an input...
//        input = argv[argc-1];
//    }

    const char* short_options = "hl::v::";

    const struct option long_options[] = {
            {"help",no_argument,nullptr,'h'},
            {"list",optional_argument,nullptr,'l'},
            {"version",optional_argument,nullptr,'v'},
            {nullptr,0,nullptr,0}
    };

    set<int> arguments;

    int rez;
    int option_index;

// Shut GetOpt error messages down (return '?'):
//    opterr = 0;

    while ((rez=getopt_long(argc,argv,short_options,
                            long_options,&option_index)) !=- 1) {

        if (!arguments.count(rez)) {
            arguments.insert(rez);

            switch (rez) {
                case 'h': {
                    printf("help\n");
                    break;
                }
                case 'l': {
                    if (optarg != nullptr)
                        printf("list = %s\n", optarg);
                    else
                        printf("list\n");
                    break;
                }
                case 'v': {
                    if (optarg != nullptr)
                        printf("version = %s\n", optarg);
                    else
                        printf("version\n");
                    break;
                }
//                case '?': default: {
//                    printf("found unknown option\n");
//                    break;
//                }
            }
        }
    }

    return 0;
}