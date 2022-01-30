#!/bin/bash

# Exit on first failure. Prevents testing of old builds.
set -e

./scripts/build.sh
cd build/test
./TaskManTest