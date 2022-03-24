#!/bin/bash

tr ':;,?!\"' ' ' < $1 | tr -s ' ' '\n' | sort | uniq -ic | sort -nr | head
# $1 komentoriviargumentille, jolla passataa luettava asia
#tr jotta saa yksittäiset sanat
#uniq -c uniikkien sanojen laskuun
#head 10 ekan näyttämiseen