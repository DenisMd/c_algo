#!/usr/bin/env bash
set -euo pipefail

if [[ ! -x ./a.out ]]; then
    echo "a.out not found or not executable in $(pwd)" >&2
    exit 1
fi

shopt -s nullglob
txt_files=(./*.txt)

if [[ ${#txt_files[@]} -eq 0 ]]; then
    echo "No .txt files found in $(pwd)" >&2
    exit 1
fi

for f in "${txt_files[@]}"; do
    echo "=== $f ==="
    ./a.out < "$f"
    echo
done
