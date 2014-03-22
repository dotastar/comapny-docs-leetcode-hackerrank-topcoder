#!/bin/bash

TARGET="$1"

for d in */ ; do
  if [ -f "${d}Makefile" ] ; then
    if ! make -C "$d" $TARGET ; then
      exit 1
    fi
  fi
done
