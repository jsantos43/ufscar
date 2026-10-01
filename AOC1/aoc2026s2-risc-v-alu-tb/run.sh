#!/bin/sh
set -eu

cd "$(dirname "$0")"
exec ./tests/run.sh "$@"
