#!/bin/bash

n=2
# n個目の引数から最後まで
echo "${@:${n}}"

# n個目の引数から3つ
echo "${@:${n}:3}"
