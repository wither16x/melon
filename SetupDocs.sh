#!/bin/bash

# Since I don't know how to make Doyxgen generate the HTML code in docs/ instead of
# docs/html/ (prolly a skill issue), I wrote this script to move the HTML code form
# docs/html/ to docs/.

mv -v docs/html/* docs/