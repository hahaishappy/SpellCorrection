#include "DictProducer.h"

int main()
{
    DictProducer dict("holy.txt");
    dict.bulid_dict();
    dict.store_dict("dict.txt");

    return 0;
}

