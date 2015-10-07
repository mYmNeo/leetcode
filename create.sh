#!/usr/bin/env bash

echo "$1"|tr -d ' '|xargs -I{} touch {}.cc
